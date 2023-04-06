#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDWeaponActor.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDBackpackUIMeshElement.h"
#include "UObject/NoExportTypes.h"
#include "ESDIInteractiveInteractType.h"
#include "UObject/NoExportTypes.h"
#include "TWDBackpackPage.h"
#include "Engine/EngineTypes.h"
#include "ESDIInteractRangeType.h"
#include "EUIDirection.h"
#include "TWDBackpack.generated.h"

class UAkAudioEvent;
class UStaticMeshComponent;
class UChildActorComponent;
class ATWDPlayerInventorySlot;
class ASDIInventoryActor;
class UBoxComponent;
class USDIPointGripComponent;
class UTWDNonVRBackpackWidget;
class USceneComponent;
class UMaterialInstanceDynamic;
class ATWDBackpackInventorySlot;
class UPrimitiveComponent;
class ASDIPlayerHand;
class ATWDStash;
class ASDIInventorySlot;

UCLASS()
class TWD_API ATWDBackpack : public ATWDWeaponActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* BackpackMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* UIMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float SlotCollisionRadius;
    
    UPROPERTY(Transient)
    bool bDuringGrabAction;
    
    UPROPERTY(Transient)
    bool bIsGrabDelayed;
    
    UPROPERTY(Transient)
    FTimerHandle RepInsideInventoryDelayTimer;
    
    UPROPERTY(Transient)
    bool bDelayOldRepInsideInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioBagOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioBagClose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioItemRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioItemPlace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioItemRemoveSpecial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioItemPlaceSpecial;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    int32 AvailablePages;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    int32 ActivePageIndex;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* NextPageCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* PrevPageCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PointGripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PointGripRight;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TArray<ATWDPlayerInventorySlot*> InventorySlots;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TArray<ATWDPlayerInventorySlot*> LargeSlots;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* QuickSlotComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ATWDPlayerInventorySlot> InventorySlotBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ATWDPlayerInventorySlot> SpecialInventorySlotBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<UTWDNonVRBackpackWidget> NonVRBackpackWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSoftClassPtr<ASDIInventoryActor>> LowPriorityKeyItemClasses;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USceneComponent* InventorySlotRoot;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FIntVector InventorySlotCount;
    
    UPROPERTY(Transient)
    TArray<FTWDBackpackUIMeshElement> UIMeshElements;
    
    UPROPERTY(Transient)
    UMaterialInstanceDynamic* UIMeshMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly)
    int32 LeftArrowMeshElementIndex;
    
    UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly)
    int32 RightArrowMeshElementIndex;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FLinearColor ArrowMeshElementBaseColor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FLinearColor ArrowMeshElementHighlightedColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bNonVRInputActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 ActiveNonVRSlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 PrevNonVRSlotIndex;
    
private:
    UPROPERTY(EditDefaultsOnly)
    FVector2D InventorySlotSpacing;
    
    UPROPERTY()
    TArray<FTWDBackpackPage> InventoryPages;
    
    UPROPERTY()
    FTWDBackpackPage SpecialInventoryPage;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* QuickInventorySlot;
    
    UPROPERTY(Transient)
    bool bInsideOnRep_bRepInsideInventory;
    
    UPROPERTY(Transient)
    TMap<UPrimitiveComponent*, bool> PreviousVisibility;
    
    UPROPERTY(Transient)
    TMap<UPrimitiveComponent*, TEnumAsByte<ECollisionEnabled::Type>> PreviousCollision;
    
    UPROPERTY(Instanced, Transient)
    UTWDNonVRBackpackWidget* NonVRBackpackWidget;
    
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TSoftObjectPtr<ATWDStash> StashActor;
    
    ATWDBackpack(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    void UpdateSlotIndexForCurrentPage();
    
public:
    UFUNCTION(BlueprintCallable)
    void StopNonVRInteraction();
    
    UFUNCTION(BlueprintCallable)
    void StartNonVRInteraction();
    
    UFUNCTION(BlueprintPure)
    bool ShouldGrabInventoryInsteadOfInteract(ESDIInteractiveInteractType Type, ASDIPlayerHand* hand, ESDIInteractRangeType RangeType, UPrimitiveComponent* Component) const;
    
    UFUNCTION(BlueprintCallable)
    void SetUIMeshElementVisible(int32 MeshElementIndex, bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetUIMeshElementColor(int32 MeshElementIndex, const FLinearColor& Color);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotUIMeshElementVisible(ATWDBackpackInventorySlot* InvSlot, bool bVisible, bool bAuxVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetAvailablePages(int32 NewAvailablePages);
    
    UFUNCTION(BlueprintCallable)
    void RefreshBackpackSlots();
    
private:
    UFUNCTION()
    void QuickInventorySlotChanged(ATWDPlayerInventorySlot* InventorySlot, ASDIInventoryActor* CurrentInventory);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnShow();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPageFlip(int32 PrevPageIndex, int32 CurrentPageIndex);
    
    UFUNCTION()
    void OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBackpackContentChanged(ASDIInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAutoPlaceSpecialInventory(ASDIInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory, bool bShowHMDNotification);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAutoPlaceAmmo(ASDIInventoryActor* InventoryActor);
    
protected:
    UFUNCTION()
    void NonVRNavigate(EUIDirection Direction);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsUIMeshElementVisible(int32 MeshElementIndex) const;
    
    UFUNCTION(BlueprintPure)
    bool IsScrapEnabled() const;
    
protected:
    UFUNCTION()
    void InputNonVRScrap();
    
    UFUNCTION()
    void InputNonVRPageRight();
    
    UFUNCTION()
    void InputNonVRPageLeft();
    
    UFUNCTION()
    void InputNonVRNavUp();
    
    UFUNCTION()
    void InputNonVRNavRight();
    
    UFUNCTION()
    void InputNonVRNavLeft();
    
    UFUNCTION()
    void InputNonVRNavDown();
    
    UFUNCTION()
    void InputNonVRInteract();
    
    UFUNCTION()
    void InputNonVRDrop();
    
    UFUNCTION()
    void InputNonVRCancel();
    
    UFUNCTION()
    void InputNonVRBackpackButton();
    
public:
    UFUNCTION(BlueprintPure)
    bool HasUIMesh() const;
    
    UFUNCTION(BlueprintCallable)
    void GoToPrevPage();
    
    UFUNCTION(BlueprintCallable)
    void GoToPage(int32 PageIndex);
    
    UFUNCTION(BlueprintCallable)
    void GoToNextPage();
    
    UFUNCTION(BlueprintPure)
    FLinearColor GetUIMeshElementColor(int32 MeshElementIndex) const;
    
    UFUNCTION(BlueprintPure)
    ATWDPlayerInventorySlot* GetQuickSlot() const;
    
    UFUNCTION(BlueprintCallable)
    UTWDNonVRBackpackWidget* GetNonVRBackpackWidget();
    
    UFUNCTION(BlueprintPure)
    ATWDPlayerInventorySlot* GetInventorySlotByIdx(uint8 slotIdx) const;
    
    UFUNCTION(BlueprintPure)
    TArray<ASDIInventoryActor*> GetBackpackInventoryActors() const;
    
    UFUNCTION()
    ASDIInventorySlot* FindEmptyInventorySlot(ASDIInventoryActor* InventoryActor, int32& OutPage);
    
    UFUNCTION(BlueprintCallable)
    bool AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bForceCheckOnlyDontPlace, bool bDisableGotoPage);
    
    UFUNCTION(BlueprintCallable)
    void ActivateNonVRInteraction();
    
};

