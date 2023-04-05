#include "TWDDismemberDroppedLimb.h"
#include "Components/SkeletalMeshComponent.h"

bool ATWDDismemberDroppedLimb::ShowGoreBlood() const {
    return false;
}

void ATWDDismemberDroppedLimb::SelfDestructionCheck() {
}

void ATWDDismemberDroppedLimb::MeshOnPhysicsStateChange() {
}

bool ATWDDismemberDroppedLimb::CanBeDestroyed(bool bCheckStabStuckWeapons) const {
    return false;
}

ATWDDismemberDroppedLimb::ATWDDismemberDroppedLimb(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    this->bAllowDestructionInHub = true;
    this->DestructionMinDistanceFromPlayer = 1024.00f;
    this->DestructionMinTimeSinceLastRendered = 3.00f;
    this->AnimInstanceClass = NULL;
    this->SplashColorTexture = NULL;
    this->SplashNormalTexture = NULL;
    this->MeatColorTexture = NULL;
    this->MeatNormalTexture = NULL;
    this->NoGoreSplashColorTexture = NULL;
    this->NoGoreMeatColorTexture = NULL;
    this->WoundSeverityScale = 1.00f;
    this->bDisableDamageWounds = false;
    this->StabLoopParticleSystem = NULL;
    this->StabMovementParticleSystem = NULL;
    this->StabMeleeDurabilityModifier = 1.00f;
}

