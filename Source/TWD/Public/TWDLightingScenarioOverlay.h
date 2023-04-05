#pragma once
#include "CoreMinimal.h"
#include "PerPlatformString.h"
#include "TWDLightingScenarioOverlay.generated.h"

USTRUCT(BlueprintType)
struct FTWDLightingScenarioOverlay {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FPerPlatformString> NightLevels;
    
    UPROPERTY(EditAnywhere)
    TArray<FPerPlatformString> DayLevels;
    
    TWD_API FTWDLightingScenarioOverlay();
};

