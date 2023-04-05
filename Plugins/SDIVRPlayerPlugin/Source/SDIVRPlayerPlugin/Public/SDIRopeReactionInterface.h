#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionPullParams.h"
#include "SDIRopeReactionTugParams.h"
#include "SDIRopeReactionStruggleActiveParams.h"
#include "UObject/Interface.h"
#include "SDIRopeReactionTickParams.h"
#include "SDIRopeReactionStruggleTickParams.h"
#include "SDIRopeReactionStruggleCompleteParams.h"
#include "SDIRopeReactionElasticTautPhysicsParams.h"
#include "SDIRopeReactionFunctionDetachedParams.h"
#include "SDIRopeReactionFunctionGrabbedParams.h"
#include "SDIRopeReactionFunctionFiredParams.h"
#include "SDIRopeReactionFunctionDroppedParams.h"
#include "SDIRopeReactionFunctionCutParams.h"
#include "SDIRopeReactionFunctionAttachedParams.h"
#include "SDIRopeReactionAttachment.h"
#include "SDIRopeReactionInterface.generated.h"

class ASDIInteractiveRopeActor;

UINTERFACE(Blueprintable)
class SDIVRPLAYERPLUGIN_API USDIRopeReactionInterface : public UInterface {
    GENERATED_BODY()
};

class SDIVRPLAYERPLUGIN_API ISDIRopeReactionInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent)
    float RopeStruggleTick(float DeltaTime, const FSDIRopeReactionStruggleTickParams& StruggleTickParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void RopeStruggleComplete(const FSDIRopeReactionStruggleCompleteParams& StruggleCompleteParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void RopeReactionTick(float DeltaTime, const FSDIRopeReactionTickParams& TickParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void RopePullTick(float DeltaTime, const FSDIRopeReactionPullParams& PullParams);
    
    UFUNCTION(BlueprintNativeEvent)
    bool RopeIsStruggleActive(const FSDIRopeReactionStruggleActiveParams& StruggleActiveParams, bool& bOutAllowIncrement, float& OutStruggleAmount);
    
    UFUNCTION(BlueprintNativeEvent)
    float RopeGetElasticTautLength(const FSDIRopeReactionElasticTautPhysicsParams& ElasticTautParams);
    
    UFUNCTION(BlueprintNativeEvent)
    bool RopeAllowElasticTautPhysics(const FSDIRopeReactionElasticTautPhysicsParams& ElasticTautParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRopeTug(const FSDIRopeReactionTugParams& TugParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRopeGrabbed(const FSDIRopeReactionFunctionGrabbedParams& GrabbedParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRopeFired(const FSDIRopeReactionFunctionFiredParams& FiredParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRopeDropped(const FSDIRopeReactionFunctionDroppedParams& DroppedParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRopeDetached(const FSDIRopeReactionFunctionDetachedParams& DetachedParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRopeCut(const FSDIRopeReactionFunctionCutParams& CutParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRopeAttached(const FSDIRopeReactionFunctionAttachedParams& AttachedParams);
    
    UFUNCTION(BlueprintNativeEvent)
    bool GetRopeAttachment(ASDIInteractiveRopeActor* Rope, FSDIRopeReactionAttachment& OutAttachment) const;
    
};

