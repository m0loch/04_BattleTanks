// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent),
	hidecategories=("Collision"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DegreesPerSecond);

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20.0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0.0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40.0;
};