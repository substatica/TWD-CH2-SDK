#pragma once
#include "CoreMinimal.h"
#include "RFloatExp.h"
#include "TWDPlayerControllerTimeDilation.h"
#include "TWDWeaponSettingsNonVRHitRules.h"
#include "TWDWeaponStabSettings.generated.h"

USTRUCT(BlueprintType)
struct FTWDWeaponStabSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanStab;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabPushMotionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabPullMotionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabHeadHeldPullOutStrengthFactorMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrownStabAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float LaunchedStabAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabBrainMaxAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabWiggleAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabAllowWiggleAfterStart;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabWiggleSpeedDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabPushMovementMaxOffsetAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabOrientToNormal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bThrownStabOrientToNormal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bLaunchedStabOrientToNormal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabCompleteHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float RestabDelay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabRangedGrabDelay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabActiveRagdollStrengthMultiplyer;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp StabPullOutStrength;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabPullOutStrengthFactor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabStartStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabCompleteStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabPullStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp StabStartDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp StabCompleteDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp StabPullDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnStabStart;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnStabComplete;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnStabPull;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanStabOffscreen;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float OnscreenHorizontalAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float OnscreenVerticalAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation StabTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bThrownStabUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation ThrownStabTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bLaunchedStabUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation LaunchedStabTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRStabUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRStabTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRStabWeakpointUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRStabWeakpointTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRThrownStabUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRThrownStabTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRLaunchedStabUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRLaunchedStabTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDWeaponSettingsNonVRHitRules NonVRStabRules;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanPopHeadOnStab;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HeadPopChance;
    
    TWD_API FTWDWeaponStabSettings();
};

