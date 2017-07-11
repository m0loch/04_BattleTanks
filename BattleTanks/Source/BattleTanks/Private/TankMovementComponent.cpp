// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::InitMovementComponent(UTankTrack* pLeftTrack, UTankTrack* pRightTrack)
{
	LeftTrack = pLeftTrack;
	RightTrack = pRightTrack;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if ( !ensure(LeftTrack && RightTrack) )
	{
		UE_LOG(LogTemp, Warning, TEXT("Tracks not properly set."));
		return;
	}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if ( !ensure(LeftTrack && RightTrack) )
	{
		UE_LOG(LogTemp, Warning, TEXT("Tracks not properly set."));
		return;
	}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector &MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);   // Potrei mettere un bel commento intelligente qui
	float RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z; // ma ti rimando a wikipedia + lezioni 162 e 163.

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);
}
