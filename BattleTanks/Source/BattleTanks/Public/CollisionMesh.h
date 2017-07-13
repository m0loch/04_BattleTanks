#pragma once

#include "Components/StaticMeshComponent.h"
#include "CollisionMesh.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UCollisionMesh : public UStaticMeshComponent
{
	GENERATED_BODY()
};
