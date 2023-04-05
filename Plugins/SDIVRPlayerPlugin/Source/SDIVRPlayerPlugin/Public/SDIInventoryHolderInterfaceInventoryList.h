#pragma once
#include "CoreMinimal.h"
#include "SDIInventoryHolderInterfaceInventoryListEntry.h"
#include "SDIInventoryHolderInterfaceInventoryList.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIInventoryHolderInterfaceInventoryList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIInventoryHolderInterfaceInventoryListEntry> Inventory;
    
    FSDIInventoryHolderInterfaceInventoryList();
};

