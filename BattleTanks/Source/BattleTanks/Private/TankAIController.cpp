// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto tank = GetPlayerTank();
	if (tank)
		UE_LOG(LogTemp, Warning, TEXT("I see player controlling tank %s"), *tank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("I don't know what player is doing...."))

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
