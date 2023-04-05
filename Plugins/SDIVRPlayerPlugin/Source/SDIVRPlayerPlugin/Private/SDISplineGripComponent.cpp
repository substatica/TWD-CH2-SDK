#include "SDISplineGripComponent.h"

USDISplineGripComponent::USDISplineGripComponent() {
    this->hand = EControllerHand::AnyHand;
    this->HandPose = ESDIHandPose::HP_Fist;
    this->GripType = ESDIGripType::Any;
    this->LocationGripMovement = ESDIGripMovement::Locked;
    this->RotationGripMovement = ESDIGripMovement::Locked;
    this->RotationGripMovementTarget = ESDIGripMovementTarget::Tracked;
    this->bAvoidHandOverlap = true;
    this->bHandOverlapAllowSideSwap = true;
    this->HandOverlapMinDistance = 10.00f;
    this->bUseTrackedHandForConstraintAdjustments = false;
    this->bApplyRotationConstraintsOnGrab = true;
    this->bApplyRotationConstraintsOnGrabTwist = true;
    this->bApplyRotationConstraintsOnGrabSwing1 = true;
    this->bApplyRotationConstraintsOnGrabSwing2 = true;
    this->bPreferredForGrabFromInventory = false;
    this->bPreferredForRangedGrab = false;
    this->bPreferredForNonVR = false;
    this->bMaintainAttachment = false;
    this->LinearDistanceUpdateThreshold = 1.00f;
    this->AngularDistanceUpdateThresholdDegrees = 5.00f;
    this->bOverrideSinglePhysicsHandLocationPID = false;
    this->SinglePhysicsHandLocationPIDScalar = 1.00f;
    this->bOverrideSinglePhysicsHandRotationPID = false;
    this->SinglePhysicsHandRotationPIDScalar = 1.00f;
    this->bOverrideDualPhysicsHandLocationPID = false;
    this->DualPhysicsHandLocationPIDScalar = 1.00f;
    this->bOverrideDualPhysicsHandRotationPID = false;
    this->DualPhysicsHandRotationPIDScalar = 1.00f;
    this->DesiredGripPercent = -1.00f;
    this->NonVRGripPercent = -1.00f;
}

