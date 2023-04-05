#include "TWDMovementInputSplineActor.h"

ATWDMovementInputSplineActor::ATWDMovementInputSplineActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VisibleMovementTargetRadius = 2048.00f;
    this->bOnlyToMovementTargets = false;
    this->bInputFacingOnlyWithMovementTargets = false;
}

