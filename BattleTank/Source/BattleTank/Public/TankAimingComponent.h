// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading
};


//Forward declaration
class UTankBarrel;
class UTankTurret;

//Holds barrel's property and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	/// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

	/// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float LaunchSpeed = 6000.0f;
	
	UTankTurret * Turret = nullptr;
	UTankBarrel * Barrel = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);
		
};
