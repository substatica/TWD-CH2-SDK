#include "SDICoreCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "SDIRigidBodySleeperComponent.h"
#include "SDICollisionChannelIgnoranceComponent.h"
#include "PhysicsEngine/PhysicalAnimationComponent.h"

class USDICoreUtilityAI;
class APlayerController;

bool ASDICoreCharacter::UtilityAIConsumingInput() const {
    return false;
}

void ASDICoreCharacter::StopRagdollAnimation() {
}

bool ASDICoreCharacter::StopRagdoll(const bool bAttachToMeshRoot) {
    return false;
}

bool ASDICoreCharacter::StartRagdollAnimation(float PhysicalAnimationStrength, FName PhysicalAnimationProfileName, float PhysicalAnimationDuration) {
    return false;
}

bool ASDICoreCharacter::StartRagdoll(const bool bStartImmediately, FName OverrideConstraintProfileName, float OverrideConstraintProfileDuration, float PhysicalAnimationStrength, FName PhysicalAnimationProfileName, float PhysicalAnimationDuration, const bool bWasQueued) {
    return false;
}

bool ASDICoreCharacter::SetHandIKTransform(EControllerHand hand, const FTransform& Transform) {
    return false;
}

bool ASDICoreCharacter::SetHandIKOnSurface(EControllerHand hand, const FHitResult& Hit, const FVector& HandHintDirection, bool bHintDirectionIsHandForward) {
    return false;
}

bool ASDICoreCharacter::SetHandIKDirections(EControllerHand hand, const FVector& Location, const FVector& HandForward, const FVector& HandHintDirection, bool bHintDirectionIsPalmDirection) {
    return false;
}

bool ASDICoreCharacter::SetHandIKActive(EControllerHand hand, bool bActive, float BlendTime) {
    return false;
}

void ASDICoreCharacter::SetBaseGroundMovementSpeedType_Implementation(EAIBaseGroundMovementSpeedType NewBaseGroundMovementSpeedType) {
}

void ASDICoreCharacter::SetADS(bool bADS) {
}

void ASDICoreCharacter::ServerSetADS_Implementation(bool bADS) {
}
bool ASDICoreCharacter::ServerSetADS_Validate(bool bADS) {
    return true;
}

void ASDICoreCharacter::ResetInputs() {
}

void ASDICoreCharacter::RemoveRagdollImpulses(bool bCancelVelocity, bool bQueuedDirect, bool bQueuedRadial) {
}

void ASDICoreCharacter::RecreateRagdoll(const FName& OverrideConstraintProfileName) {
}

void ASDICoreCharacter::PlayerControllerDetached_Implementation(APlayerController* PC) {
}

void ASDICoreCharacter::PlayerControllerAttached_Implementation(APlayerController* PC) {
}

void ASDICoreCharacter::OnRep_RepDamageTakenData(const FSDIReplicatedDamageData& OldRepDamageTakenData) {
}

void ASDICoreCharacter::OnRep_RepDamageInflictedData(const FSDIReplicatedDamageData& OldRepDamageInflictedData) {
}

void ASDICoreCharacter::OnRep_bRepADS(bool bOldRepADS) {
}

void ASDICoreCharacter::OnADSChanged_Implementation(bool bADS) {
}

void ASDICoreCharacter::MeshOnPhysicsStateChange() {
}

bool ASDICoreCharacter::IsThirdPerson() const {
    return false;
}

bool ASDICoreCharacter::IsRagdollQueued() const {
    return false;
}

bool ASDICoreCharacter::IsRagdollAnimationQueued() const {
    return false;
}

bool ASDICoreCharacter::IsRagdollAnimationActiveOrQueued() const {
    return false;
}

bool ASDICoreCharacter::IsRagdollAnimationActive() const {
    return false;
}

bool ASDICoreCharacter::IsRagdollActiveOrQueued() const {
    return false;
}

bool ASDICoreCharacter::IsRagdollActive() const {
    return false;
}

bool ASDICoreCharacter::IsInImmobileState_Implementation() const {
    return false;
}

