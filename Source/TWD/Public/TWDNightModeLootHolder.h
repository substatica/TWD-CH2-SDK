#pragma once
#include "CoreMinimal.h"
#include "TWDInventorySlotGrid.h"
#include "TWDInventoryHolderActor.h"
#include "QIntExpMulti.h"
#include "TWDNightModeLootHolder.generated.h"

class ATWDPlayerInventorySlot;
class USceneComponent;
class ASDIInventoryActor;
class UDataTable;

UCLASS()
class TWD_API ATWDNightModeLootHolder : public ATWDInventoryHolderActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContentChangedDelegate, ASDIInventoryActor*, NewInventory);
    
    UPROPERTY(BlueprintAssignable)
    FOnContentChangedDelegate OnContentChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* InventorySlotRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDInventorySlotGrid InventorySlotGrid;
    
    UPROPERTY(EditDefaultsOnly)
    FQIntExpMulti LootInventoryCount;
    
    UPROPERTY(EditDefaultsOnly)
    UDataTable* LootInventoryTable;
    
public:
    ATWDNightModeLootHolder(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void SetSlotsVisible(bool NewVisible);
    
public:
    UFUNCTION()
    void OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* NewInventory);
    
};

