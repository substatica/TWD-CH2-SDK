#pragma once
#include "CoreMinimal.h"
#include "TWDInventorySlotGrid.h"
#include "TWDInventoryHolderActor.h"
#include "TWDExileOrderBox.generated.h"

class ATWDPlayerInventorySlot;
class USceneComponent;
class UTWDExileOrderEvent;
class ASDIInventoryActor;
class ASDIInventorySlot;

UCLASS()
class TWD_API ATWDExileOrderBox : public ATWDInventoryHolderActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenStateChangedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLockedStateChangedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContentChangedDelegate);
    
    UPROPERTY(BlueprintAssignable)
    FOnContentChangedDelegate OnBoxContentChanged;
    
    UPROPERTY(BlueprintAssignable)
    FOnOpenStateChangedDelegate OnBoxOpenStateChanged;
    
    UPROPERTY(BlueprintAssignable)
    FOnLockedStateChangedDelegate OnBoxLockedStateChanged;
    
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* InventorySlotRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDInventorySlotGrid InventorySlotGrid;
    
    UPROPERTY(BlueprintReadOnly)
    UTWDExileOrderEvent* AssociatedExileOrderEvent;
    
    UPROPERTY(BlueprintReadOnly)
    bool bBoxOpen;
    
    UPROPERTY(BlueprintReadOnly)
    bool bBoxLocked;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bStartLocked;
    
public:
    ATWDExileOrderBox(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool TryLateAssignExileOrderEvent();
    
    UFUNCTION(BlueprintCallable)
    bool SetBoxOpenState(bool bNewOpen, bool& bStateChanged);
    
    UFUNCTION(BlueprintCallable)
    bool SetBoxLockedState(bool bNewLocked, bool& bStateChanged);
    
    UFUNCTION()
    void OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory);
    
    UFUNCTION(BlueprintCallable)
    ASDIInventorySlot* FindEmptyInventorySlot(ASDIInventoryActor* InventoryActor, bool bShuffle);
    
    UFUNCTION(BlueprintCallable)
    bool AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bShuffle, bool bForceCheckOnlyDontPlace);
    
};

