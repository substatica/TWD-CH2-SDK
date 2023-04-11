#include "SDIRopeReactionInterfaceUtil.h"

class UObject;
class UAkAudioEvent;
class UObject;
class UCurveFloat;
class ASDIInteractiveRopeActor;

void USDIRopeReactionInterfaceUtil::SetRopeTugEvent(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIPlayerHandMove& TugMove, float TugEngage, float TugDisengage, float TugMinTime) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStruggleTugIncrement(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTugAnim& TugIncrementAnim) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStruggleTugEvent(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIPlayerHandMove& TugMove, bool bRequireTwoHands, float TugEngage, float TugDisengage, float TugMinTime) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStruggleStick(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, float StickSpeed, bool bRequireTwoHands) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStrugglePaused(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, bool bPaused) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStruggleHandOffset(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, float OffsetSpeed, bool bRequireTwoHands) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStruggleFeedback(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, UObject* FeedbackLoop, UObject* StartFeedback, UObject* CompleteFeedback) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStruggleDecay(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, float DecayDelay, float DecaySpeed, UCurveFloat* DecaySpeedCurve) {
}

void USDIRopeReactionInterfaceUtil::SetRopeStruggleAudio(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIAkAudioEventPairDynamicLoop& SoundLoop, const FString& SoundLoopRTPC, UAkAudioEvent* TugSound, UAkAudioEvent* CancelSound, UAkAudioEvent* CompleteSound) {
}

void USDIRopeReactionInterfaceUtil::SetRopeDetachForces(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, UCurveFloat* HandForceCurve, float RopeImpulse, float RopeImpulseVerticality, const FSDIBlendOption& RopeImpulseBlend) {
}

float USDIRopeReactionInterfaceUtil::RopeStruggleTick_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, float DeltaTime, const FSDIRopeReactionStruggleTickParams& StruggleParams) {
    return 0.0f;
}

void USDIRopeReactionInterfaceUtil::RopeStruggleComplete_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleCompleteParams& StruggleCompleteParams) {
}

void USDIRopeReactionInterfaceUtil::RopeReactionTick_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, float DeltaTime, const FSDIRopeReactionTickParams& TickParams) {
}

bool USDIRopeReactionInterfaceUtil::RopeIsStruggleActive_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleActiveParams& StruggleParams, bool& bOutAllowIncrement, float& OutStruggleAmount) {
    return false;
}

float USDIRopeReactionInterfaceUtil::RopeGetElasticTautLength_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionElasticTautPhysicsParams& ElasticTautParams) {
    return 0.0f;
}

bool USDIRopeReactionInterfaceUtil::RopeAllowElasticTautPhysics_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionElasticTautPhysicsParams& ElasticTautParams) {
    return false;
}

void USDIRopeReactionInterfaceUtil::OnRopeGrabbed_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionGrabbedParams& GrabbedParams) {
}

void USDIRopeReactionInterfaceUtil::OnRopeFired_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionFiredParams& FiredParams) {
}

void USDIRopeReactionInterfaceUtil::OnRopeDropped_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionDroppedParams& DroppedParams) {
}

void USDIRopeReactionInterfaceUtil::OnRopeDetached_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionDetachedParams& DetachedParams) {
}

void USDIRopeReactionInterfaceUtil::OnRopeCut_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionCutParams& CutParams) {
}

void USDIRopeReactionInterfaceUtil::OnRopeAttached_Internal(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionAttachedParams& AttachedParams) {
}

bool USDIRopeReactionInterfaceUtil::GetRopeAttachment_Internal(const UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, ASDIInteractiveRopeActor* Rope, FSDIRopeReactionAttachment& OutAttachment) {
    return false;
}

void USDIRopeReactionInterfaceUtil::EndRopeReactionOn(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, bool bImmediately, bool bDrop) {
}

void USDIRopeReactionInterfaceUtil::EndRopeReaction(ASDIInteractiveRopeActor* Rope, bool bImmediately, bool bDrop) {
}

void USDIRopeReactionInterfaceUtil::EnableRopeTugEvents(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, bool bEnabled, bool bRequireTwoHands, bool bAllowLateral) {
}

void USDIRopeReactionInterfaceUtil::EnableRopeStruggleTick(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, bool bEnabled, float MinTautLength) {
}

void USDIRopeReactionInterfaceUtil::EnableRopePullTick(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, bool bEnabled, bool bRequireTwoHands) {
}

float USDIRopeReactionInterfaceUtil::AlterRopeStruggleAmount(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams, float Delta) {
    return 0.0f;
}

void USDIRopeReactionInterfaceUtil::AddRopeStruggleAmountAnim(UObject* InterfaceOwner, FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams, const FSDIRopeReactionStruggleTugAnim& AnimatedStruggleIncrement, bool bFromTug) {
}

USDIRopeReactionInterfaceUtil::USDIRopeReactionInterfaceUtil() {
}

