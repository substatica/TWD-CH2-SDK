#include "SDIGameplayTagActorStaticMesh.h"
#include "Components/StaticMeshComponent.h"

ASDIGameplayTagActorStaticMesh::ASDIGameplayTagActorStaticMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
}

