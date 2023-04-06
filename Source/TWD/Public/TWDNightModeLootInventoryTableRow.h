#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDNightModeLootInventoryTableRow.generated.h"

class ASDIInventoryActor;

USTRUCT(BlueprintType)
struct FTWDNightModeLootInventoryTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftClassPtr<ASDIInventoryActor> LootInventoryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Weight;
    
    TWD_API FTWDNightModeLootInventoryTableRow();
};

