#include "SDIHandMeshComponent.h"

USDIHandMeshComponent::USDIHandMeshComponent() {
    this->bUsePhysics = false;
    this->RotationProportionalGainCurve = NULL;
    this->RotationDerivativeGainCurve = NULL;
    this->SingleHandedRotationGainCurveMinMass = 0.00f;
    this->TwoHandedRotationGainCurveMinMass = 1.00f;
    this->TwoHandedGrabScalar = 2.00f;
    this->TwoHandedGrabRotationScalar = 1.00f;
    this->MinLimitedForceScale = 0.10f;
    this->DesiredRelativeCompTransform_ElapsedTickTime = 0.00f;
}

