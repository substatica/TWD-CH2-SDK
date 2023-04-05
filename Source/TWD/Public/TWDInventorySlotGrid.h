#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDInventorySlotGrid.generated.h"

class ATWDPlayerInventorySlot;

USTRUCT(BlueprintType)
struct TWD_API FTWDInventorySlotGrid {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ATWDPlayerInventorySlot> InventorySlotBlueprint;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FIntVector SlotCount;
    
    UPROPERTY(EditDefaultsOnly)
    FVector2D SlotSpacing;
    
    UPROPERTY(BlueprintReadOnly)
    TArray<ATWDPlayerInventorySlot*> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<ATWDPlayerInventorySlot*> BlueprintCreatedSlots;
    
    FTWDInventorySlotGrid();
};

