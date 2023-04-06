#pragma once
#include "CoreMinimal.h"
#include "TWDEstimatedLevelLoadingTime.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDEstimatedLevelLoadingTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditDefaultsOnly)
    FString Map;
    
    UPROPERTY(BlueprintReadWrite, Config, EditDefaultsOnly)
    float Time;
    
    FTWDEstimatedLevelLoadingTime();
};