bool ASDICoreCharacter::IsHandIKActive(EControllerHand hand) const {
    return false;
}

bool ASDICoreCharacter::IsFirstPerson() const {
    return false;
}

bool ASDICoreCharacter::IsADSAllowed_Implementation() const {
    return false;
}

bool ASDICoreCharacter::IsADS() const {
    return false;
}

void ASDICoreCharacter::InputToggleSprintReleased() {
}

void ASDICoreCharacter::InputToggleSprintPressed() {
}

void ASDICoreCharacter::InputToggleCrouchReleased() {
}

void ASDICoreCharacter::InputToggleCrouchPressed() {
}

void ASDICoreCharacter::InputSprintReleased() {
}

void ASDICoreCharacter::InputSprintPressed() {
}

void ASDICoreCharacter::InputMoveRightAxis(float Value) {
}

void ASDICoreCharacter::InputMoveRight(float Value) {
}

void ASDICoreCharacter::InputMoveLeft(float Value) {
}

void ASDICoreCharacter::InputMoveForwardAxis(float Value) {
}

void ASDICoreCharacter::InputMoveForward(float Value) {
}

void ASDICoreCharacter::InputMoveBackward(float Value) {
}

void ASDICoreCharacter::InputCrouchReleased() {
}

void ASDICoreCharacter::InputCrouchPressed() {
}

TSubclassOf<USDICoreUtilityAI> ASDICoreCharacter::GetUtilityAIClass() const {
    return NULL;
}

FSDIReplicatedDamageData ASDICoreCharacter::GetLastDamageTaken() const {
    return FSDIReplicatedDamageData{};
}

FSDIReplicatedDamageData ASDICoreCharacter::GetLastDamageInflicted() const {
    return FSDIReplicatedDamageData{};
}

bool ASDICoreCharacter::EnableHandIKEffectorSpring(EControllerHand hand, bool bEnabled) {
    return false;
}

bool ASDICoreCharacter::AddRagdollRadialImpulse(FVector Origin, float Radius, float Strength, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange) {
    return false;
}

bool ASDICoreCharacter::AddRagdollImpulseAtLocation(FVector Impulse, FVector Location, FName BoneName) {
    return false;
}

bool ASDICoreCharacter::AddRagdollImpulse(FVector Impulse, FName BoneName, bool bVelChange) {
    return false;
}

void ASDICoreCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDICoreCharacter, RepRagdollBones);
    DOREPLIFETIME(ASDICoreCharacter, bRepADS);
    DOREPLIFETIME(ASDICoreCharacter, RepDamageTakenData);
    DOREPLIFETIME(ASDICoreCharacter, RepDamageInflictedData);
}

ASDICoreCharacter::ASDICoreCharacter() {
    this->CapsuleCollisionIgnoranceComp = CreateDefaultSubobject<USDICollisionChannelIgnoranceComponent>(TEXT("CapsuleCollisionIgnorance"));
    this->MeshCollisionIgnoranceComp = CreateDefaultSubobject<USDICollisionChannelIgnoranceComponent>(TEXT("MeshCollisionIgnorance"));
    this->RigidBodySleeperComponent = CreateDefaultSubobject<USDIRigidBodySleeperComponent>(TEXT("RigidBodySleeperComponent"));
    this->RagdollPhysicalAnimationComponent = CreateDefaultSubobject<UPhysicalAnimationComponent>(TEXT("RagdollPhysicalAnimationComponent"));
    this->SprintCancelMinVelocityPct = 0.50f;
    this->SprintCancelTime = 0.50f;
    this->SprintMinAnalogInput = 0.50f;
    this->RagdollRootBoneName = TEXT("pelvis");
    this->UtilityAIClass = NULL;
    this->NetObstructedCullDistanceSquared = 16777216.00f;
    this->bRepADS = false;
    this->bCtrlSprint = false;
    this->bCtrlSprintWasToggled = false;
    this->SprintCancelTimer = 0.00f;
    this->bCtrlCrouch = false;
    this->bCtrlCrouchWasToggled = false;
    this->bAnyRagdollBonesUpdated = false;
}

