#include "SDIGameplayTagActorSkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"

ASDIGameplayTagActorSkeletalMesh::ASDIGameplayTagActorSkeletalMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
}

