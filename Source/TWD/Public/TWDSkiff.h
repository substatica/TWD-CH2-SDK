#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDInventoryHolderActor.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDSkiff.generated.h"

class UStaticMeshComponent;
class UShapeComponent;
class USceneComponent;
class ATWDPlayerInventorySlot;
class UPrimitiveComponent;
class AActor;
class ASDIInventoryActor;

UCLASS()
class TWD_API ATWDSkiff : public ATWDInventoryHolderActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bMagicSlotsEnabled;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    TArray<ATWDPlayerInventorySlot*> MagicSlots;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TSubclassOf<ATWDPlayerInventorySlot> MagicSlotClass;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Instanced)
    USceneComponent* MagicSlotRoot;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector MagicSlotSpacing;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MagicSlotRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced)
    UShapeComponent* InventorySwapVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName PlayerStartTag;
    
public:
    ATWDSkiff(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    void OnReadyForPlay();
    
    UFUNCTION()
    void OnInventorySwapVolumeTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory);
    
    UFUNCTION()
    void LoadSlotContents();
    
public:
    UFUNCTION()
    FName GetPlayerStartTag() const;
    
protected:
    UFUNCTION()
    void ActivateMagicSlots();
    
};

