#include "SDIInteractiveActorSkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"

ASDIInteractiveActorSkeletalMesh::ASDIInteractiveActorSkeletalMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
}

