#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "AlphaBlend.h"
#include "TWDPlayerControllerTimeDilation.h"
#include "RFloatExp.h"
#include "TWDWeaponSettingsNonVRHitRules.h"
#include "UObject/NoExportTypes.h"
#include "TWDWeaponDismemberSettings.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FTWDWeaponDismemberSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bHeldDismember;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bThrownDismember;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bLaunchedDismember;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MinImpactVelocity;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FName LimbSocketName;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TEnumAsByte<EAxis::Type> LimbSocketAxis;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bLimbSocketAxisZIsWorld;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve DismemberResistanceCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxDistanceAlongLimb;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxFlatAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FName WeaponTargetSocketName;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberHoldTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberInterpTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    EAlphaBlendOption DismemberInterpBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* DismemberInterpBlendCustomCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberFollowThroughForceMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StaminaCost;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRFloatExp DurabilityCost;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDurabilityCanBreakOnDismember;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberActiveRagdollStrengthMultiplyer;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberPushMotionMultiplierPreResistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberPushMotionMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxDismemberDist;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FVector MaxDismemberDistExtent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanDismemberOffscreen;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float OnscreenHorizontalAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float OnscreenVerticalAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bHeldDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation HeldDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bThrownDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation ThrownDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bLaunchedDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation LaunchedDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNonVRHeldDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRHeldDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNonVRHeldDismemberWeakpointUseTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRHeldDismemberWeakpointTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNonVRThrownDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRThrownDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNonVRLaunchedDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRLaunchedDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAdvancedDismemberOnly;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bUseSlowDismembering;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDWeaponSettingsNonVRHitRules NonVRDismemberRules;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRHeldDismemberDelay;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRThrownDismemberDelay;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRLaunchedDismemberDelay;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRHeldDismemberSplayDuration;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberDirectionControlBiasExponent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberLateralDirectionControlBiasExponent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberLateralDirectionDotThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberDirectionControlReverseThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float GrazeAngleThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float GrazeAngleCorrectionThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FVector GrazeWoundSize;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FVector PreSeverWoundSize;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FVector MaxPreSeverWoundSize;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float PreSeverWoundDistanceForward;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FVector2D PreSeverWoundSplashRatio;
    
    TWD_API FTWDWeaponDismemberSettings();
};

