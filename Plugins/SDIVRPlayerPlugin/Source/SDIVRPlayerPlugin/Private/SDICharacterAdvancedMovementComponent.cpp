#include "SDICharacterAdvancedMovementComponent.h"
#include "Net/UnrealNetwork.h"

class UObject;
class ASDIInteractiveMovableActor;
class UPrimitiveComponent;

void USDICharacterAdvancedMovementComponent::UpdateMovementHandCorrectionValues(float DeltaTime) {
}

void USDICharacterAdvancedMovementComponent::TickPostPhysics(UObject* TickOwner, float DeltaTime) {
}

void USDICharacterAdvancedMovementComponent::ServerMoveSDI_Implementation(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, const FSavedMove_SDICharacterAdvanced_MoveData& ServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode) {
}
bool USDICharacterAdvancedMovementComponent::ServerMoveSDI_Validate(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, const FSavedMove_SDICharacterAdvanced_MoveData& ServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode) {
    return true;
}

void USDICharacterAdvancedMovementComponent::ServerMoveOldSDI_Implementation(float OldTimeStamp, FVector_NetQuantize10 OldAccel, uint8 OldMoveFlags, const FSavedMove_SDICharacterAdvanced_MoveData& OldServerMoveData) {
}
bool USDICharacterAdvancedMovementComponent::ServerMoveOldSDI_Validate(float OldTimeStamp, FVector_NetQuantize10 OldAccel, uint8 OldMoveFlags, const FSavedMove_SDICharacterAdvanced_MoveData& OldServerMoveData) {
    return true;
}

void USDICharacterAdvancedMovementComponent::ServerMoveDualSDI_Implementation(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, const FSavedMove_SDICharacterAdvanced_MoveData& PendingServerMoveData, uint32 View0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 NewFlags, const FSavedMove_SDICharacterAdvanced_MoveData& NewServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode) {
}
bool USDICharacterAdvancedMovementComponent::ServerMoveDualSDI_Validate(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, const FSavedMove_SDICharacterAdvanced_MoveData& PendingServerMoveData, uint32 View0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 NewFlags, const FSavedMove_SDICharacterAdvanced_MoveData& NewServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode) {
    return true;
}

void USDICharacterAdvancedMovementComponent::ServerMoveDualHybridRootMotionSDI_Implementation(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, const FSavedMove_SDICharacterAdvanced_MoveData& PendingServerMoveData, uint32 View0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 NewFlags, const FSavedMove_SDICharacterAdvanced_MoveData& NewServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode) {
}
bool USDICharacterAdvancedMovementComponent::ServerMoveDualHybridRootMotionSDI_Validate(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, const FSavedMove_SDICharacterAdvanced_MoveData& PendingServerMoveData, uint32 View0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 NewFlags, const FSavedMove_SDICharacterAdvanced_MoveData& NewServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode) {
    return true;
}

bool USDICharacterAdvancedMovementComponent::IsTeleporting() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsRopeWalking() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsRopeMovement() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsRopeClimbing() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsMovingActor(ASDIInteractiveMovableActor*& OutActor) const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsMantlingUp() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsMantlingOver() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsMantling() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsGrabbingAndPulling() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsCrawling() const {
    return false;
}

bool USDICharacterAdvancedMovementComponent::IsClimbing() const {
    return false;
}

void USDICharacterAdvancedMovementComponent::GetMovementGripState(ESDIMovementHandGripState& OutLeftHand, ESDIMovementHandGripState& OutRightHand) const {
}

void USDICharacterAdvancedMovementComponent::ClientVeryShortAdjustPositionSDI_Implementation(float Timestamp, FVector NewLoc, UPrimitiveComponent* NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI) {
}

void USDICharacterAdvancedMovementComponent::ClientAdjustRootMotionSourcePositionSDI_Implementation(float Timestamp, FRootMotionSourceGroup ServerRootMotion, bool bHasAnimRootMotion, float ServerMontageTrackPosition, FVector ServerLoc, FVector_NetQuantizeNormal ServerRotation, float ServerVelZ, UPrimitiveComponent* ServerBase, FName ServerBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI) {
}

