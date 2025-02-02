// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class URadialForceComponent;


UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UProjectileMovementComponent * ProjectileMovement = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent * CollisionMesh = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent * LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent * ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent * ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
	float DestroyDelay = 10.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage = 20.0f;

public:	

	void LaunchProjectile(float Speed);

	

private:
	AProjectile();

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit);
	void OnTimerExpire();
};