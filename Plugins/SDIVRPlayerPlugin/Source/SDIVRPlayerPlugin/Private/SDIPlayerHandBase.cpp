#include "SDIPlayerHandBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "SDIMotionControllerComponent.h"
#include "SDILatePhysicalAnimationComponent.h"
#include "SDICollisionChannelIgnoranceComponent.h"

class UObject;
class APawn;
class UObject;
class UAnimSequenceBase;
class USceneComponent;
class UActorComponent;
class APlayerController;

void ASDIPlayerHandBase::UpdateHandHidden_Implementation(bool bHandHidden) {
}

bool ASDIPlayerHandBase::UnlockShoulder(UObject* LockOwner) {
    return false;
}

bool ASDIPlayerHandBase::UnlockHandRotation(UObject* LockOwner, bool bInterpolate) {
    return false;
}

bool ASDIPlayerHandBase::UnlockHandLocation(UObject* LockOwner, bool bInterpolate) {
    return false;
}

void ASDIPlayerHandBase::UnlockHandClench() {
}

bool ASDIPlayerHandBase::UnlockHand(UObject* LockOwner, bool bInterpolate) {
    return false;
}

bool ASDIPlayerHandBase::StopHapticsByValue(UObject* EffectOwner) const {
    return false;
}

bool ASDIPlayerHandBase::StopHapticEffectId(int32 ID) const {
    return false;
}

bool ASDIPlayerHandBase::StopHapticEffect(UObject* HapticEffect, UObject* EffectOwner) const {
    return false;
}

void ASDIPlayerHandBase::StopHandShake(int32 ID) {
}

void ASDIPlayerHandBase::StopHandAnimation(float BlendOutTime) {
}

bool ASDIPlayerHandBase::StopAllHapticEffects(UObject* EffectOwner) const {
    return false;
}

void ASDIPlayerHandBase::SetTrackedHandMeshHidden(bool bNewHidden) {
}

bool ASDIPlayerHandBase::SetLockedHandPoseInfo(UObject* LockOwner, const FSDIHandPoseInfo& NewPoseInfo, float BlendSpeed) {
    return false;
}

bool ASDIPlayerHandBase::SetHapticsByValue(const float Frequency, const float Amplitude, UObject* EffectOwner) const {
    return false;
}

void ASDIPlayerHandBase::SetHandPoseInfo(FSDIHandPoseInfo NewPoseInfo, float BlendSpeed) {
}

void ASDIPlayerHandBase::SetHandPose(ESDIHandPose NewPose, float BlendSpeed) {
}

void ASDIPlayerHandBase::SetHandMeshHidden(bool bNewHidden) {
}

void ASDIPlayerHandBase::SetHandClench(float NewClench) {
}

void ASDIPlayerHandBase::SetDebugTrackedHandMeshFadeStartDistanceScale(float Scale) {
}

void ASDIPlayerHandBase::SetDebugTrackedHandMeshFadeInDistanceScale(float Scale) {
}

void ASDIPlayerHandBase::RecreatePhysicsConstraints() {
}

int32 ASDIPlayerHandBase::PlayHapticEffect(UObject* HapticEffect, float Scale, bool bLoop, int32 Priority, UObject* EffectOwner) const {
    return 0;
}

int32 ASDIPlayerHandBase::PlayHandShake(const FSDIPlayerHandShake& Shake, float Scale) {
    return 0;
}

bool ASDIPlayerHandBase::PlayHandAnimation(UAnimSequenceBase* Anim, FName SlotName, float BlendInTime, float BlendOutTime, float PlayRate) {
    return false;
}

void ASDIPlayerHandBase::OnPawnChanged_Implementation(APawn* OldPawn, APawn* NewPawn) {
}

bool ASDIPlayerHandBase::LockShoulder(UObject* LockOwner, float ArmLengthMultiplier, float AdditionalArmLength) {
    return false;
}

bool ASDIPlayerHandBase::LockHandToComponent(UObject* LockOwner, USceneComponent* Comp, FName SocketName, FRotator Extent, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand) {
    return false;
}

bool ASDIPlayerHandBase::LockHandRotationToComponent(UObject* LockOwner, USceneComponent* Comp, FName SocketName, FRotator Extent, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation) {
    return false;
}

bool ASDIPlayerHandBase::LockHandRotation(UObject* LockOwner, FRotator Rotation, FRotator Extent, USceneComponent* Parent, FName ParentSocketName, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation) {
    return false;
}

bool ASDIPlayerHandBase::LockHandLocationToComponent(UObject* LockOwner, USceneComponent* Comp, FName SocketName, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand) {
    return false;
}

void ASDIPlayerHandBase::LockHandClench(float NewClench) {
}

bool ASDIPlayerHandBase::K2LockHandLocation(UObject* LockOwner, FVector Extents, FTransform Transform, USceneComponent* Parent, FName ParentSocketName, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand) {
    return false;
}

bool ASDIPlayerHandBase::K2LockHand(UObject* LockOwner, FVector Extents, FTransform Transform, FRotator Extent, USceneComponent* Parent, FName ParentSocketName, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand) {
    return false;
}