void USDICharacterAdvancedMovementComponent::ClientAdjustRootMotionPositionSDI_Implementation(float Timestamp, float ServerMontageTrackPosition, FVector ServerLoc, FVector_NetQuantizeNormal ServerRotation, float ServerVelZ, UPrimitiveComponent* ServerBase, FName ServerBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI) {
}

void USDICharacterAdvancedMovementComponent::ClientAdjustPositionSDI_Implementation(float Timestamp, FVector NewLoc, FVector NewVel, UPrimitiveComponent* NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI) {
}

bool USDICharacterAdvancedMovementComponent::CheckForMantle(float VerticalTestDistance, FHitResult& OutMantleTargetInfo, bool& bMantleOver, bool& bMantleRequireCrouch, bool bCheckMantleUp, bool bCheckMantleOver, FVector MotionDirection) const {
    return false;
}

void USDICharacterAdvancedMovementComponent::CancelTeleport() {
}

bool USDICharacterAdvancedMovementComponent::CancelClimbNonVR() {
    return false;
}

bool USDICharacterAdvancedMovementComponent::AttemptTeleport(const FTransform& DesiredTransform, const FHitResult& HitResult) {
    return false;
}

void USDICharacterAdvancedMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USDICharacterAdvancedMovementComponent, MoveData);
}

