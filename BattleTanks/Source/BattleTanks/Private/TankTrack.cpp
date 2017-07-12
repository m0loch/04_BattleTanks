#include "BattleTanks.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewayForce();
	CurrentThrottle = 0.0;
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1.0, 1.0);
}

void UTankTrack::ApplySidewayForce()
{
	// Calcola la velocità di scivolamento laterale.
	float SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Calcola la correzione da applicare.
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	FVector CorrectAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Applica la correzione laterale simulando l'attrito del cingolo.
	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector CorrectionForce = TankRoot->GetMass() * CorrectAcceleration / 2; // Divisa equamente sui due cingoli!

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::DriveTrack()
{
	FVector ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
