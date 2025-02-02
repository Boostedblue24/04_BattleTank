// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "GameFramework/DamageType.h"
#include "Delegates/Delegate.h"
#include "Tank.generated.h" /// Put new includes above

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	/// Called by the engine when Actor Damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DmaageEvent, class AController* EventInstigator, AActor * DamageCauser) override;
	
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;
	
	FTankDelegate OnDeath;


private:

	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;


protected:
	
};
