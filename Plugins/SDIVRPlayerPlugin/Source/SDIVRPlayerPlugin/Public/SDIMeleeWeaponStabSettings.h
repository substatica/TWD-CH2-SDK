#pragma once
#include "CoreMinimal.h"
#include "ESDIAxis.h"
#include "SDIDamageData.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "SDIMeleeWeaponStabSettings.generated.h"

class UCurveFloat;
class UObject;
class UAkAudioEvent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIMeleeWeaponStabSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis StabAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabInterpolationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabNormalAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabForcedCapsuleOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabStartDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabMaxDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabExtractionDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabExtractionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabExtractionTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* StabInitialDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabCanPush;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* StabCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* StabPullCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData StabStartDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData StabCompleteDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData StabPullDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString StabImpactVelocityRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabStartAudio;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabCompleteAudio;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabPullAudio;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop StabSawLoop;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString StabSawLoopVelocityRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabStartFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabCompleteFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabPullFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabPushLoopFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* StabPushLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabPullLoopFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* StabPullLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 StabSawIncrements;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabIncrementalSawInFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabIncrementalSawOutFeedback;
    
    FSDIMeleeWeaponStabSettings();
};

