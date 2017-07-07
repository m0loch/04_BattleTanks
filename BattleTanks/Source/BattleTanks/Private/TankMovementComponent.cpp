// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Init(UTankTrack* pLeftTrack, UTankTrack* pRightTrack)
{
	LeftTrack = pLeftTrack;
	RightTrack = pRightTrack;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tracks not properly set."));
		return;
	}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tracks not properly set."));
		return;
	}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
