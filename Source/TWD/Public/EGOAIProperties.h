#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGOAIActionBundle.h"
#include "EGOAIAction.h"
#include "Engine/DataTable.h"
#include "EGOAIProperties.generated.h"

USTRUCT(BlueprintType)
struct FEGOAIProperties : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FEGOAIAction> ActionList;
    
    UPROPERTY(Transient)
    TArray<FEGOAIActionBundle> ActionListBundles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FDataTableRowHandle> ActionListBundleHandleList;
    
    UPROPERTY(EditAnywhere)
    float PropertiesUpdateInterval;
    
    TWD_API FEGOAIProperties();
};

