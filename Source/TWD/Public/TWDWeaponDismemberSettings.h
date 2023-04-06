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
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bHeldDismember;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bThrownDismember;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bLaunchedDismember;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MinImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName LimbSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<EAxis::Type> LimbSocketAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bLimbSocketAxisZIsWorld;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve DismemberResistanceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxDistanceAlongLimb;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxFlatAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName WeaponTargetSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberInterpTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EAlphaBlendOption DismemberInterpBlend;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* DismemberInterpBlendCustomCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberFollowThroughForceMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp DurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnDismember;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberActiveRagdollStrengthMultiplyer;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberPushMotionMultiplierPreResistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberPushMotionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxDismemberDist;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector MaxDismemberDistExtent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanDismemberOffscreen;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float OnscreenHorizontalAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float OnscreenVerticalAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bHeldDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation HeldDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bThrownDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation ThrownDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bLaunchedDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation LaunchedDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRHeldDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRHeldDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRHeldDismemberWeakpointUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRHeldDismemberWeakpointTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRThrownDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRThrownDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonVRLaunchedDismemberUseTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDPlayerControllerTimeDilation NonVRLaunchedDismemberTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAdvancedDismemberOnly;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUseSlowDismembering;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDWeaponSettingsNonVRHitRules NonVRDismemberRules;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRHeldDismemberDelay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRThrownDismemberDelay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRLaunchedDismemberDelay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRHeldDismemberSplayDuration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberDirectionControlBiasExponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberLateralDirectionControlBiasExponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberLateralDirectionDotThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberDirectionControlReverseThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float GrazeAngleThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float GrazeAngleCorrectionThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector GrazeWoundSize;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector PreSeverWoundSize;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector MaxPreSeverWoundSize;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PreSeverWoundDistanceForward;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector2D PreSeverWoundSplashRatio;
    
    TWD_API FTWDWeaponDismemberSettings();
};

