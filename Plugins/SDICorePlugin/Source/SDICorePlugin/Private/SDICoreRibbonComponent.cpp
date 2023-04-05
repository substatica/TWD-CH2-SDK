#include "SDICoreRibbonComponent.h"

bool USDICoreRibbonComponent::IsIdle() const {
    return false;
}

USDICoreRibbonComponent::USDICoreRibbonComponent() {
    this->bIsAnimatedSpline = false;
    this->bAlwaysGenerateMesh = false;
    this->MinimumMovementDistance = 0.10f;
    this->ExtensionTime = 0.10f;
    this->RetractionTime = 0.50f;
    this->MaxMotionHistory = 30;
    this->MaxMotionAge = 0.25f;
    this->MotionAxis = ESDIAxis::Any;
    this->bVelocityInMotionAxisOnly = true;
    this->Material = NULL;
    this->LODSettings.AddDefaulted(1);
}

