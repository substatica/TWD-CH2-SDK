#pragma once
#include "CoreMinimal.h"
#include "RFloatExp.h"
#include "SDICoreUtilityAITargetEntry.h"
#include "SDICoreUtilityAITarget.generated.h"

class USDICoreUtilityAI;
class AActor;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICoreUtilityAITarget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    USDICoreUtilityAI* Owner;
    
public:
    UPROPERTY(EditAnywhere)
    FRFloatExp MaintainTime;
    
    UPROPERTY(EditAnywhere)
    float PriorityForceSwitchThreshold;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDICoreUtilityAITargetEntry CachedTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Timer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bChangedTarget;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<AActor>> IgnoredTargets;
    
    FSDICoreUtilityAITarget();
};

