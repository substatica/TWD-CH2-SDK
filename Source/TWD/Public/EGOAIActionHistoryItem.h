#pragma once
#include "CoreMinimal.h"
#include "ActionScore.h"
#include "EGOAIActionHistoryItem.generated.h"

USTRUCT(BlueprintType)
struct FEGOAIActionHistoryItem {
    GENERATED_BODY()
public:
    UPROPERTY()
    float Timestamp;
    
    UPROPERTY()
    FActionScore ActionScore;
    
    TWD_API FEGOAIActionHistoryItem();
};

