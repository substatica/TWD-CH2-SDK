#pragma once
#include "CoreMinimal.h"
#include "TWDInventorySlotGrid.h"
#include "TWDInventoryHolderActor.h"
#include "TWDPawnShopDrawer.generated.h"

class ASDIInventoryActor;
class ATWDPlayerInventorySlot;
class USceneComponent;

UCLASS()
class TWD_API ATWDPawnShopDrawer : public ATWDInventoryHolderActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* InventorySlotRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDInventorySlotGrid InventorySlotGrid;
    
public:
    ATWDPawnShopDrawer();
    UFUNCTION()
    void OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory);
    
    UFUNCTION(BlueprintCallable)
    bool AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bShuffle, bool bForceCheckOnlyDontPlace);
    
};

