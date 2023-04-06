#pragma once
#include "CoreMinimal.h"
#include "SDIInventorySlot.h"
#include "ETWDInventoryType.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ETWDPlayerCharacterTickInventory.h"
#include "InventorySlotContentChangedDelegate.h"
#include "ESlotType.h"
#include "ETWDInventorySlot.h"
#include "InputCoreTypes.h"
#include "TWDPlayerInventorySlot.generated.h"

class UMaterialInstanceDynamic;
class UCapsuleComponent;
class ATWDBackpack;
class ASDIPlayerHand;
class ASDIInventoryActor;
class ASDIHeldActor;
class UStaticMeshComponent;
class AActor;
class UMaterialInterface;

UCLASS()
class ATWDPlayerInventorySlot : public ASDIInventorySlot {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UCapsuleComponent* SlotCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDInventoryType InventoryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector InventoryReplacementDropOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIgnoreSlotScale;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUpdateVisualOnTick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bPlayInvalidNotificationOnOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FLinearColor UIIndicator_SlotFullColor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FLinearColor UIIndicator_DefaultColor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float UIIndicator_SlotFullOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float UIIndicator_HighlightOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float UIIndicator_DefaultOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDPlayerCharacterTickInventory InventorySlotTickGroup;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ATWDBackpack* BackpackOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<ETWDInventoryType> LimitTheseTypes;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UMaterialInstanceDynamic* UIIndicator;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<ASDIPlayerHand*> OverlappingHands;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIInventoryActor* PendingInventory;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bSlotFull;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bInvalidItem;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bValidItem;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHighlightValid;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bMeshHighlighted;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bInteractionHighlight;
    
public:
    UPROPERTY(BlueprintAssignable)
    FInventorySlotContentChanged OnCurrentInventoryChanged;
    
    UPROPERTY()
    ASDIHeldActor* LeftHeldActor;
    
    UPROPERTY()
    ASDIHeldActor* RightHeldActor;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIInventoryActor> PreviousInventory;
    
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* SlotMesh;
    
private:
    UPROPERTY(EditAnywhere)
    ESlotType SlotType;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ETWDInventorySlot::Type> slotIdx;
    
public:
    ATWDPlayerInventorySlot(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintPure)
    bool WasSlotRecentlyRendered(float Tolerance) const;
    
    UFUNCTION(BlueprintCallable)
    void UpdateVisual(bool bForceUpdate);
    
    UFUNCTION(BlueprintCallable)
    void UpdateValidState();
    
    UFUNCTION(BlueprintCallable)
    void UpdateMeshHighlighting(bool bForceUpdate);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMeshColors();
    
    UFUNCTION(BlueprintCallable)
    void SetSlotHighlightActive(bool bActive);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotActive(bool bActive);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnUpdateValidState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMeshHighlightedChanged();
    
    UFUNCTION()
    void OnHeldActorGrabbed(ASDIHeldActor* HeldActor, AActor* GrabbedBy, EControllerHand hand, ASDIPlayerHand* PlayerHand);
    
    UFUNCTION()
    void OnHeldActorDropped(ASDIHeldActor* HeldActor, AActor* GrabbedBy, EControllerHand hand, ASDIPlayerHand* PlayerHand);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnHeldActorChanged(bool bValidHeldActorExists, ASDIHeldActor* LeftHandHeldActor, ASDIHeldActor* RightHandHeldActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsValidInventory(ASDIInventoryActor* Inventory);
    
    UFUNCTION(BlueprintPure)
    bool IsActiveInventorySlot() const;
    
    UFUNCTION(BlueprintPure)
    bool InventoryTypeAllowed(ASDIInventoryActor* Inv) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UMaterialInterface* GetSheathedInventoryMaterial(ASDIInventoryActor* InvActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void EnableSlot(bool bEnable) const;
    
};

