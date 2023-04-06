#pragma once
#include "CoreMinimal.h"
#include "LevelScenerioData.generated.h"

class UDataTable;

USTRUCT(BlueprintType)
struct TWD_API FLevelScenerioData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UDataTable* ScenarioCommandTable;
    
    FLevelScenerioData();
};

