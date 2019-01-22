// Fill out your copyright notice in the Description page of Project Settings.



#include "TankPlayerController.h"
#include "BattleTank.h"
#include "Tank.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}
