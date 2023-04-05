#include "SDIInteractiveRopeActor.h"
#include "SDIInteractiveRopeComponent.h"

class APawn;

void ASDIInteractiveRopeActor::UpdateTickEnabled_Implementation() {
}

bool ASDIInteractiveRopeActor::ShouldTickBeEnabled_Implementation() const {
    return false;
}

void ASDIInteractiveRopeActor::SetCanBeUsedForMovement(bool bMovement) {
}

bool ASDIInteractiveRopeActor::IsStruggleActive(bool& bOutIsHeld, bool& bOutIsTaut, bool& bOutAllowIncrement, float& OutStruggleAmount) {
    return false;
}

bool ASDIInteractiveRopeActor::IsBeingHeld() const {
    return false;
}

bool ASDIInteractiveRopeActor::IsBeingClimbed() const {
    return false;
}

APawn* ASDIInteractiveRopeActor::GetHeldBy() const {
    return NULL;
}

void ASDIInteractiveRopeActor::Drop() {
}

bool ASDIInteractiveRopeActor::CanBeUsedForMovement() const {
    return false;
}

ASDIInteractiveRopeActor::ASDIInteractiveRopeActor() {
    this->RopeComponent = CreateDefaultSubobject<USDIInteractiveRopeComponent>(TEXT("RopeComponent"));
    this->bCanBeUsedForMovement = false;
    this->bAllowRangedGrab = true;
    this->MaxRangedGrabDistance = 96.00f;
    this->MaxRangedGrabDistanceWhenHeld = 32.00f;
    this->RangedGrabInterpolationSpeed = 512.00f;
    this->bSoftRangedGrabInterpolationConstraint = true;
    this->SoftRangedGrabInterpolationConstraintStiffness = 50.00f;
    this->SoftRangedGrabInterpolationConstraintDamping = 5.00f;
    this->GripAudioEvent = NULL;
    this->ReleaseAudioEvent = NULL;
}

