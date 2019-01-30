// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {Super::BeginPlay();}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	auto AIControlledTank = GetPawn();
	
	if (!ensure(PlayerTank && AIControlledTank)) { return; }
	
		/// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		/// Aim towards player
		auto AimingComponent = AIControlledTank->FindComponentByClass<UTankAimingComponent>();

		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		/// Fire if ready
		AimingComponent->Fire(); 
	
	
}

