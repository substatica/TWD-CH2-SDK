#include "SDIInteractiveRopeComponent.h"

USDIInteractiveRopeComponent::USDIInteractiveRopeComponent() {
    this->bEnableGripTautConstraints = false;
    this->CosmeticGripExtension = 6.00f;
    this->bEnableGripTautInterpolation = true;
    this->GripTautStartDistance = 20.00f;
    this->GripTautStiffnessConstant = 50.00f;
    this->GripTautDampeningRatio = 1.00f;
    this->bGripTautOverrideLocationPID = false;
    this->bGripTautOverrideRotationPID = false;
    this->bReactionInterfaceLocked = false;
    this->bCreatedNonEnforcedTautConstraints = false;
}

