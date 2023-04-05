#include "TWDWeaponStablizerComponent.h"

UTWDWeaponStablizerComponent::UTWDWeaponStablizerComponent() {
    this->StablizationAxis = ESDIAxis::PlaneXZ;
    this->ForwardAxis = ESDIAxis::Any;
    this->MinStablizationSpeed = 10.00f;
    this->MaxStablizationSpeed = 100.00f;
    this->TorqueScale = 1.00f;
    this->bEnableStablization = true;
}

