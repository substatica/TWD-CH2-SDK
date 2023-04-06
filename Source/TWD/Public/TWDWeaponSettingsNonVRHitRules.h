#pragma once
#include "CoreMinimal.h"
#include "TWDWeaponSettingsNonVRHitRules.generated.h"

USTRUCT(BlueprintType)
struct FTWDWeaponSettingsNonVRHitRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bWeakpoint;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bWeakpointRequireChargedAttack;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonWeakpoint;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonWeakpointRequireChargedAttack;
    
    TWD_API FTWDWeaponSettingsNonVRHitRules();
};

