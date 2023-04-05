#pragma once
#include "CoreMinimal.h"
#include "TWDGameProgressionChapterProperties.generated.h"

class UTWDMapManager;
class UTWDScenarioManager;

USTRUCT(BlueprintType)
struct FTWDGameProgressionChapterProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSoftClassPtr<UTWDMapManager> MapManagerClass;
    
    UPROPERTY(EditDefaultsOnly)
    TSoftClassPtr<UTWDScenarioManager> ScenarioManagerClass;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 DayCountOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 BalancedGameLength;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 TotalStoryEvents;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StoryEventWeight;
    
    TWD_API FTWDGameProgressionChapterProperties();
};

