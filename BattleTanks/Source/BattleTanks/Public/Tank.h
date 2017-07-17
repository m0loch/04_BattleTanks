// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankEvent);

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float Damage, const FDamageEvent &DamageEvent, AController *EventInstigator, AActor *DamageCauser) override;

	FTankEvent OnDeath;

	// FALSO: in realt� non torna una percentuale, ma un valore fra 0 e 1.
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100.0;

	// Solo visibile poich� non � che tutti devono star l� a smanacciarla.
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth = StartingHealth;
};
