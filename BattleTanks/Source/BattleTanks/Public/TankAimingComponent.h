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

class AProjectile;
class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

public:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void InitAimingComponent(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	EAimingStatus GetAimingStatus() const
	{ return AimingStatus; }

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EAimingStatus AimingStatus = EAimingStatus::Reloading;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	double LaunchSpeed = 4000.0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	double ReloadTimeInSeconds = 3.0;

	// Gestione del cooldown.
	double LastFireTime = 0.0;

private:
	void MoveBarrelTowards(const FVector &AimDirection);

	bool IsBarrelMoving();

	// Uso interno.
	FVector AimDirection = FVector(0.0);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
};
