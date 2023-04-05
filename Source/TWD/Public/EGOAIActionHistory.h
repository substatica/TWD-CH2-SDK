#pragma once
#include "CoreMinimal.h"
#include "EEGOAIActionTypes.h"
#include "EGOAIActionHistoryItem.h"
#include "EGOAIActionHistory.generated.h"

USTRUCT(BlueprintType)
struct FEGOAIActionHistory {
    GENERATED_BODY()
public:
    UPROPERTY()
    TMap<EEGOAIActionTypes, FEGOAIActionHistoryItem> ActionHistoryList;
    
    TWD_API FEGOAIActionHistory();
};

