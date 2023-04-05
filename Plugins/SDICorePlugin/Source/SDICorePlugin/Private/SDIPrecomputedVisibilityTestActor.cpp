#include "SDIPrecomputedVisibilityTestActor.h"
#include "Components/CapsuleComponent.h"

ASDIPrecomputedVisibilityTestActor::ASDIPrecomputedVisibilityTestActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnablePrecomputedVisibility = false;
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
}

