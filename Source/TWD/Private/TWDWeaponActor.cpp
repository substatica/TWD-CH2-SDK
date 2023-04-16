#include "TWDWeaponActor.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "TWDAutoTickAkComponent.h"
#include "TWDWeaponShoveComponent.h"

class UPrimitiveComponent;
class USceneComponent;
class ATWDWeaponActor;
class UTWDWeaponHitCapsuleComponent;
class AActor;
class UAkAudioEvent;
class USDIWeaponHitCapsuleComponent;
class UDamageType;
class ATWDCharacter;
class ATWDDismemberDroppedLimb;
class UObject;

void ATWDWeaponActor::WeldChildToMainPhysicsComponent(UPrimitiveComponent* ToWeld) {
}

void ATWDWeaponActor::UpdateLowDurabilityMaterial() {
}

TArray<ATWDWeaponActor*> ATWDWeaponActor::UnstickAllWeaponsFromComponent(const USceneComponent* Comp, bool bSimulatePhysics, bool bRecurse, bool bRecurseIntoAttachedActors) {
    return TArray<ATWDWeaponActor*>();
}

TArray<ATWDWeaponActor*> ATWDWeaponActor::UnstickAllWeaponsFromActor(const AActor* Actor, bool bSimulatePhysics, bool bRecurseIntoAttachedActors) {
    return TArray<ATWDWeaponActor*>();
}

void ATWDWeaponActor::SuspendDismember() {
}

void ATWDWeaponActor::StopAkAudioComponent() {
}

bool ATWDWeaponActor::StartStick_Implementation(UTWDWeaponHitCapsuleComponent* InStickCapsule, bool bUsePrevTransform, const FTWDWeaponStickSettings& StickSettings, const FHitResult& HitInfo, float ImpactSpeed, bool bIsHeldByPlayerHand, bool bThrown, bool bLaunched) {
    return false;
}

bool ATWDWeaponActor::StartStab_Implementation(UTWDWeaponHitCapsuleComponent* InStabCapsule, const FHitResult& HitInfo, float InitialDepth, const FVector& CapsuleOffset, const FTransform& HitTransform, bool bIsHeldByPlayerHand, bool bThrown, bool bLaunched, bool bForceEmbedded) {
    return false;
}

void ATWDWeaponActor::StartSlowDismemberWoundAndEffects_Implementation(const FHitResult& WorldDismemberHitInfo) {
}

void ATWDWeaponActor::StabStuckEject() {
}

bool ATWDWeaponActor::StabEmbedWeapon(UTWDWeaponHitCapsuleComponent* InStabCapsule, AActor* Target, FName BoneName, float DepthPercent) {
    return false;
}

bool ATWDWeaponActor::ShouldAbortDismember() const {
    return false;
}

void ATWDWeaponActor::SetAkAudioComponentSwitch(const FString& SwitchGroup, const FString& SwitchState) {
}

void ATWDWeaponActor::SetAkAudioComponentRTPCValue(const FString& RTPC, float Value, int32 InterpolationTimeMs) {
}

void ATWDWeaponActor::ServerUpdateStabState_Implementation(ETWDWeaponStabState NewStabState) {
}
bool ATWDWeaponActor::ServerUpdateStabState_Validate(ETWDWeaponStabState NewStabState) {
    return true;
}

void ATWDWeaponActor::ServerStartStab_Implementation(const FHitResult& HitInfo, float InitialDepth) {
}
bool ATWDWeaponActor::ServerStartStab_Validate(const FHitResult& HitInfo, float InitialDepth) {
    return true;
}

void ATWDWeaponActor::ServerSetInventorySlotIdx_IFC_Implementation(uint8 InventorySlotIdx) {
}
bool ATWDWeaponActor::ServerSetInventorySlotIdx_IFC_Validate(uint8 InventorySlotIdx) {
    return true;
}

void ATWDWeaponActor::ServerEndStab_Implementation(bool bRemoveWeapon, float StabDepth) {
}
bool ATWDWeaponActor::ServerEndStab_Validate(bool bRemoveWeapon, float StabDepth) {
    return true;
}

