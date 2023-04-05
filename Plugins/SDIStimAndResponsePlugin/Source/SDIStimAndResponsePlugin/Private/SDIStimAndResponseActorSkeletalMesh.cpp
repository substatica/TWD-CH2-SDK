#include "SDIStimAndResponseActorSkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"

ASDIStimAndResponseActorSkeletalMesh::ASDIStimAndResponseActorSkeletalMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
}

