// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	/// No need to call Super as we're replacing functionality
	
	/// Getting current tank forward vector
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	/// Getting the pathfinding-generated intended forward vector
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	/// Creating a correct forward throw for the dot product of previous two vectors
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	/// Passing dot product for forward throw
	IntendMoveForward(ForwardThrow);

	/// Taking a cross product of pathfinding-generated intended forward vector and the current tank forward vector 
	/// to get a rotation vector
	auto RightVector = FVector::CrossProduct(TankForward, AIForwardIntention);
	/// Getting the Z component of the new turning vector for a throw float
	float RightThrow = RightVector.Z;
	/// Feeding the new throw float into the method that turns the tank right
	IntendTurnRight(RightThrow);
}