USDICharacterAdvancedMovementComponent::USDICharacterAdvancedMovementComponent() {
    this->bLastClimbingFacingValid = false;
    this->bLastClimbingFacingWasHint = false;
    this->ClimbingRightHandInterpolation = 0.00f;
    this->ClimbingLeftHandInterpolation = 0.00f;
    this->bWantsToCrawl = false;
    this->bForceCrawl = false;
    this->bCrawlMaintainsBaseLocation = true;
    this->bDesiredTeleportTransformValid = false;
    this->bTeleportCrouching = false;
    this->bTeleporting = false;
    this->bTeleportingCancelled = false;
    this->bRopeMovementLimitingDisabled = false;
    this->bUpdatingBaseMovement = false;
    this->bSwimMovementLimitedToSurface = false;
    this->bSwimMovementTouchingGround = false;
    this->bSwimMovementTouchingCeiling = false;
    this->SwimMovementCameraTransition = 0;
    this->SwimStickMovementAKTimestamp = 0.00f;
    this->bCameraWasUnderWater = false;
    this->bModifiedCapsuleHeight = false;
    this->FallingHMDHapticFeedbackLoopId = 0;
    this->bStartMovingOnGround = false;
    this->MaxWalkSpeedCrawl = 50.00f;
    this->CrawlHalfHeight = 15.00f;
    this->bCanWalkOffLedgesWhenCrawling = false;
    this->bCanCrawl = true;
    this->bCanClimb = true;
    this->bCanGrabAndPull = true;
    this->bCanUseRope = true;
    this->RopeMovementSpringStiffness = 100.00f;
    this->RopeMovementSpringDamp = 0.75f;
    this->SurfaceGripMaxPhysicsLinearVel = 5.00f;
    this->SurfaceGripMaxPhysicsAngularVelDeg = 5.00f;
    this->HandAverageVelocityTime = 0.10f;
    this->GrabAndPullSpringStiffness = 100.00f;
    this->GrabAndPullSpringDamp = 0.75f;
    this->ClimbingHalfHeight = 0.00f;
    this->ClimbingSpringStiffness = 100.00f;
    this->ClimbingSpringDamp = 0.75f;
    this->ClimbingYawSpringStiffness = 30.00f;
    this->ClimbingYawSpringDamp = 1.00f;
    this->bClimbingUseFixedFacing = true;
    this->bClimbingFaceGripWithoutHint = true;
    this->ClimbingScanDistance = 30.00f;
    this->ClimbingGripInterpolationTime = 0.00f;
    this->bCanMantleOver = true;
    this->bCanMantleUp = true;
    this->bMantleVerticalTestAllowHMD = true;
    this->ClimbingMantleVerticalTestDistance = 32.00f;
    this->ClimbingMantleMaxDistanceToFloor = 256.00f;
    this->ClimbingMantleCheckStep = 16.00f;
    this->ClimbingAutoMantleVerticalTestDistance = -32.00f;
    this->ClimbingMantleCheckSideStep = 12.00f;
    this->ClimbingMantleCheckSideStepCapsuleRadiusMultiplier = 2.00f;
    this->WalkingMantleVerticalTestDistance = 32.00f;
    this->WalkingMantleMaxDistanceToFloor = 256.00f;
    this->WalkingMantleCheckStep = 16.00f;
    this->WalkingAutoMantleVerticalTestDistance = -32.00f;
    this->WalkingMantleCheckSideStep = 12.00f;
    this->WalkingMantleCheckSideStepCapsuleRadiusMultiplier = 2.00f;
    this->NonVRMantleVerticalTestDistance = 128.00f;
    this->NonVRMantleMaxDistanceToFloor = 256.00f;
    this->NonVRMantleCheckStep = 16.00f;
    this->NonVRMantleCheckSideStep = 12.00f;
    this->NonVRMantleCheckSideStepCapsuleRadiusMultiplier = 2.00f;
    this->NonVRMantleMinAnalogInput = 0.25f;
    this->NonVRMantleInputAngleDeg = 90.00f;
    this->RopeClimbingHalfHeight = 0.00f;
    this->SinglePivotRopeDampingCurve = NULL;
    this->SinglePivotRopeDamping = 2.00f;
    this->DualPivotRopeDamping = 3.00f;
    this->RopeDampingApproachingPivotFactor = 0.35f;
    this->RopeDampingLeavingPivotFactor = 1.00f;
    this->NonMovementRopeArmLengthScale = 0.90f;
    this->bNonMovementRopeAvoidShoulderDislocation = true;
    this->NonMovementRopeMaxShoulderDislocationDistance = 4.00f;
    this->NonMovementRopeShoulderDislocationCorrectionSpeed = 2048.00f;
    this->MinZDeltaForRopeClimbing = 1.00f;
    this->SwimmingHalfHeight = 0.00f;
    this->BrakingDecelerationSwimmingImmersedZ = 1536.00f;
    this->SwimmingHMDPitchRemapCurve = NULL;
    this->SwimmingHandGrippedMotionVelocityMul = 1.00f;
    this->SwimmingHandOpenMotionVelocityMul = 0.00f;
    this->SwimmingSingleHandMotionVelocityBoost = 0.25f;
    this->SwimmingHandMotionMinVelocity = 10.00f;
    this->MaxSprintSwimSpeed = 300.00f;
    this->MaxHandMotionSwimSpeed = 450.00f;
    this->SwimmingDesiredHeightAboveSurface = 40.00f;
    this->SwimmingDesiredHeightBelowSurface = 8.00f;
    this->SwimmingCameraWaterPlaneRadius = 8.00f;
    this->SwimmingCameraAboveSurfaceMovementAngleDeg = 10.00f;
    this->SwimmingCameraBelowSurfaceMovementAngleDeg = 0.00f;
    this->SwimStartAKEvent = NULL;
    this->SwimStartZVelocityRTPC = TEXT("Dive_Velocity");
    this->SwimEndAKEvent = NULL;
    this->SwimSufraceAKEvent = NULL;
    this->SwimSubmergeAKEvent = NULL;
    this->SwimHandMovementAKEvent = NULL;
    this->SwimStickMovementAKEvent = NULL;
    this->SwimStickMovementAKMinAnalogInput = 0.25f;
    this->FallingHMDHapticFeedbackLoop = NULL;
    this->FallingHMDHapticFeedbackVelocityScaleCurve = NULL;
}

