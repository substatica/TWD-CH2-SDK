#include "SDIStimAndResponseActorStaticMesh.h"
#include "Components/StaticMeshComponent.h"

ASDIStimAndResponseActorStaticMesh::ASDIStimAndResponseActorStaticMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
}

