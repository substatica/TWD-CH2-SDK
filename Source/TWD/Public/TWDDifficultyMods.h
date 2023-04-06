#pragma once
#include "CoreMinimal.h"
#include "RFloat.h"
#include "TWDDifficultyMods.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDDifficultyMods {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DayPercentageAdded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloat DayPercentageRange;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HealthLossMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StaminaLossMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DurabilityLossMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float BellsTimerAddedSeconds;
    
    FTWDDifficultyMods();
};

