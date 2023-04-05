#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDRuleTableExclusion.generated.h"

class UDataTable;

USTRUCT(BlueprintType)
struct FTWDRuleTableExclusion {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UDataTable* RuleDataTable;
    
    UPROPERTY(EditAnywhere)
    TArray<FDataTableRowHandle> ExcludedRowHandles;
    
    TWD_API FTWDRuleTableExclusion();
};

