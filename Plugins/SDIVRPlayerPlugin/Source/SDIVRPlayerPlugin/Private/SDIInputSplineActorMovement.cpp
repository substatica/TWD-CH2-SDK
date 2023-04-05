#include "SDIInputSplineActorMovement.h"

ASDIInputSplineActorMovement::ASDIInputSplineActorMovement(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VisibleMovementTargetRadius = 2048.00f;
    this->bOnlyToMovementTargets = false;
    this->bInputFacingOnlyWithMovementTargets = false;
}

