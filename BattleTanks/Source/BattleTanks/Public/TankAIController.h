#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

protected:
	UFUNCTION()
	void OnTankDeath();

	// Quanto il carro può avvicinarsi al giocatore. (In centimetri?)
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000.0;
};
