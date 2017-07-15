// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float Damage, const FDamageEvent &DamageEvent, AController *EventInstigator, AActor *DamageCauser)
{
	int32 DamagePoints = FMath::RoundToInt(Damage);
	DamagePoints = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamagePoints;
	if ( CurrentHealth <= 0 )
	{
		UE_LOG(LogTemp, Warning, TEXT("TANK DIED"));
	}

	return DamagePoints;
}
