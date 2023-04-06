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
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 DayCountOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 BalancedGameLength;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 TotalStoryEvents;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StoryEventWeight;
    
    TWD_API FTWDGameProgressionChapterProperties();
};

