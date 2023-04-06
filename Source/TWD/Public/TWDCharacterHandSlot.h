#pragma once
#include "CoreMinimal.h"
#include "SDIInventorySlot.h"
#include "TWDRequiredInventory.h"
#include "TWDCharacterHandSlot.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UCapsuleComponent;

UCLASS()
class ATWDCharacterHandSlot : public ASDIInventorySlot {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* SlotRoot;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UCapsuleComponent* SlotCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* SlotMesh;
    
private:
    UPROPERTY(Transient)
    TArray<FTWDRequiredInventory> RequiredInventory;
    
    UPROPERTY(Transient)
    bool bEnabled;
    
public:
    ATWDCharacterHandSlot(const FObjectInitializer& ObjectInitializer);
};

