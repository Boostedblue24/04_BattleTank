// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {Super::BeginPlay();}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	auto AIControlledTank = Cast<ATank>(GetPawn());
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found no Player Tanks!"));
	}
	if (PlayerTank)
	{
		/// TODO Move towards player

		/// Aim towards player
		AIControlledTank->AimAt(PlayerTank->GetActorLocation());
		/// Fire if ready
		//AIControlledTank->Fire(); /// TODO Don't fire every frame
	}
	
}

