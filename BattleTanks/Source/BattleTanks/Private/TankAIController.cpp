// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto tank = GetControlledTank();
	if (tank)
		UE_LOG(LogTemp, Warning, TEXT("AI controls tank %s"), *tank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("AI controls nothing...."))

}

ATank* ATankAIController::GetControlledTank() const
{
	return (ATank*)GetPawn();
}
