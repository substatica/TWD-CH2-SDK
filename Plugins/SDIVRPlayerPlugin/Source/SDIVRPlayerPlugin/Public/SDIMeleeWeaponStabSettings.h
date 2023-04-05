#pragma once
#include "CoreMinimal.h"
#include "ESDIAxis.h"
#include "SDIDamageData.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "SDIMeleeWeaponStabSettings.generated.h"

class UCurveFloat;
class UHapticFeedbackEffect_Base;
class UAkAudioEvent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIMeleeWeaponStabSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    ESDIAxis StabAxis;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabInterpolationDuration;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabNormalAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabForcedCapsuleOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabStartDepth;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabMaxDepth;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabExtractionDepth;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabExtractionDelay;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabExtractionTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* StabInitialDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bStabCanPush;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* StabCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* StabPullCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIDamageData StabStartDamageData;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIDamageData StabCompleteDamageData;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIDamageData StabPullDamageData;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString StabImpactVelocityRTPC;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabStartAudio;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabCompleteAudio;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabPullAudio;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop StabSawLoop;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString StabSawLoopVelocityRTPC;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabStartFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabCompleteFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabPullFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabPushLoopFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* StabPushLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabPullLoopFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* StabPullLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 StabSawIncrements;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabIncrementalSawInFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabIncrementalSawOutFeedback;
    
    FSDIMeleeWeaponStabSettings();
};