bool ASDIPlayerHandBase::K2IsHandPoseLocked(FSDIHandPoseInfo& OutPose) const {
    return false;
}

bool ASDIPlayerHandBase::K2IsHandClenchLocked(float& OutLockedClench) const {
    return false;
}

float ASDIPlayerHandBase::K2ComputeHandMove(const FSDIPlayerHandMove& Move, FVector DesiredDirection, FVector& OutVector) const {
    return 0.0f;
}

bool ASDIPlayerHandBase::IsTrackedHandMeshHidden() const {
    return false;
}

bool ASDIPlayerHandBase::IsShoulderLockedBy(const UObject* Obj) const {
    return false;
}

bool ASDIPlayerHandBase::IsShoulderLocked() const {
    return false;
}

bool ASDIPlayerHandBase::IsPlayingHapticsByValue(UObject* EffectOwner) const {
    return false;
}

bool ASDIPlayerHandBase::IsPlayingHapticEffectId(int32 ID) const {
    return false;
}

bool ASDIPlayerHandBase::IsPlayingHapticEffect(UObject* HapticEffect, UObject* EffectOwner) const {
    return false;
}

bool ASDIPlayerHandBase::IsPlayingHandShake(int32 ID) const {
    return false;
}

bool ASDIPlayerHandBase::IsPlayingHandAnimation() const {
    return false;
}

bool ASDIPlayerHandBase::IsHandMeshHidden() const {
    return false;
}

bool ASDIPlayerHandBase::IsHandLockInterpolating() const {
    return false;
}

bool ASDIPlayerHandBase::IsHandLockExceedingArmLengthReleaseFactor(float& OutTime) const {
    return false;
}

bool ASDIPlayerHandBase::IsHandLockedBy(const UObject* Obj) const {
    return false;
}

bool ASDIPlayerHandBase::IsHandLocked() const {
    return false;
}

void ASDIPlayerHandBase::InitializeHand() {
}

bool ASDIPlayerHandBase::HasCosmeticHandMesh() const {
    return false;
}

void ASDIPlayerHandBase::HandWasTeleported_Implementation(const FTransform& OldTransform, const FTransform& NewTransform) {
}

FTransform ASDIPlayerHandBase::GetVisualHandMeshTransform() const {
    return FTransform{};
}

USkeletalMeshComponent* ASDIPlayerHandBase::GetVisualHandMesh() const {
    return NULL;
}

float ASDIPlayerHandBase::GetUpperArmLength() const {
    return 0.0f;
}

FTransform ASDIPlayerHandBase::GetTrackedHandMeshTransform() const {
    return FTransform{};
}

USkeletalMeshComponent* ASDIPlayerHandBase::GetTrackedHandMesh() const {
    return NULL;
}

float ASDIPlayerHandBase::GetTimeSinceLastHandTeleport() const {
    return 0.0f;
}

FTransform ASDIPlayerHandBase::GetShoulderTransform() const {
    return FTransform{};
}

FVector ASDIPlayerHandBase::GetShoulderOffset() const {
    return FVector{};
}

float ASDIPlayerHandBase::GetShoulderLockLimitedTime() const {
    return 0.0f;
}

APlayerController* ASDIPlayerHandBase::GetPlayerController() const {
    return NULL;
}

USkeletalMeshComponent* ASDIPlayerHandBase::GetPhysicalHandMesh() const {
    return NULL;
}

APawn* ASDIPlayerHandBase::GetPawn() const {
    return NULL;
}

USDIMotionControllerComponent* ASDIPlayerHandBase::GetMotionController() const {
    return NULL;
}

bool ASDIPlayerHandBase::GetIsIndicatingDirection() const {
    return false;
}

UObject* ASDIPlayerHandBase::GetHapticFeedbackEffect(int32 ID) const {
    return NULL;
}

FSDIHandPoseInfo ASDIPlayerHandBase::GetHandPoseInfo(bool& bOutForHighlight) const {
    return FSDIHandPoseInfo{};
}

ESDIHandPose ASDIPlayerHandBase::GetHandPose() const {
    return ESDIHandPose::HP_Fist;
}

FVector ASDIPlayerHandBase::GetHandOffsetDelta() const {
    return FVector{};
}

FTransform ASDIPlayerHandBase::GetHandMeshWristTransform() const {
    return FTransform{};
}

FTransform ASDIPlayerHandBase::GetHandMeshTransform() const {
    return FTransform{};
}

FTransform ASDIPlayerHandBase::GetHandMeshShoulderTransform() const {
    return FTransform{};
}

FTransform ASDIPlayerHandBase::GetHandMeshElbowTransform() const {
    return FTransform{};
}

UActorComponent* ASDIPlayerHandBase::GetHandLockGripComponent(FSDIGripInfo& OutGripInfo) const {
    return NULL;
}

float ASDIPlayerHandBase::GetForeArmLength() const {
    return 0.0f;
}

FTransform ASDIPlayerHandBase::GetDesiredHandMeshTransform(float DeltaSeconds) {
    return FTransform{};
}

