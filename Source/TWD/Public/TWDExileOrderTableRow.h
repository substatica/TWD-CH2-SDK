#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDExileOrderTableRow.generated.h"

class UTWDExileOrder;

USTRUCT(BlueprintType)
struct FTWDExileOrderTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSoftClassPtr<UTWDExileOrder> OrderClass;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TMap<int32, float> WeightByGlobalFavorTier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TMap<int32, float> WeightByLocalFavorTier;
    
    TWD_API FTWDExileOrderTableRow();
};

