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
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bMagicSlotsEnabled;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TArray<ATWDPlayerInventorySlot*> MagicSlots;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ATWDPlayerInventorySlot> MagicSlotClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced)
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

