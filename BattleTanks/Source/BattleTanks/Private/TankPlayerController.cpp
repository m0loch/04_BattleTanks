// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"

UTankAimingComponent* ATankPlayerController::GetAimingComponent()
{
	auto ControlledTank = GetPawn();
	if ( !ControlledTank )
		return nullptr;

	return ControlledTank->FindComponentByClass<UTankAimingComponent>();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UTankAimingComponent* AimingComponent = GetAimingComponent();

	if ( ensure(AimingComponent) )
		FoundAimingComponent(AimingComponent);
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	UTankAimingComponent* AimingComponent = GetAimingComponent();
	if ( !AimingComponent)
		return;

	FVector HitLocation;
	if ( GetSightRayHitLocation(HitLocation) )
	{
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	// Find the crosshair position.
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// De-project the screen position of the crosshair to a a world direction.
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Do a LineTrace using maximum range.
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(const FVector2D &ScreenLocation, FVector &LookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	HitLocation = FVector(0.0);

	FHitResult Hit;

	// Gets player location.
	FVector PlayerLocation = PlayerCameraManager->GetCameraLocation();

	// Calculates the end of the LineTrace.
	FVector LineEnd = PlayerLocation + (LineTraceRange * LookDirection);

	if ( GetWorld()->LineTraceSingleByChannel(Hit, PlayerLocation, LineEnd, ECC_Visibility) )
	{
		HitLocation = Hit.Location;
		return true;
	}

	return false;
}
