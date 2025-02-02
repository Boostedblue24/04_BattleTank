// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
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
		
		/// If aiming or locked, fire
		if (AimingComponent->GetFiringState() == EFiringState::Locked)
		{
			AimingComponent->Fire();
		}
	
	
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		/// Subscribe our local method to the Tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!ensure(GetPawn())) { return; }
	
	GetPawn()->DetachFromControllerPendingDestroy();
	
	UE_LOG(LogTemp, Warning, TEXT("AI Tank Died"));
}

