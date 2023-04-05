#include "SDICoreCharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"

class UPrimitiveComponent;
class AActor;

void USDICoreCharacterMovementComponent::SetBaseGroundMovementSpeedType(EAIBaseGroundMovementSpeedType NewBaseGroundMovementSpeedType) {
}

void USDICoreCharacterMovementComponent::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void USDICoreCharacterMovementComponent::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool USDICoreCharacterMovementComponent::IsSprinting(bool bCheckVelocity) const {
    return false;
}

bool USDICoreCharacterMovementComponent::IsRagdoll(bool& bOutOnFloor, float& OutLowVelocityTime) const {
    return false;
}

bool USDICoreCharacterMovementComponent::IsForceCrouch() const {
    return false;
}

float USDICoreCharacterMovementComponent::GetMaxSprintSpeed() const {
    return 0.0f;
}

float USDICoreCharacterMovementComponent::GetMaxSpeedWithoutSprinting() const {
    return 0.0f;
}

EAIBaseGroundMovementSpeedType USDICoreCharacterMovementComponent::GetBaseGroundMovementSpeedType() const {
    return EAIBaseGroundMovementSpeedType::Walk;
}

void USDICoreCharacterMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USDICoreCharacterMovementComponent, bRepWantsToSprint);
}

USDICoreCharacterMovementComponent::USDICoreCharacterMovementComponent() {
    this->MaxJogSpeed = 225.00f;
    this->MaxRunSpeed = 300.00f;
    this->MaxDashSpeed = 500.00f;
    this->MaxStrollSpeed = 115.00f;
    this->MaxSprintSpeed = 900.00f;
    this->MaxFallSpeed = 1500.00f;
    this->bCanSprint = true;
    this->bCanSprintWithoutStickDeflection = false;
    this->bSprintToggleDoesNotCancelSprint = false;
    this->MinAnalogWalkSpeedCrouched = 0.00f;
    this->MinAnalogWalkSpeedSprint = 0.00f;
    this->CollisionMaxSpeedMultiplierCurve = NULL;
    this->CollisionMaxSpeedMultiplierCapsuleHeightScale = 0.75f;
    this->FallingCollisionMaxSpeedMultiplierCurve = NULL;
    this->FallingCollisionMaxSpeedMultiplierCapsuleHeightScale = 0.90f;
    this->RagdollLowVelocityThreshold = 32.00f;
    this->BaseGroundMovementSpeedType = EAIBaseGroundMovementSpeedType::Walk;
    this->MovementModeTime = 0.00f;
    this->bRepWantsToSprint = false;
    this->RagdollLowVelocityTime = 0.00f;
    this->CollisionMaxSpeedMultiplierCurveRange = 0.00f;
    this->FallingCollisionMaxSpeedMultiplierCurveRange = 0.00f;
    this->CollisionMaxSpeedMultiplier = 1.00f;
    this->bComponentOverlapForceCrouch = false;
    this->StartBaseEyeHeight = 0.00f;
}

