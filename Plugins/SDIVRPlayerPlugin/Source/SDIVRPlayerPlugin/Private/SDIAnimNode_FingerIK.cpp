#include "SDIAnimNode_FingerIK.h"

FSDIAnimNode_FingerIK::FSDIAnimNode_FingerIK() {
    this->Alpha = 0.00f;
    this->MinGameplayPlatformLevel = 0;
    this->bIgnoreTimeDilation = false;
    this->bApplyToTrackedHandMesh = false;
    this->bUseCollisionCache = false;
    this->CollisionCacheRadius = 0.00f;
    this->bDebugDrawFingers = false;
    this->bTestRotationFixed = false;
    this->bTestRotationLive = false;
    this->TestRotationFixedAmount = 0.00f;
    this->TestRotationLiveSpeed = 0.00f;
    this->TestRotationLiveHoldTime = 0.00f;
    this->ActualAlpha = 0.00f;
    this->SideMultiplier = 0.00f;
    this->ActorCustomTimeDilation = 0.00f;
    this->RootIndex = 0;
    this->bInputsValid = false;
    this->CollisionChannel = ECC_WorldStatic;
    this->bIsSurfaceGripHandPose = false;
    this->bWasSurfaceGripHandPose = false;
    this->TestRotationLiveDir = 0.00f;
    this->TestRotationLiveAmount = 0.00f;
    this->bHandRootBoneIsValidToEvaluate = false;
}

