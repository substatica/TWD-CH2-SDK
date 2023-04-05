#include "SDIActiveRagdollComponent.h"

class UPrimitiveComponent;
class AActor;
class USDIActiveRagdollComponent;

void USDIActiveRagdollComponent::UpdatePhysicsAsset() {
}

void USDIActiveRagdollComponent::UnlockBone(int32& InOutId) {
}

bool USDIActiveRagdollComponent::TurnOn(float Duration) {
    return false;
}

void USDIActiveRagdollComponent::TurnOff(bool bAllowBlendOut) {
}

void USDIActiveRagdollComponent::ToggleOn() {
}

void USDIActiveRagdollComponent::ToggleOff(bool bAllowBlendOut) {
}

void USDIActiveRagdollComponent::SetBoneActiveOverride(FName BoneName, bool bEnabled) {
}

bool USDIActiveRagdollComponent::RemovePhysicalAnimationDataProfile(int32 ID) {
    return false;
}

bool USDIActiveRagdollComponent::RemoveConstraintProfile(int32 ID) {
    return false;
}

int32 USDIActiveRagdollComponent::OverridePhysicalAnimationDataProfile(FName Profile) {
    return 0;
}

int32 USDIActiveRagdollComponent::OverrideConstraintProfile(FName Profile) {
    return 0;
}

void USDIActiveRagdollComponent::OnStitchedComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void USDIActiveRagdollComponent::OnHeldActorComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void USDIActiveRagdollComponent::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void USDIActiveRagdollComponent::MeshOnPhysicsStateChange() {
}

int32 USDIActiveRagdollComponent::LockHands(FName RelativeBone, bool bRotation, bool bLocation) {
    return 0;
}

int32 USDIActiveRagdollComponent::LockBone(FName Bone, FName RelativeBone, bool bRotation, bool bLocation) {
    return 0;
}

bool USDIActiveRagdollComponent::K2IsOn(float& OutActiveTimeRemaining) const {
    return false;
}

bool USDIActiveRagdollComponent::IsValidBone(const FName& BoneName) const {
    return false;
}

bool USDIActiveRagdollComponent::IsToggledOn() const {
    return false;
}

bool USDIActiveRagdollComponent::IsForcedOn() const {
    return false;
}

bool USDIActiveRagdollComponent::IsBoneLocked(FName Bone) const {
    return false;
}

bool USDIActiveRagdollComponent::IsActiveBone(const FName& BoneName) const {
    return false;
}

float USDIActiveRagdollComponent::GetDefaultStrengthMultiplyer() const {
    return 0.0f;
}

USDIActiveRagdollComponent* USDIActiveRagdollComponent::GetActiveRagdollComponentFor(AActor* Actor) {
    return NULL;
}

void USDIActiveRagdollComponent::ClearBoneActiveOverrides(const TArray<FName>& BoneNames) {
}

void USDIActiveRagdollComponent::ClearBoneActiveOverride(FName BoneName) {
}

bool USDIActiveRagdollComponent::ActiveRagdollAllowed() const {
    return false;
}

USDIActiveRagdollComponent::USDIActiveRagdollComponent() {
    this->bEnableGravity = false;
    this->BlendInSpeed = 2.00f;
    this->BlendOutSpeed = 2.00f;
    this->bEngageOnCollision = true;
    this->CollisionActiveDuration = 1.00f;
    this->bHackRecreatePhysicsStateOnCollision = true;
    this->DefaultStrengthMultiplyer = -1.00f;
    this->ActiveTimer = 0.00f;
    this->ToggledOnCount = 0;
    this->bNotifyToggledOn = false;
    this->bBlendWeightInterpolating = false;
    this->bRagdollActive = false;
    this->bInsideOnComponentHit = false;
    this->bInsideOnStitchedComponentHit = false;
    this->bInsideOnHeldActorComponentHit = false;
    this->bInsideOnAccessoryComponentHit = false;
}

