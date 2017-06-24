// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto tank = GetControlledTank();
	if (tank)
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank %s"), *tank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("Nope"))

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return (ATank*)GetPawn();
}
