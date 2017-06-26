// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // MUST be the last include...

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	double CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	double CrossHairYLocation = 0.333333;

	UPROPERTY(EditAnywhere)
		double LineTraceRange = 1000000.0;

private:
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	// Punta il cannone verso il mirino.
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &HitLocation) const;

	bool GetLookDirection(const FVector2D &ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
};
