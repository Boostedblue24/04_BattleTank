// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"



ATank * ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = (GetWorld()->GetFirstPlayerController()-> GetPawn());
	if (!PlayerTank){return nullptr;}
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AITank = GetAITank();
	auto PlayerTank = GetPlayerTank();

	if(!AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Not Possessing Any Tanks!"));
		
	}
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller %s found player: %s"), *(AITank->GetName()), *(PlayerTank->GetName()));
	}
}

