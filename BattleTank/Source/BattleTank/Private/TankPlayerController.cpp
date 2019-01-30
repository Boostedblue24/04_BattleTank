// Fill out your copyright notice in the Description page of Project Settings.



#include "TankPlayerController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

class UTankAimingComponent;



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(AimingComponent)) { return; }
	
	FoundAimingComponent(AimingComponent);
	
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation; /// OUT Parameter

	if (GetSightRayHitLocation(HitLocation))
	{
		AimingComponent->AimAt(HitLocation);
	}
	
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	// Find crosshair position
	/// Calculate Viewport Size
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	/// Calculate crosshair position (ScreenLocation) by using Viewport size X/Y divided by crosshair position
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	

	// Deproject the screen position of the crosshair to a world direction	
	/// Variable for the vector that the camera is looking along
	FVector LookDirection;

	/// Deprojecting using crosshair location and Look vector 
	/// and logging out the Look direction vector if the Deproject method succeeds
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		/// Line trace along that look direction and see what we hit (up to a max range)
		return GetLookVectorHitLocation(LookDirection, HitLocation);
		
	}
	return false;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; /// To be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	///Setting up variables
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	/// Checking to see if line trace succeeds (within specified range)
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	
	HitLocation = FVector(0);
	return false;
}


