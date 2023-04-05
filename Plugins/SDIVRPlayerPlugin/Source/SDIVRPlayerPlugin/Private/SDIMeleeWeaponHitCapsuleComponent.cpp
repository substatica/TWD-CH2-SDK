#include "SDIMeleeWeaponHitCapsuleComponent.h"

class ASDIHeldActor;
class USDIMeleeWeaponHitCapsuleComponent;
class USceneComponent;
class UObject;
class AActor;
class ASDIPlayerHand;
class UPrimitiveComponent;
class AController;
class APawn;

void USDIMeleeWeaponHitCapsuleComponent::UpdateAttachmentInfo(USceneComponent* OldParent, USceneComponent* NewParent, const FName& NewParentSocketName) {
}

void USDIMeleeWeaponHitCapsuleComponent::TickOverlaps(UObject* ObjectOwner, float DeltaTime) {
}

void USDIMeleeWeaponHitCapsuleComponent::ResetMotionHistory(bool bReserveAbs, bool bReserveRel) {
}

bool USDIMeleeWeaponHitCapsuleComponent::PredictMotionCurves(FInterpCurveVector& OutBottom, FInterpCurveVector& OutTop, FVector& OutPlanePivot, FVector& OutPlaneExtensionLocation, FVector& OutPlaneNormal, FVector& OutPlaneTangent, float Time, float Resolution, float History) const {
    return false;
}

bool USDIMeleeWeaponHitCapsuleComponent::PredictMotion(TArray<FTransform>& OutTransforms, FVector& OutPlanePivot, FVector& OutPlaneNormal, float Time, float Resolution, float History) const {
    return false;
}

void USDIMeleeWeaponHitCapsuleComponent::OnWeaponActorGrabbed(ASDIHeldActor* HeldActor, AActor* GrabbedBy, EControllerHand hand, ASDIPlayerHand* HandPtr) {
}

void USDIMeleeWeaponHitCapsuleComponent::OnWeaponActorDropped(ASDIHeldActor* HeldActor, AActor* DroppedBy) {
}

void USDIMeleeWeaponHitCapsuleComponent::OnProjectileMovementStop(const FHitResult& ImpactResult) {
}

void USDIMeleeWeaponHitCapsuleComponent::OnPhysicsComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName) {
}

void USDIMeleeWeaponHitCapsuleComponent::OnPhysicsComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName) {
}

bool USDIMeleeWeaponHitCapsuleComponent::MeleeWeaponCouldCauseDamageToHitResult(AActor* Weapon, USDIMeleeWeaponHitCapsuleComponent*& OutComp, const FHitResult& HitResult, bool bCheckVelocity, bool bCheckHistory, bool bCheckValidDamageValues) {
    return false;
}

bool USDIMeleeWeaponHitCapsuleComponent::MeleeWeaponCouldCauseDamage(AActor* Weapon, USDIMeleeWeaponHitCapsuleComponent*& OutComp, AActor* Target, bool bCheckVelocity, bool bCheckHistory, bool bCheckValidDamageValues) {
    return false;
}

bool USDIMeleeWeaponHitCapsuleComponent::IsTwoHanded() const {
    return false;
}

FTransform USDIMeleeWeaponHitCapsuleComponent::GetWeaponHitCapsuleTransform() const {
    return FTransform{};
}

USDIMeleeWeaponHitCapsuleComponent* USDIMeleeWeaponHitCapsuleComponent::GetWeaponHit(AActor* Actor, const FHitResult& HitInfo, bool bUseFindBestFallback, bool bOnlyCanDamage) {
    return NULL;
}

bool USDIMeleeWeaponHitCapsuleComponent::GetInstigatorInfo(AController*& OutController, APawn*& OutPawn) const {
    return false;
}

USDIMeleeWeaponHitCapsuleComponent* USDIMeleeWeaponHitCapsuleComponent::FindBestExternalWeaponHit(AActor* Actor, const FHitResult& HitInfo, bool bOnlyCanDamage, bool bCheckVelocity, bool bCheckValidDamageValues) {
    return NULL;
}

void USDIMeleeWeaponHitCapsuleComponent::DrawDebugMotionPrediction(float Time, float Resolution, float History, float LifeTime) const {
}

void USDIMeleeWeaponHitCapsuleComponent::DrawDebugMotionHistory(float Timespan, FLinearColor Color, int32 Subdivisions, bool bRotation, bool bPersistent, float LifeTime, float Thickness) const {
}

bool USDIMeleeWeaponHitCapsuleComponent::CouldCauseDamage(bool bCheckVelocity, bool bCheckValidDamageValues) const {
    return false;
}

float USDIMeleeWeaponHitCapsuleComponent::ComputeVelocityDamagePercent(bool bUseRelativeHistory) const {
    return 0.0f;
}

FVector USDIMeleeWeaponHitCapsuleComponent::ComputeImpactVelocity(const FHitResult& ImpactResult, float& OutScalarVel, bool bUseRelativeHistory) const {
    return FVector{};
}

FVector USDIMeleeWeaponHitCapsuleComponent::ComputeAvgTopVelocity(float AvgTime, float& ScalarVel, bool bUseRelativeHistory) const {
    return FVector{};
}

FVector USDIMeleeWeaponHitCapsuleComponent::ComputeAvgBottomVelocity(float AvgTime, float& ScalarVel, bool bUseRelativeHistory) const {
    return FVector{};
}

bool USDIMeleeWeaponHitCapsuleComponent::CanApplyDamage() const {
    return false;
}

USDIMeleeWeaponHitCapsuleComponent::USDIMeleeWeaponHitCapsuleComponent() {
    this->DamageHistoryDuration = 0.50f;
    this->CollisionHistoryDuration = 0.50f;
    this->VelocityAvgTime = 0.15f;
    this->ImpactDamageVelocityAvgTime = 0.04f;
    this->DamageIndexVelocityAvgTime = 0.04f;
    this->bUseOverlapHitDetection = true;
    this->bUseActorForDamageHistory = true;
    this->bDamageOnlyWhenHeld = false;
    this->bCanDamageInstigator = false;
    this->bAlwaysTickWhenActive = false;
    this->bDetachFromHierarchy = true;
    this->HitReactImpulseMultiplier = 1.00f;
    this->HitReactMinSpeed = 100.00f;
    this->bUsePlaneForOverlap = true;
    this->bPlaneCanUseOverlapScaleOverrides = false;
    this->PlaneNormalAxis = EAxis::Y;
    this->PlaneHalfHeight = 1.00f;
    this->bUsedForDefense = false;
    this->CheckForBlockSubdivisions = 3;
    this->LastTickTimeStamp = -1.00f;
}

