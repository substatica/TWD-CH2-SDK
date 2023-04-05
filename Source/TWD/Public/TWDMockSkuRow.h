#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ETWDMockSkuGranting.h"
#include "TWDMockSkuRow.generated.h"

USTRUCT(BlueprintType)
struct FTWDMockSkuRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDMockSkuGranting Operation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName SkuFriendlyName;
    
    TWD_API FTWDMockSkuRow();
};

