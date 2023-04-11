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

class UObject;
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAutoUpdateTautElasticity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAutoUpdateTautElasticityWorldLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAutoUpdateTautElasticityAvoidShoulderDislocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAutoFaceOnTaut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bContinualFaceOnTaut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AutoFaceOnTautMinYawDeltaDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bTugEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bTugRequireTwoHands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bTugAllowLateral;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIPlayerHandMove TugMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float TugEngage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float TugDisengage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float TugMinTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* TugSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bPullTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bPullRequireTwoHands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStruggleTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleMinTautLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIPlayerHandMove StruggleTugMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStruggleTugRequireTwoHands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStruggleTugRequiredToComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleTugEngage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleTugDisengage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleTugMinTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIRopeReactionStruggleTugAnim StruggleTugIncrementAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleStickSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStruggleStickRequireTwoHands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat StruggleHandOffsetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleHandOffsetSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStruggleHandOffsetRequireTwoHands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleDecayDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UCurveFloat* StruggleDecaySpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StruggleDecaySpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UObject* StruggleFeedbackLoop;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIBlendOption StruggleFeedbackLoopBlend;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StruggleStartFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StruggleCompleteFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop StruggleSoundLoop;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString StruggleSoundLoopRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* StruggleTugSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* StruggleCancelSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* StruggleCompleteSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UCurveBase* DetachHandForceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DetachRopeImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DetachRopeImpulseVerticality;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption DetachRopeImpulseBlend;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ASDIPlayerController> PlayerController;
    
    UPROPERTY(Transient)
    bool bWasTaut;
    
    UPROPERTY(Transient)
    float TugTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float StruggleAmount;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LastStruggleAmount;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LastStruggleAmountDelta;
    
    UPROPERTY(Transient)
    float StruggleTugTime;
    
    UPROPERTY(Transient)
    float StruggleNoInputTime;
    
    UPROPERTY(Transient)
    TArray<FSDIRopeReactionStruggleTugAnim> StruggleAnims;
    
    UPROPERTY(Transient)
    int32 StruggleFeedbackLoopId[2];
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bStrugglePaused;
    
protected:
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ASDIInteractiveRopeActor>, FSDIRopeReactionAttachment> AttachedRopes;
    
public:
    FSDIRopeReactionData();
};

