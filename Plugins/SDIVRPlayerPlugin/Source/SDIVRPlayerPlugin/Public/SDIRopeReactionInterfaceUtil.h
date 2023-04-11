#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "SDIPlayerHandMove.h"
#include "SDIRopeReactionFunctionAttachedParams.h"
#include "SDIRopeReactionStruggleTugAnim.h"
#include "SDIRopeReactionData.h"
#include "SDIRopeReactionStruggleActiveParams.h"
#include "SDIBlendOption.h"
#include "SDIRopeReactionStruggleTickParams.h"
#include "SDIRopeReactionElasticTautPhysicsParams.h"
#include "SDIRopeReactionStruggleCompleteParams.h"
#include "SDIRopeReactionTickParams.h"
#include "SDIRopeReactionFunctionDetachedParams.h"
#include "SDIRopeReactionFunctionGrabbedParams.h"
#include "SDIRopeReactionFunctionFiredParams.h"
#include "SDIRopeReactionFunctionDroppedParams.h"
#include "SDIRopeReactionFunctionCutParams.h"
#include "SDIRopeReactionAttachment.h"
#include "SDIRopeReactionInterfaceUtil.generated.h"

class UObject;
class UObject;
class UCurveFloat;
class UAkAudioEvent;
class ASDIInteractiveRopeActor;

UCLASS(BlueprintType)
class SDIVRPLAYERPLUGIN_API USDIRopeReactionInterfaceUtil : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USDIRopeReactionInterfaceUtil();
    UFUNCTION(BlueprintCallable)
    static void SetRopeTugEvent(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIPlayerHandMove& TugMove, float TugEngage, float TugDisengage, float TugMinTime);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStruggleTugIncrement(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTugAnim& TugIncrementAnim);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStruggleTugEvent(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIPlayerHandMove& TugMove, bool bRequireTwoHands, float TugEngage, float TugDisengage, float TugMinTime);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStruggleStick(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, float StickSpeed, bool bRequireTwoHands);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStrugglePaused(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, bool bPaused);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStruggleHandOffset(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, float OffsetSpeed, bool bRequireTwoHands);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStruggleFeedback(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, UObject* FeedbackLoop, UObject* StartFeedback, UObject* CompleteFeedback);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStruggleDecay(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, float DecayDelay, float DecaySpeed, UCurveFloat* DecaySpeedCurve);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeStruggleAudio(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIAkAudioEventPairDynamicLoop& SoundLoop, const FString& SoundLoopRTPC, UAkAudioEvent* TugSound, UAkAudioEvent* CancelSound, UAkAudioEvent* CompleteSound);
    
    UFUNCTION(BlueprintCallable)
    static void SetRopeDetachForces(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, UCurveFloat* HandForceCurve, float RopeImpulse, float RopeImpulseVerticality, const FSDIBlendOption& RopeImpulseBlend);
    
    UFUNCTION(BlueprintCallable)
    static float RopeStruggleTick_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, float DeltaTime, const FSDIRopeReactionStruggleTickParams& StruggleParams);
    
    UFUNCTION(BlueprintCallable)
    static void RopeStruggleComplete_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleCompleteParams& StruggleCompleteParams);
    
    UFUNCTION(BlueprintCallable)
    static void RopeReactionTick_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, float DeltaTime, const FSDIRopeReactionTickParams& TickParams);
    
    UFUNCTION(BlueprintCallable)
    static bool RopeIsStruggleActive_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleActiveParams& StruggleParams, bool& bOutAllowIncrement, float& OutStruggleAmount);
    
    UFUNCTION(BlueprintCallable)
    static float RopeGetElasticTautLength_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionElasticTautPhysicsParams& ElasticTautParams);
    
    UFUNCTION(BlueprintCallable)
    static bool RopeAllowElasticTautPhysics_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionElasticTautPhysicsParams& ElasticTautParams);
    
    UFUNCTION(BlueprintCallable)
    static void OnRopeGrabbed_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionGrabbedParams& GrabbedParams);
    
    UFUNCTION(BlueprintCallable)
    static void OnRopeFired_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionFiredParams& FiredParams);
    
    UFUNCTION(BlueprintCallable)
    static void OnRopeDropped_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionDroppedParams& DroppedParams);
    
    UFUNCTION(BlueprintCallable)
    static void OnRopeDetached_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionDetachedParams& DetachedParams);
    
    UFUNCTION(BlueprintCallable)
    static void OnRopeCut_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionCutParams& CutParams);
    
    UFUNCTION(BlueprintCallable)
    static void OnRopeAttached_Internal(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionFunctionAttachedParams& AttachedParams);
    
    UFUNCTION(BlueprintCallable)
    static bool GetRopeAttachment_Internal(const UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, ASDIInteractiveRopeActor* Rope, FSDIRopeReactionAttachment& OutAttachment);
    
    UFUNCTION(BlueprintCallable)
    static void EndRopeReactionOn(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, bool bImmediately, bool bDrop);
    
    UFUNCTION(BlueprintCallable)
    static void EndRopeReaction(ASDIInteractiveRopeActor* Rope, bool bImmediately, bool bDrop);
    
    UFUNCTION(BlueprintCallable)
    static void EnableRopeTugEvents(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, bool bEnabled, bool bRequireTwoHands, bool bAllowLateral);
    
    UFUNCTION(BlueprintCallable)
    static void EnableRopeStruggleTick(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, bool bEnabled, float MinTautLength);
    
    UFUNCTION(BlueprintCallable)
    static void EnableRopePullTick(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, bool bEnabled, bool bRequireTwoHands);
    
    UFUNCTION(BlueprintCallable)
    static float AlterRopeStruggleAmount(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams, float Delta);
    
    UFUNCTION(BlueprintCallable)
    static void AddRopeStruggleAmountAnim(UObject* InterfaceOwner, UPARAM(Ref) FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams, const FSDIRopeReactionStruggleTugAnim& AnimatedStruggleIncrement, bool bFromTug);
    
};

