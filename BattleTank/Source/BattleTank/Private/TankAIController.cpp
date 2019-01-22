// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"

ATank * ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto AITank = GetAITank();

	if(!AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Not Possessing Any Tanks!"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Possessing %s"), *(AITank->GetName()));
	}
}