void ATWDWeaponActor::ResumeDismember() {
}

int32 ATWDWeaponActor::PostEventToAkAudioComponent(UAkAudioEvent* Event, const FString& EventName) {
    return 0;
}


void ATWDWeaponActor::OnWeaponHit(USDIWeaponHitCapsuleComponent* SelfComponent, USDIWeaponHitCapsuleComponent* WeaponHitComponent, AActor* HitActor, UPrimitiveComponent* HitComp, const FVector& HitVelocity, const FTransform& HitTransform, const FHitResult& HitInfo, const UDamageType* DamageType) {
}

void ATWDWeaponActor::OnWeaponActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& HitInfo) {
}

void ATWDWeaponActor::OnRep_RepTWDInventoryData_Timer() {
}

void ATWDWeaponActor::OnRep_RepTWDInventoryData(const FTWDReplicatedInventoryActorInterfaceData& OldRepTWDInventoryData) {
}

void ATWDWeaponActor::OnRep_RepTWDDurabilityData(const FTWDReplicatedDurabilityInterfaceData& OldRepTWDDurabilityData) {
}

void ATWDWeaponActor::OnNonVRAttackAction_Implementation(const FTWDNonVRMeleeAttackDetails& Details) {
}

void ATWDWeaponActor::OnEndNonVRAttackDamageWindow_Implementation(const FTWDNonVRMeleeAttackDetails& Details) {
}

void ATWDWeaponActor::OnEndNonVRAttack_Implementation(const FTWDNonVRMeleeAttackDetails& Details) {
}

void ATWDWeaponActor::OnDurabilityBreak_Implementation() {
}



void ATWDWeaponActor::OnDismemberedLimb_Implementation(const FTWDWeaponDismemberSettings& Settings, const FHitResult& HitInfo, bool bThrown, const FTransform& CapsuleTransform, const FVector& DismemberAxis, const FVector& DismemberFlatAxis, bool bWeakpoint, bool bWasTargetDead, ATWDCharacter* Target, ETWDCharacterHitRegion Region, ATWDDismemberDroppedLimb* DroppedLimb, float Delay) {
}




void ATWDWeaponActor::OnBeginNonVRAttackDamageWindow_Implementation(const FTWDNonVRMeleeAttackDetails& Details, float TotalDuration) {
}

void ATWDWeaponActor::OnBeginNonVRAttack_Implementation(const FTWDNonVRMeleeAttackDetails& Details, float TotalDuration) {
}

void ATWDWeaponActor::NonVRShoveAttackFilter(const AActor* Actor, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge, bool& bRetVal) {
}

bool ATWDWeaponActor::K2IsStuck(FHitResult& OutStickHitInfo) const {
    return false;
}

bool ATWDWeaponActor::IsThreat(ATWDCharacter* Character) {
    return false;
}

bool ATWDWeaponActor::IsStuckOrStabbed(FHitResult& OutHitInfo, bool& bOutCharged, bool& bOutWeakpoint, bool& bOutWeakpointIsDiseased, bool& bOutPlayerExtraction) const {
    return false;
}

bool ATWDWeaponActor::IsStabbingAllowed() const {
    return false;
}

bool ATWDWeaponActor::IsHighThreat(ATWDCharacter* Character) {
    return false;
}

bool ATWDWeaponActor::IsDismemberGrappleImmunityActive(bool bPrimaryHand) const {
    return false;
}

bool ATWDWeaponActor::IsDismemberAllowed() const {
    return false;
}

bool ATWDWeaponActor::GetUseStabCooldownsForDismember() {
    return false;
}

bool ATWDWeaponActor::GetStabWeakpointIsDiseased() const {
    return false;
}

bool ATWDWeaponActor::GetStabWeakpoint() const {
    return false;
}

ETWDWeaponStabState ATWDWeaponActor::GetStabState() const {
    return ETWDWeaponStabState::None;
}

FVector ATWDWeaponActor::GetStabNormal() const {
    return FVector{};
}

float ATWDWeaponActor::GetStabLoopFeedbackHapticEffectScale(float& OutCurveTime) const {
    return 0.0f;
}

