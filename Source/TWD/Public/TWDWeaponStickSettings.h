#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "RFloatExp.h"
#include "TWDWeaponStickSettings.generated.h"

USTRUCT(BlueprintType)
struct FTWDWeaponStickSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bHeldStick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bThrownStick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bLaunchedStick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StickAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrownStickAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float LaunchedStickAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HeldStickMinVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrownStickMinVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float LaunchedStickMinVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStickOrientToNormal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bThrownStickOrientToNormal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bLaunchedStickOrientToNormal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StickDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StickThrownDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StickLaunchedDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PullStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp StickDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp PullDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnStick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnPull;
    
    TWD_API FTWDWeaponStickSettings();
};

