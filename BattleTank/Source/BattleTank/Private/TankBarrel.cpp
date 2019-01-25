// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTank.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	/// Apply the rotation difference to both turret and barrel (framerate independent and given a specificed elevation speed)
	
	auto Time = GetWorld()->GetTimeSeconds();
	///UE_LOG(LogTemp, Warning, TEXT("%f: Barrel Elevate called at speed %f"), Time, RelativeSpeed);
	return;
}