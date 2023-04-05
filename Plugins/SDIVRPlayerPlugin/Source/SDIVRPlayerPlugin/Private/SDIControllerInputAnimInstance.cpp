#include "SDIControllerInputAnimInstance.h"

void USDIControllerInputAnimInstance::UnlockClench() {
}

void USDIControllerInputAnimInstance::SetHandPoseInfo(const FSDIHandPoseInfo& NewPose, bool bBlend, float BlendSpeed, bool bForHighlight) {
}

void USDIControllerInputAnimInstance::SetClench(float NewClench) {
}

void USDIControllerInputAnimInstance::LockClench(float NewClench) {
}

bool USDIControllerInputAnimInstance::IsClenchLocked(float& OutLockedClench) const {
    return false;
}

void USDIControllerInputAnimInstance::InputTrigger(float Value) {
}

void USDIControllerInputAnimInstance::InputThumbUp(float Value) {
}

void USDIControllerInputAnimInstance::InputPointing(float Value) {
}

void USDIControllerInputAnimInstance::InputGripRing(float Value) {
}

void USDIControllerInputAnimInstance::InputGripPinky(float Value) {
}

void USDIControllerInputAnimInstance::InputGripMiddle(float Value) {
}

void USDIControllerInputAnimInstance::InputGrip(float Value) {
}

float USDIControllerInputAnimInstance::GetTrigger() const {
    return 0.0f;
}

float USDIControllerInputAnimInstance::GetThumbUp() const {
    return 0.0f;
}

float USDIControllerInputAnimInstance::GetPointing() const {
    return 0.0f;
}

float USDIControllerInputAnimInstance::GetGripRing() const {
    return 0.0f;
}

float USDIControllerInputAnimInstance::GetGripPinky() const {
    return 0.0f;
}

float USDIControllerInputAnimInstance::GetGripMiddle() const {
    return 0.0f;
}

float USDIControllerInputAnimInstance::GetGrip() const {
    return 0.0f;
}

USDIControllerInputAnimInstance::USDIControllerInputAnimInstance() {
    this->InterpSpeed = 30.00f;
    this->PoseInterpSpeed = 10.00f;
    this->HandPoseLinkedGraphTag = TEXT("HandPoseLinkedGraph");
    this->LockedClench = -1.00f;
    this->Trigger = 0.00f;
    this->GripPinky = 0.00f;
    this->GripRing = 0.00f;
    this->GripMiddle = 0.00f;
    this->Pointing = 1.00f;
    this->ThumbUp = 1.00f;
    this->GripPinkyClenchRaw = 0.00f;
    this->GripPinkyClench = 0.00f;
    this->GripRingClenchRaw = 0.00f;
    this->GripRingClench = 0.00f;
    this->GripMiddleClenchRaw = 0.00f;
    this->GripMiddleClench = 0.00f;
    this->GripPose = 0.00f;
    this->PointingClenchRaw = 0.00f;
    this->PointingClench = 0.00f;
    this->PointingPose = 0.00f;
    this->ThumbClenchRaw = 0.00f;
    this->ThumbClench = 0.00f;
    this->ThumbPose = 0.00f;
    this->hand = EControllerHand::AnyHand;
    this->bHandPoseInfoForHighlight = false;
    this->CachedSnapshot = TEXT("CachedSnapshot");
    this->CachedAlpha = 1.00f;
    this->OverridePoseInterpSpeed = -1.00f;
    this->bCustomLinkedHandPoseAnimInstance = false;
    this->DefaultHandPoseAnimInstance = NULL;
}

