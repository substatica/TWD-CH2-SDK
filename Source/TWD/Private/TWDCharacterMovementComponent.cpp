#include "TWDCharacterMovementComponent.h"

class UCurveBase;
class UPhysicalMaterial;
class AActor;
class UObject;

bool UTWDCharacterMovementComponent::UpdateAttackMoveTargetOffset(float Offset) {
    return false;
}

bool UTWDCharacterMovementComponent::IsExecutingAttackMove(FVector& OutMoveLocation, AActor*& OutMoveTarget, FName& OutMoveTargetSocket, bool& bOutFaceTargetYaw, bool& bOutFaceTargetPitch) const {
    return false;
}

bool UTWDCharacterMovementComponent::IsDodging(FVector& OutDirection, float& OutDuration, float& OutTimeRemaining, float& OutDamageReduction) const {
    return false;
}

float UTWDCharacterMovementComponent::GetPerceptionNoiseLevel() const {
    return 0.0f;
}

FRotator UTWDCharacterMovementComponent::GetOffsetFacingFromMovement() const {
    return FRotator{};
}

float UTWDCharacterMovementComponent::GetNoiseLevel(TEnumAsByte<EMovementMode> NoiseMovementMode, uint8 NoiseCustomMode) const {
    return 0.0f;
}

float UTWDCharacterMovementComponent::GetMaxTeleportSpeedCrouched() const {
    return 0.0f;
}

float UTWDCharacterMovementComponent::GetMaxTeleportSpeed() const {
    return 0.0f;
}

float UTWDCharacterMovementComponent::GetMaxNoiseLevel(bool bForceRefresh) const {
    return 0.0f;
}

UObject* UTWDCharacterMovementComponent::GetFootstepSound(UPhysicalMaterial* PhysMat, UObject* CurrentSound) const {
    return NULL;
}

bool UTWDCharacterMovementComponent::ExecuteTargetDodge(const FHitResult& Target, UCurveBase* InDodgeCurve, bool bCanInterrupt, bool bFaceTargetYaw, float MaxYawVelDeg) {
    return false;
}

bool UTWDCharacterMovementComponent::ExecuteDodge(const FVector& Direction, UCurveBase* InDodgeCurve, bool bCanInterrupt, bool bFaceDirectionYaw, float MaxYawVelDeg) {
    return false;
}

bool UTWDCharacterMovementComponent::ExecuteAttackMoveLocation(const FVector& TargetLocation, float Time, float MaxSpeed, float Offset, bool bFaceTargetYaw, bool bFaceTargetPitch, FRotator MaxRotVel, float HoldTime, bool bCancelVelocityOnExit) {
    return false;
}

bool UTWDCharacterMovementComponent::ExecuteAttackMoveActor(AActor* MoveTarget, FName MoveTargetSocket, float Time, float MaxSpeed, float Offset, bool bFaceTargetYaw, bool bFaceTargetPitch, FRotator MaxRotVel, float HoldTime, bool bCancelVelocityOnExit, bool bPredictTargetVelocity, bool bOffsetIgnoreCollisions) {
    return false;
}

bool UTWDCharacterMovementComponent::ExecuteAttackMove(const FVector& TargetLocation, AActor* Target, FName TargetSocket, float Time, float MaxSpeed, float Offset, bool bFaceTargetYaw, bool bFaceTargetPitch, FRotator MaxRotVel, float HoldTime, bool bCancelVelocityOnExit, bool bPredictTargetVelocity, bool bOffsetIgnoreCollisions) {
    return false;
}

void UTWDCharacterMovementComponent::CancelDodge(bool bCancelVelocity) {
}

void UTWDCharacterMovementComponent::CancelAttackMove(bool bCancelVelocity) {
}

UTWDCharacterMovementComponent::UTWDCharacterMovementComponent() {
    this->NoiseVelocity = 0.00f;
    this->NoiseDistance = 0.00f;
    this->NoiseTime = 0.00f;
    this->MaxNoiseLevel = 0.00f;
    this->ClimbingGruntTimer = 0.00f;
    this->AttackMoveTargetOffset = 0.00f;
    this->AttackMoveTargetMaxSpeed = 0.00f;
    this->AttackMoveTargetDuration = 0.00f;
    this->bAttackMoveTargetFaceTargetYaw = false;
    this->bAttackMoveTargetFaceTargetPitch = false;
    this->AttackMoveTargetHoldTime = 0.00f;
    this->bAttackMoveCancelVelocityOnExit = true;
    this->bAttackMovePredictTargetVelocity = false;
    this->bAttackMoveTargetOffsetIgnoreCollisions = false;
    this->HandLockPhysicsForceSpringTarget = 0.00f;
    this->bCrouchedInsideLowSpace = false;
    this->DodgeDuration = 0.00f;
    this->CachedDodgeTimeMultiplier = 1.00f;
    this->CachedDodgeDistanceMultiplier = 1.00f;
    this->DodgeCurve = NULL;
    this->DodgeTimestamp = 0.00f;
    this->bDodgeDeceleration = false;
    this->bDodgeFaceYaw = false;
    this->DodgeMaxYawVelDeg = 0.00f;
    this->bTeleportCameraLerpInsteadOfFade = false;
    this->TeleportCameraFadeOutTime = 0.10f;
    this->TeleportCameraFadeInTime = 0.20f;
    this->TeleportCameraLerpTime = 0.10f;
    this->MaxTeleportSpeed = 600.00f;
    this->MaxTeleportSpeedCrouched = 400.00f;
    this->MaxTeleportSpeedCrawl = 200.00f;
    this->MaxWalkSpeedDrag = 75.00f;
    this->MaxWalkSpeedWinded = 150.00f;
    this->MaxWalkSpeedWindedCrouched = 100.00f;
    this->MaxWalkSpeedWindedCrawl = 50.00f;
    this->bAllowGrippingClimbableSurfacesWhileWinded = false;
    this->ClimbingGruntSound = NULL;
    this->ClimbingMantleSound = NULL;
    this->WalkingNoiseCurve = NULL;
    this->CrouchedNoiseCurve = NULL;
    this->CrawlNoiseCurve = NULL;
    this->TeleportWalkingNoiseCurve = NULL;
    this->TeleportCrouchedNoiseCurve = NULL;
    this->TeleportCrawlNoiseCurve = NULL;
    this->GrabAndPullNoiseCurve = NULL;
    this->GrabAndPullCrouchNoiseCurve = NULL;
    this->GrabAndPullCrawlNoiseCurve = NULL;
    this->NoiseDistanceThreshold = 128.00f;
    this->NoiseTimeThreshold = 1.00f;
    this->NoiseVelocityInterpolationFactor = 2.00f;
    this->bHandLocksLimitMovement = true;
    this->HandLockMinDistance2D = 16.00f;
    this->HandLockArmLengthMultiplier = 1.25f;
    this->HandLockPhysicsForceMinAnalogInput = 0.10f;
    this->HandLockPhysicsForceCurve = NULL;
    this->HandLockPhysicsForceOneHandMultiplier = 1.00f;
    this->HandLockPhysicsForceTwoHandMultiplier = 0.50f;
    this->CrouchedInsideLowSpaceRadiusMultiplier = 0.50f;
    this->bCanDodge = false;
    this->DefaultDodgeCurve = NULL;
    this->DodgeCooldown = 0.50f;
    this->DodgeStaminaCost = 10.00f;
    this->DodgeTimeMultiplier = 1.00f;
    this->DodgeDistanceMultiplier = 1.00f;
    this->DodgeBrakingDeceleration = 2048.00f;
}

