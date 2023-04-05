#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TWDSavedItemData.h"
#include "TWDPersistentLevelItemData.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDPersistentLevelItemData : public FTWDSavedItemData {
    GENERATED_BODY()
public:
    UPROPERTY()
    FTransform ItemTransform;
    
    FTWDPersistentLevelItemData();
};

