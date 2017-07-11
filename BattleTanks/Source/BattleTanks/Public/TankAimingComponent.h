// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EAimingStatus : uint8
{
	Reloading,
	Aiming,
	Locked,
};

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitAimingMovementComponent(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, double LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
	EAimingStatus AimingStatus = EAimingStatus::Reloading;

private:
	void MoveBarrelTowards(const FVector &AimDirection);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
};
