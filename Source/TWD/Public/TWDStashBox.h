#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "TWDInventoryHolderActor.h"
#include "TWDStashPage.h"
#include "UObject/NoExportTypes.h"
#include "TWDStashBox.generated.h"

class UBoxComponent;
class ASDIInventoryActor;
class USceneComponent;
class ATWDPlayerInventorySlot;
class ASDIInventorySlot;

UCLASS()
class TWD_API ATWDStashBox : public ATWDInventoryHolderActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    int32 ActivePageIndex;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    int32 AvailablePages;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ATWDPlayerInventorySlot> InventorySlotBlueprint;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* InventorySlotRoot;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* InventoryUIRoot;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FIntVector InventorySlotCount;
    
    UPROPERTY(EditDefaultsOnly)
    FVector2D InventorySlotSpacing;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float InventorySlotRadius;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TArray<FTWDStashPage> InventoryPages;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* NextPageCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* PrevPageCollision;
    
    UPROPERTY(EditDefaultsOnly)
    bool bEnableAutoAdvance;
    
    UPROPERTY(EditDefaultsOnly)
    float AutoAdvanceCheckDelay;
    
public:
    ATWDStashBox(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TransferFromPlayerInventory();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStashContentChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPageFlip(int32 PrevPageIndex, int32 CurrentPageIndex);
    
    UFUNCTION()
    void OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory);
    
    UFUNCTION(BlueprintCallable)
    void GoToPrevPage();
    
    UFUNCTION(BlueprintCallable)
    void GoToPage(int32 PageIndex);
    
    UFUNCTION(BlueprintCallable)
    void GoToNextPage();
    
    UFUNCTION()
    ASDIInventorySlot* FindEmptyInventorySlot(ASDIInventoryActor* InventoryActor, int32& OutPage);
    
private:
    UFUNCTION()
    void CheckForPageAutoAdvance();
    
public:
    UFUNCTION(BlueprintCallable)
    bool AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bForceCheckOnlyDontPlace);
    
};

