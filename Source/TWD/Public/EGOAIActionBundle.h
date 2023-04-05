#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGOAIAction.h"
#include "EGOAIActionBundle.generated.h"

USTRUCT(BlueprintType)
struct FEGOAIActionBundle : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Description;
    
    UPROPERTY(Transient)
    bool bEnable;
    
    UPROPERTY(Transient)
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FEGOAIAction> ActionList;
    
    TWD_API FEGOAIActionBundle();
};

