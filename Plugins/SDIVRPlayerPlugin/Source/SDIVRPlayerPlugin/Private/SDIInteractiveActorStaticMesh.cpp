#include "SDIInteractiveActorStaticMesh.h"
#include "Components/StaticMeshComponent.h"

ASDIInteractiveActorStaticMesh::ASDIInteractiveActorStaticMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
}

