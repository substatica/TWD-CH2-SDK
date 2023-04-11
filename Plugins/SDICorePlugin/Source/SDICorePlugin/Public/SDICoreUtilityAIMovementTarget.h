#pragma once
#include "CoreMinimal.h"
#include "SDICoreUtilityAITargetEntry.h"
#include "SDICoreUtilityAIMovementTarget.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICoreUtilityAIMovementTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDICoreUtilityAITargetEntry Target;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bChangedTarget;
    
    FSDICoreUtilityAIMovementTarget();
};