FVector ATWDWeaponActor::GetStabImpactPoint() const {
    return FVector{};
}

FVector ATWDWeaponActor::GetStabImpactNormal() const {
    return FVector{};
}

float ATWDWeaponActor::GetStabDepth() const {
    return 0.0f;
}

float ATWDWeaponActor::GetStabCurveInput() const {
    return 0.0f;
}

UPrimitiveComponent* ATWDWeaponActor::GetStabComponent() const {
    return NULL;
}

bool ATWDWeaponActor::GetStabCharged() const {
    return false;
}

FTransform ATWDWeaponActor::GetStabBoneTransform() const {
    return FTransform{};
}

FName ATWDWeaponActor::GetStabBoneName() const {
    return NAME_None;
}

ETWDNonVRMeleeAttackType ATWDWeaponActor::GetStabAttack() const {
    return ETWDNonVRMeleeAttackType::None;
}

float ATWDWeaponActor::GetLowDurabilityMaterialValue() const {
    return 0.0f;
}

FVector ATWDWeaponActor::GetExplosionOriginPoint() const {
    return FVector{};
}

ETWDWeaponDismemberState ATWDWeaponActor::GetDismemberState() const {
    return ETWDWeaponDismemberState::None;
}

float ATWDWeaponActor::GetDeathBlowImpulse_Implementation(TSubclassOf<UDamageType> DamageType) {
    return 0.0f;
}

void ATWDWeaponActor::EndStick_Implementation() {
}

void ATWDWeaponActor::EndStab_Implementation(bool bRemoveWeapon) {
}

void ATWDWeaponActor::DeactivateNonVRDismemberTrailFX() {
}

void ATWDWeaponActor::CompleteStab_Implementation(const FTransform& CompTransform, const FTWDWeaponStabSettings& Settings) {
}


void ATWDWeaponActor::AppliedDamage_Implementation(UTWDWeaponHitCapsuleComponent* WeaponHitComponent, const FHitResult& HitInfo) {
}

bool ATWDWeaponActor::AllowStickAfterStab_Implementation() const {
    return false;
}

bool ATWDWeaponActor::AkAudioComponentHasActiveEvents() const {
    return false;
}

void ATWDWeaponActor::AbortDismember(const FString& DebugReason) {
}

void ATWDWeaponActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATWDWeaponActor, RepTWDInventoryData);
    DOREPLIFETIME(ATWDWeaponActor, RepTWDDurabilityData);
    DOREPLIFETIME(ATWDWeaponActor, RepTimeDilationData);
    DOREPLIFETIME(ATWDWeaponActor, RepPlayerTimeDilationData);
    DOREPLIFETIME(ATWDWeaponActor, RepStabState);
    DOREPLIFETIME(ATWDWeaponActor, RepStabDepth);
    DOREPLIFETIME(ATWDWeaponActor, RepStabHit);
}

