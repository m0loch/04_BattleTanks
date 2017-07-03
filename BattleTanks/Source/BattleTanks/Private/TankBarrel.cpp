#include "BattleTanks.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float NewElevation = FMath::ClampAngle(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(NewElevation, 0.0, 0.0));
}
