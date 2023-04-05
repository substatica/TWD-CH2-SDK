#include "SDIMeleeWeaponActor.h"
#include "AkComponent.h"

class AActor;
class USDIActiveRagdollComponent;
class USDIMeleeWeaponHitCapsuleComponent;
class UPrimitiveComponent;

void ASDIMeleeWeaponActor::StabActiveRagdollDeactivated(AActor* Actor, USDIActiveRagdollComponent* Comp) {
}

void ASDIMeleeWeaponActor::StabActiveRagdollActivated(AActor* Actor, USDIActiveRagdollComponent* Comp) {
}

void ASDIMeleeWeaponActor::OnWeaponActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void ASDIMeleeWeaponActor::OnAppliedDamage_Implementation(USDIMeleeWeaponHitCapsuleComponent* Capsule, const FSDIDamageData& DamageData, const TArray<AActor*>& DamagedActors, const FHitResult& HitInfo, const FVector& ImpactVelocity, int32 DamageID) {
}

bool ASDIMeleeWeaponActor::IsStuckOrStabbed(FHitResult& OutHitInfo) const {
    return false;
}

float ASDIMeleeWeaponActor::GetStabLoopFeedbackHapticEffectScale(float& OutCurveTime) const {
    return 0.0f;
}

bool ASDIMeleeWeaponActor::EmbedWeaponAt(const FHitResult& HitInfo, const FTransform& WeaponTransform, bool bMustExtract) {
    return false;
}

bool ASDIMeleeWeaponActor::EmbedWeapon(UPrimitiveComponent* DesiredPrimComp, bool bMustExtract) {
    return false;
}

bool ASDIMeleeWeaponActor::CanMeleeHitCapsuleComponentApplyDamage_Implementation(const USDIMeleeWeaponHitCapsuleComponent* HitComponent) const {
    return false;
}

ASDIMeleeWeaponActor::ASDIMeleeWeaponActor() {
    this->AkAudioComponent = CreateDefaultSubobject<UAkComponent>(TEXT("AkAudioComponent"));
    this->bStabSyncMoveTarget = false;
    this->bStabSyncMoveAttacker = true;
    this->StabSyncMoveCharacterDistance = 15.00f;
    this->StabSyncMoveCharacterSpeed = 200.00f;
    this->StabSyncMoveCharacterMaxDuration = 1.00f;
    this->bStartEmbedded = false;
    this->bExtractWhenEmbedded = false;
    this->bIsShield = false;
    this->bShieldStrappedToArm = false;
    this->StabState = ESDIMeleeWeaponStabState::None;
    this->InitialStabDepth = 0.00f;
    this->StabDepth = 0.00f;
    this->CachedStabCurve = NULL;
    this->CachedStabPullCurve = NULL;
    this->StabInterpolationTime = 0.00f;
    this->StabExtractionDelay = 0.00f;
    this->StabExtractionTime = -1.00f;
    this->StabCapsuleOffset = 0.00f;
    this->StabSyncMoveCharacterTimer = 0.00f;
    this->bIsEmbedded = false;
    this->bEmbeddedExtract = false;
    this->bStabToggledAR = false;
    this->bStabContacted = false;
    this->StabSawIncrement = 0;
}

