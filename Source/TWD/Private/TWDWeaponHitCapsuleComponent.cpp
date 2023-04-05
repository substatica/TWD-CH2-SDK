#include "TWDWeaponHitCapsuleComponent.h"

void UTWDWeaponHitCapsuleComponent::SetStickingAllowed(bool bCanDismember) {
}

void UTWDWeaponHitCapsuleComponent::SetStabbingAllowed(bool bCanStab) {
}

void UTWDWeaponHitCapsuleComponent::SetDismemberAllowed(bool bCanDismember) {
}

bool UTWDWeaponHitCapsuleComponent::IsStickingAllowed() const {
    return false;
}

bool UTWDWeaponHitCapsuleComponent::IsStabbingAllowed() const {
    return false;
}

bool UTWDWeaponHitCapsuleComponent::IsDismemberAllowed() const {
    return false;
}

UTWDWeaponHitCapsuleComponent::UTWDWeaponHitCapsuleComponent() {
    this->bAllowStab = false;
    this->StabAxis = ESDIAxis::PosZ;
    this->ThrownStabAxis = ESDIAxis::PosZ;
    this->LaunchedStabAxis = ESDIAxis::PosZ;
    this->StabWoundAxis = ESDIAxis::PosX;
    this->StabCollisionCorrectionStep = 4.00f;
    this->StabStartDepth = 4.00f;
    this->StabMaxDepth = 16.00f;
    this->bStabMaintainMinStartDepth = false;
    this->StabExtractionDepth = 0.00f;
    this->bStabInitialDepthVelocityRemovePawnVelocity = true;
    this->StabStartLerpTime = 0.12f;
    this->StabThrownStartLerpTime = 0.12f;
    this->StabLaunchedStartLerpTime = 0.12f;
    this->bStabCanPush = true;
    this->bUseStabPushTriggerDepth = false;
    this->StabPushTriggerDepth = 4.00f;
    this->bStabCanDrag = false;
    this->bStabFromThrown = false;
    this->bStabFromLaunched = false;
    this->bStabUsePullOutMove = true;
    this->bStabStickAfterRelease = true;
    this->bStabBrainingUseRagdoll = true;
    this->bStabRefineHitInfo = false;
    this->StabSawIncrements = 5;
    this->bDismemberUsePullOutMove = false;
    this->bAllowDismember = false;
    this->DismemberAxis = ESDIAxis::PosX;
    this->bUseDismemberLateralAxis = false;
    this->DismemberLateralAxis = ESDIAxis::PosZ;
    this->DismemberFlatAxis = ESDIAxis::PosNegY;
    this->bAllowStick = false;
    this->StickAxis = ESDIAxis::PosZ;
    this->ThrownStickAxis = ESDIAxis::PosZ;
    this->LaunchedStickAxis = ESDIAxis::PosZ;
    this->WoundAxis = ESDIAxis::PosZ;
    this->bCapsuleAndWeaponMustAgreeOnShouldHandleHits = false;
}

