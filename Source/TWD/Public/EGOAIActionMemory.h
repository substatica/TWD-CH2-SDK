#pragma once
#include "CoreMinimal.h"
#include "ActionScore.h"
#include "EGOAIActionMemory.generated.h"

USTRUCT(BlueprintType)
struct FEGOAIActionMemory {
    GENERATED_BODY()
public:
    UPROPERTY()
    bool bHasMemory;
    
    UPROPERTY()
    FActionScore ActionMemory;
    
    TWD_API FEGOAIActionMemory();
};

