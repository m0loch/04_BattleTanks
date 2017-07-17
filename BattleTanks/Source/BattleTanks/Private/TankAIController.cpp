#include "BattleTanks.h"
#include "Tank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isDead)
		return;

	auto PlayerTank     = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (PlayerTank && ControlledTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		UTankAimingComponent* TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

		if ( !ensure(TankAimingComponent) )
			return;

		TankAimingComponent->AimAt(PlayerTank->GetActorLocation());

		if ( TankAimingComponent->GetAimingStatus() == EAimingStatus::Locked )
			TankAimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if ( !InPawn )
		return;

	auto PossessedTank = Cast<ATank>(InPawn);

	if ( !ensure(PossessedTank) ) return;

	PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
}

void ATankAIController::OnTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("AI Tank is dead."));
	isDead = true;
}
