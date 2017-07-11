// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank     = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (PlayerTank && ControlledTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		UTankAimingComponent* TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

		if ( !ensure(TankAimingComponent) )
			return;

		TankAimingComponent->AimAt(PlayerTank->GetActorLocation());

		// Riabilitare, prima o poi.
//		ControlledTank->Fire();
	}
}
