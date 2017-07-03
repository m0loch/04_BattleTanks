// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsPlayer();
}

ATank* ATankAIController::GetControlledTank() const
{
	return (ATank*)GetPawn();
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto pWorld = GetWorld();
	if (!pWorld) return nullptr;

	auto pPC = pWorld->GetFirstPlayerController();;
	if (!pPC) return nullptr;

	return (ATank*)pPC->GetPawn();
}

void ATankAIController::AimTowardsPlayer()
{
	ATank* pPlayerTank = GetPlayerTank();
	if ( !pPlayerTank || !GetControlledTank() )
		return;

	FVector HitLocation;
	GetControlledTank()->AimAt(pPlayerTank->GetActorLocation());
}
