#pragma once
#include "CoreMinimal.h"
#include "TWDStashPage.generated.h"

class ATWDPlayerInventorySlot;

USTRUCT(BlueprintType)
struct FTWDStashPage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    TArray<ATWDPlayerInventorySlot*> InventorySlots;
    
    TWD_API FTWDStashPage();
};

