#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "TWDInventoryHolderActor.h"
#include "TWDStashPage.h"
#include "UObject/NoExportTypes.h"
#include "TWDStash.generated.h"

class UBoxComponent;
class ASDIInventoryActor;
class USceneComponent;
class ATWDPlayerInventorySlot;
class AActor;
class ASDIInventorySlot;

UCLASS()
class TWD_API ATWDStash : public ATWDInventoryHolderActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ATWDPlayerInventorySlot> InventorySlotBlueprint;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* InventorySlotRoot;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FIntVector InventorySlotCount;
    
    UPROPERTY(EditDefaultsOnly)
    FVector2D InventorySlotSpacing;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float InventorySlotRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bCanSaveContents;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TArray<FTWDStashPage> InventoryPages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<ATWDPlayerInventorySlot*> BlueprintCreatedSlots;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TArray<TSubclassOf<ASDIInventoryActor>> SalvageMaterialClasses;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    int32 ActivePageIndex;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    int32 AvailablePages;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* NextPageCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* PrevPageCollision;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USceneComponent* InventoryWallRoot;
    
public:
    ATWDStash(const FObjectInitializer& ObjectInitializer);
    UFUNCTION()
    void SaveStashToProgression();
    
    UFUNCTION(BlueprintCallable)
    void SalvageItem(AActor* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStashContentChanged();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnSalvageMaterialAdded(UClass* SalvageMatClass, const FText& SalvageMatName, int32 SalvageMatCount);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPageFlip(int32 PrevPageIndex, int32 CurrentPageIndex);
    
    UFUNCTION()
    void OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory);
    
    UFUNCTION()
    void LoadStashFromProgression();
    
    UFUNCTION(BlueprintCallable)
    void InitStolenStashSequence();
    
    UFUNCTION(BlueprintCallable)
    void GoToPrevPage();
    
    UFUNCTION(BlueprintCallable)
    void GoToPage(int32 PageIndex);
    
    UFUNCTION(BlueprintCallable)
    void GoToNextPage();
    
    UFUNCTION(BlueprintPure)
    ATWDPlayerInventorySlot* GetInventorySlotByIdx(uint8 slotIdx) const;
    
    UFUNCTION(BlueprintPure)
    TArray<ATWDPlayerInventorySlot*> GetAllStashInventory() const;
    
    UFUNCTION()
    ASDIInventorySlot* FindEmptyInventorySlot(ASDIInventoryActor* InventoryActor, int32& OutPage);
    
    UFUNCTION(BlueprintPure)
    bool CanSaveContents() const;
    
    UFUNCTION(BlueprintPure)
    bool CanSalvage(const AActor* Item) const;
    
    UFUNCTION(BlueprintCallable)
    bool AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bForceCheckOnlyDontPlace);
    
};

