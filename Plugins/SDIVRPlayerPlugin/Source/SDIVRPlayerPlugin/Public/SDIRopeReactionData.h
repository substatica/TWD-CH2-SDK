#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDIPlayerHandMove.h"
#include "RFloat.h"
#include "SDIRopeReactionStruggleTugAnim.h"
#include "SDIBlendOption.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "SDIRopeReactionAttachment.h"
#include "SDIRopeReactionData.generated.h"

class UHapticFeedbackEffect_Base;
class UAkAudioEvent;
class UCurveFloat;
class UCurveBase;
class ASDIPlayerController;
class ASDIInteractiveRopeActor;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FComponentReference AkComponentRef;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAutoUpdateTautElasticity;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAutoUpdateTautElasticityWorldLocation;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAutoUpdateTautElasticityAvoidShoulderDislocation;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAutoFaceOnTaut;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bContinualFaceOnTaut;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float AutoFaceOnTautMinYawDeltaDegrees;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bTugEvents;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bTugRequireTwoHands;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bTugAllowLateral;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIPlayerHandMove TugMove;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float TugEngage;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float TugDisengage;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float TugMinTime;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* TugSound;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bPullTick;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bPullRequireTwoHands;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStruggleTick;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleMinTautLength;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIPlayerHandMove StruggleTugMove;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStruggleTugRequireTwoHands;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStruggleTugRequiredToComplete;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleTugEngage;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleTugDisengage;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleTugMinTime;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIRopeReactionStruggleTugAnim StruggleTugIncrementAnim;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleStickSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStruggleStickRequireTwoHands;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FRFloat StruggleHandOffsetRange;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleHandOffsetSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStruggleHandOffsetRequireTwoHands;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleDecayDelay;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UCurveFloat* StruggleDecaySpeedCurve;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float StruggleDecaySpeed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UHapticFeedbackEffect_Base* StruggleFeedbackLoop;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIBlendOption StruggleFeedbackLoopBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StruggleStartFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StruggleCompleteFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop StruggleSoundLoop;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString StruggleSoundLoopRTPC;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* StruggleTugSound;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* StruggleCancelSound;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* StruggleCompleteSound;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UCurveBase* DetachHandForceCurve;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float DetachRopeImpulse;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float DetachRopeImpulseVerticality;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIBlendOption DetachRopeImpulseBlend;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    TWeakObjectPtr<ASDIPlayerController> PlayerController;
    
    UPROPERTY(Transient)
    bool bWasTaut;
    
    UPROPERTY(Transient)
    float TugTime;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float StruggleAmount;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float LastStruggleAmount;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float LastStruggleAmountDelta;
    
    UPROPERTY(Transient)
    float StruggleTugTime;
    
    UPROPERTY(Transient)
    float StruggleNoInputTime;
    
    UPROPERTY(Transient)
    TArray<FSDIRopeReactionStruggleTugAnim> StruggleAnims;
    
    UPROPERTY(Transient)
    int32 StruggleFeedbackLoopId[2];
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bStrugglePaused;
    
protected:
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ASDIInteractiveRopeActor>, FSDIRopeReactionAttachment> AttachedRopes;
    
public:
    FSDIRopeReactionData();
};

