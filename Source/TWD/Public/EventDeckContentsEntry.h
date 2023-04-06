#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataTable.h"
#include "EventDeckContentsEntry.generated.h"

class UTWDWorldEvent;

USTRUCT(BlueprintType)
struct TWD_API FEventDeckContentsEntry : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<UTWDWorldEvent> EventClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bActive;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StartingValue;
    
    UPROPERTY()
    float CurrentValue;
    
    FEventDeckContentsEntry();
};

