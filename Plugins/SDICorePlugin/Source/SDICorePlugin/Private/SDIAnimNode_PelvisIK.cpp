#include "SDIAnimNode_PelvisIK.h"

FSDIAnimNode_PelvisIK::FSDIAnimNode_PelvisIK() {
    this->EffectorLocationSpace = RTS_World;
    this->StretchAmount = 0.00f;
    this->PelvisMotionRangeSphericalWeight = 0.00f;
    this->bPelvisIsValidToEvaluate = false;
    this->bLeftLegIsValidToEvaluate = false;
    this->bRightLegIsValidToEvaluate = false;
}