ATWDWeaponActor::ATWDWeaponActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AkAudioComponent = CreateDefaultSubobject<UTWDAutoTickAkComponent>(TEXT("AkAudioComponent"));
    this->AkAudioComponent->AttachTo(GetRootComponent());
    
    this->WeaponShoveComp = CreateDefaultSubobject<UTWDWeaponShoveComponent>(TEXT("WeaponShove"));

    this->BrokenReplacementClass = NULL;
    this->BrokenPrimaryHapticEffect = NULL;
    this->BrokenPrimaryHapticScale = 0.00f;
    this->BrokenSecondaryHapticEffect = NULL;
    this->BrokenSecondaryHapticScale = 0.00f;
    this->bUseLowDurabilityMaterialEffect = false;
    this->LowDurabilityMaterialThreshold = 0.00f;
    this->DraggingRagdollMinimumMass = 3.00f;
    this->DraggingRagdollAngularDamping = 10.00f;
    this->DraggingRagdollLinearDamping = 10.00f;
    this->bStabSyncMoveTarget = false;
    this->bStabSyncMoveAttacker = false;
    this->StabSyncMoveCharacterDistance = 8.00f;
    this->StabSyncMoveCharacterSpeed = 96.00f;
    this->StabSyncMoveCharacterMaxDuration = 1.00f;
    this->StabStartEvent = NULL;
    this->StabCompleteEvent = NULL;
    this->StabPullEvent = NULL;
    this->StabSawLoopStartEvent = NULL;
    this->StabSawLoopStopEvent = NULL;
    this->StabSawLoopVelocityRTPC = TEXT("StabVel");
    this->StabStartFeedback = NULL;
    this->StabCompleteFeedback = NULL;
    this->StabPullFeedback = NULL;
    this->StabIncrementalSawInFeedback = NULL;
    this->StabIncrementalSawOutFeedback = NULL;
    this->StabPushLoopFeedback = NULL;
    this->StabPullLoopFeedback = NULL;
    this->StabDragLocationPIDScalar = 1.00f;
    this->bDurabilityCanBreakOnWeaponHit = true;
    this->DurabilityRTPC = TEXT("DurabilityPercent");
    this->StabStuckEjectTime = 0.00f;
    this->bStabStuckEjectDeadOnly = true;
    this->bThrowAimAssist = false;
    this->ThrowAimAssistMinEngageThrowSpeed = 384.00f;
    this->ThrowAimAssistPathCollisionRadius = 8.00f;
    this->ThrowAimAssistPathCollisionTime = 1.00f;
    this->NonVRThrowAimAssistPathCollisionTime = 1.00f;
    this->ThrowAimAssistTargetRadius = 64.00f;
    this->NonVRThrowAimAssistTargetRadius = 64.00f;
    this->ThrowAimAssistTargetZOffset = 0.00f;
    this->NonVRThrowAimAssistTargetZOffset = 0.00f;
    this->ThrowAimAssistMinDesiredThrowSpeed = 512.00f;
    this->bCanStick = false;
    this->CurrentStabPhysicsConstraint = NULL;
    this->DismemberFeedback = NULL;
    this->DismemberFleshFeedback = NULL;
    this->DismemberBoneFeedback = NULL;
    this->bDismemberSyncMoveTarget = false;
    this->bDismemberSyncMoveAttacker = false;
    this->DismemberSyncMoveCharacterDistance = 8.00f;
    this->DismemberPushSyncMoveCharacterDistance = 8.00f;
    this->DismemberSyncMoveCharacterSpeed = 96.00f;
    this->DismemberSyncMoveCharacterMaxDuration = 1.00f;
    this->bDismemberFaceTarget = false;
    this->DismemberFaceTargetMinAngleDeg = 0.00f;
    this->DismemberFaceTargetTime = -1.00f;
    this->bDismemberFaceTargetMinAngleOnly = false;
    this->bDismemberRequiresLOS = false;
    this->bAllowAngleOfStrike = false;
    this->bAllowPrecisionStab = false;
    this->bAllowSplay = false;
    this->bSplayShove = true;
    this->NonVRAttackStaminaCostChargedMultiplier = 1.00f;
    this->NonVRAttackStaminaCostMiss = 0.00f;
    this->NonVRAttackStaminaCostHit = 0.00f;
    this->NonVRAttackStaminaCostHitWeakpoint = 0.00f;
    this->NonVRAttackStaminaCostHitDismember = 0.00f;
    this->NonVRAttackDurabilityCostHit = 0.00f;
    this->NonVRShoveAttackStaminaCost = 0.00f;
    this->NonVRShoveAttackDurabilityCost = 0.00f;
    this->bPlayNonVRShoveAttackCameraShakeOnStart = false;
    this->bPlayNonVRShoveAttackCameraShakeHitOnly = false;
    this->NonVRThreatAttackDistance = 250.00f;
    this->NonVRThreatMaximumThreatAngle = 50.00f;
    this->NonVRDismemberTrailSocket = TEXT("WeaponTrail");
    this->NonVRDismemberTrailDuration = 0.50f;
    this->NonVRDismemberTrailParticleSystemHuman = NULL;
    this->NonVRDismemberTrailParticleSystemWalker = NULL;
    this->CachedPreStabWeaponMass = -1.00f;
    this->CurrentStabCapsule = NULL;
    this->RepStabState = ETWDWeaponStabState::None;
    this->RepStabDepth = 0.00f;
    this->InitialStabDepth = 0.00f;
    this->bStabThrown = false;
    this->bStabLaunched = false;
    this->bStabCharged = false;
    this->bStabWeakpoint = false;
    this->bStabWeakpointIsDiseased = false;
    this->StabAttack = ETWDNonVRMeleeAttackType::None;
    this->StabLerpTimer = 0.00f;
    this->StabHoldTimer = 0.00f;
    this->RestabTimestamp = -1000.00f;
    this->StabRangedGrabDelayTimestamp = 0.00f;
    this->StabSawIncrement = 0;
    this->PrevStabSawIncrement = 0;
    this->LastSawFXTimeStamp = 0.00f;
    this->SyncMoveCharacterTimer = 0.00f;
    this->StabLerpDuration = 0.00f;
    this->CurrentStabPullOutStrengthMax = 0.00f;
    this->CurrentStabPullOutStrength = 0.00f;
    this->DefaultStabPushMovementMaxOffsetAngleDeg = 45.00f;
    this->DragUpdateStabConstraintCounter = 0;
    this->DismemberState = ETWDWeaponDismemberState::None;
    this->DismemberRegion = ETWDCharacterHitRegion::None;
    this->DismemberCapsule = NULL;
    this->LastDismemberCapsule = NULL;
    this->DismemberInterpDuration = 0.00f;
    this->bDismemberThrown = false;
    this->bDismemberLaunched = false;
    this->DismemberStateTimer = 0.00f;
    this->DismemberStateTimestamp = 0.00f;
    this->DismemberInterpDistance = 0.00f;
    this->AllowAdvDismember = false;
    this->StartDismemberDepth = 0.00f;
    this->DismemberPushStartDepth = 8.00f;
    this->InitialDismemberDepth = 0.00f;
    this->DismemberDepth = 0.00f;
    this->bIsDismemberPush = false;
    this->MaxDismemberDist = 0.00f;
    this->bContinuousDismember = false;
    this->DismemberResistanceForce = 0.00f;
    this->MaxDismemberResistanceForce = 50.00f;
    this->DismemberWoundID = 0;
    this->bSlowDismemberWoundAndEffectsStarted = false;
    this->InitialDismemberEvent = NULL;
    this->DismemberCompleteEvent = NULL;
    this->DismemberDisengageThreashold = 4.00f;
    this->DismemberGrappleImmunityTime = 2.00f;
    this->PermanentGrappleImmunity_PrimaryHand = false;
    this->bUseOriginalSlowDismemberControls = false;
    this->bDismemberNewPointAlgorithm = true;
    this->DismemberingLocationPIDScalar = 1.00f;
    this->DismemberingRotationPIDScalar = 1.00f;
    this->DismemberBoneSnapHapticEvent = NULL;
    this->DismemberBoneSnapAkEvent = NULL;
    this->DismemberBoneSnap_ResistanceWindow = 0.05f;
    this->DismemberBoneSnap_ResistanceDelta = 0.50f;
    this->DismemberResistanceHistoryMaxTime = 0.10f;
    this->bUseStabCooldownsForDismember = true;
    this->DismemberResistanceHistoryRelTime = 0.00f;
    this->bDismemberBoneSnapped = false;
    this->DismemberGrappleImmunityTimer = -1.00f;
    this->AttachmentEditor = NULL;
    this->SawFX = NULL;
    this->DismemberBoneFXComp = NULL;
    this->DismemberBoneFX = NULL;
    this->bPlayedStabSawLoopStartEvent = false;
    this->CurrentStickCapsule = NULL;
    this->bOnWeaponHitCausedDismember = false;
    this->bCurrentlyEndingStabWithDismember = false;
    this->NonVRDismemberTrailFX = NULL;
    this->NewStateToInit = ETWDWeaponDismemberState::None;
    this->bDeferredCreateDismemberWound = false;
    this->PrimaryDismemberHapticEffectLoopId = 0;
    this->SecondaryDismemberHapticEffectLoopId = 0;
}

