#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDNightModeLootInventoryTableRow.generated.h"

class ASDIInventoryActor;

USTRUCT(BlueprintType)
struct FTWDNightModeLootInventoryTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSoftClassPtr<ASDIInventoryActor> LootInventoryClass;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float Weight;
    
    TWD_API FTWDNightModeLootInventoryTableRow();
};