EControllerHand ASDIPlayerHandBase::GetControllerHand() const {
    return EControllerHand::Left;
}

FTransform ASDIPlayerHandBase::GetCameraTransform() const {
    return FTransform{};
}

FVector ASDIPlayerHandBase::GetCameraRight2D() const {
    return FVector{};
}

FVector ASDIPlayerHandBase::GetCameraForward2D() const {
    return FVector{};
}

FRuntimeFloatCurve ASDIPlayerHandBase::GetArmMeshWidthMultiplierCurve() const {
    return FRuntimeFloatCurve{};
}

FVector ASDIPlayerHandBase::GetArmMeshScale() const {
    return FVector{};
}

float ASDIPlayerHandBase::GetArmMeshLengthMultiplier() const {
    return 0.0f;
}

float ASDIPlayerHandBase::GetArmLength() const {
    return 0.0f;
}

FVector ASDIPlayerHandBase::GetArmDebugOffset() const {
    return FVector{};
}

FVector ASDIPlayerHandBase::ComputeTheoreticalElbowLocation(const FVector& DesiredWristLocation) const {
    return FVector{};
}

bool ASDIPlayerHandBase::ClearLockedHandPoseInfo(UObject* LockOwner, float BlendSpeed) {
    return false;
}

void ASDIPlayerHandBase::ClearHandPoseInfo(float BlendSpeed) {
}

bool ASDIPlayerHandBase::AreCosmeticPhysicsFingersActive(float& OutAlpha) const {
    return false;
}

bool ASDIPlayerHandBase::AdjustHapticEffectScaleId(int32 ID, float Scale) const {
    return false;
}

bool ASDIPlayerHandBase::AdjustHapticEffectScale(UObject* HapticEffect, float Scale, UObject* EffectOwner) const {
    return false;
}

void ASDIPlayerHandBase::AdjustHandShakeScale(int32 ID, float Scale) {
}

ASDIPlayerHandBase::ASDIPlayerHandBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->MotionController = CreateDefaultSubobject<USDIMotionControllerComponent>(TEXT("MotionController"));
    this->HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandMesh"));
    this->HandMesh->AttachTo(GetRootComponent());
    this->TrackedHandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TrackedHandMesh"));
    this->TrackedHandMesh->AttachTo(GetRootComponent());
    this->CosmeticHandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CosmeticHandMesh"));
    this->CosmeticHandMesh->AttachTo(GetRootComponent());
    this->CosmeticHandMeshPhysicalAnimation = CreateDefaultSubobject<USDILatePhysicalAnimationComponent>(TEXT("CosmeticHandMeshPhysicalAnimation"));
    this->HandMeshCollisionIgnoranceComp = CreateDefaultSubobject<USDICollisionChannelIgnoranceComponent>(TEXT("HandMeshCollisionIgnorance"));
    this->VelocitySmoothingFactor = 10.00f;
    this->ShoulderHeadRotationDeltaPercent = 1.00f;
    this->ShoulderHeadRotationPitchThreshold = -10.00f;
    this->TrackedHandMeshFadeInStart = 12.00f;
    this->TrackedHandMeshFadeInDistance = 40.00f;
    this->TrackedHandMeshFadeInExp = 1.00f;
    this->TrackedHandMeshFadeInAlpha = 0.60f;
    this->DebugTrackedHandMeshFadeStartDistanceScale = 1.00f;
    this->DebugTrackedHandMeshFadeInDistanceScale = 1.00f;
    this->bEnableHandCollisionIgnoranceRestorationPullback = true;
    this->HandCollisionIgnoranceRestorationSpeed = 128.00f;
    this->bAllowTeleport = true;
    this->TeleportDistance = 16.00f;
    this->TeleportMinArmLengthMultiplier = 1.50f;
    this->MaxSimulatingPhysicsMassToPushAround = 0.00f;
    this->ArmMeshLengthMultiplier = 1.00f;
    this->CosmeticHandMeshReturnSpeed = 4.00f;
    this->bCosmeticPhysicsFingers = false;
    this->CosmeticPhysicsFingersBlendInTime = 0.10f;
    this->CosmeticPhysicsFingersBlendOutTime = 0.20f;
    this->bShouldCorrectPhysicsForCharacterMovement = true;
    this->ControllerHand = EControllerHand::AnyHand;
    this->bHandMeshHidden = false;
    this->bTrackedHandMeshHidden = false;
    this->bWristBoneValid = false;
    this->bElbowBoneValid = false;
    this->bShoulderBoneValid = false;
    this->BaseForeArmLength = 0.00f;
    this->BaseUpperArmLength = 0.00f;
    this->ForeArmLength = 0.00f;
    this->UpperArmLength = 0.00f;
    this->LastHandTeleportTimestamp = -1000.00f;
    this->ShoulderLockLimitedTime = 0.00f;
    this->bHandCollisionIgnoranceRestorationTargetCamera = false;
    this->CosmeticHandMeshReturnLerp = -1.00f;
    this->bCurrentHandPoseForHighlight = false;
    this->CosmeticPhysicsFingersAlpha = 0.00f;
}

