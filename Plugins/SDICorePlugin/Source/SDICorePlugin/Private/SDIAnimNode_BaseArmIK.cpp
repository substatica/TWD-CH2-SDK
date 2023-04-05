#include "SDIAnimNode_BaseArmIK.h"

FSDIAnimNode_BaseArmIK::FSDIAnimNode_BaseArmIK() {
    this->bShoulderIsBase = false;
    this->bForeArmTwistBonesAreChained = false;
    this->ForeArmTwistSwapThreshold = 0.00f;
    this->bUpperArmTwistBonesAreChained = false;
    this->MaxExtensionPct = 0.00f;
    this->ComfortableElbowRotation = 0.00f;
    this->CalcElbowParallelBlendStart = 0.00f;
    this->CalcElbowParallelBlendExp = 0.00f;
    this->SideMultiplier = 0.00f;
    this->bInputsValid = false;
    this->ElbowRotationSpringTarget = 0.00f;
    this->LastForeArmTwistDelta = 0.00f;
    this->bIsValidToEvaluate = false;
}

