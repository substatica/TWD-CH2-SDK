#pragma once
#include "CoreMinimal.h"
#include "TWDPlayerInventorySlot.h"
#include "TWDFlashlightSlot.generated.h"

UCLASS()
class TWD_API ATWDFlashlightSlot : public ATWDPlayerInventorySlot {
    GENERATED_BODY()
public:
    ATWDFlashlightSlot();
    UFUNCTION(BlueprintNativeEvent)
    void UpdateAvailability();
    
    UFUNCTION(BlueprintPure)
    bool IsHeadSlot() const;
    
};

