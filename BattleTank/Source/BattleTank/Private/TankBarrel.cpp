// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTank.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	/// Apply the rotation difference to both turret and barrel (framerate independent and given a specificed elevation speed)
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate called at speed %f"), DegreesPerSecond);
	return;
}