#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDProductEntitlementsMap.generated.h"

USTRUCT(BlueprintType)
struct FTWDProductEntitlementsMap : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> EntitlementTableRows;
    
    TWD_API FTWDProductEntitlementsMap();
};

