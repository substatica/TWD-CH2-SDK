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
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* SlotRoot;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UCapsuleComponent* SlotCollision;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* SlotMesh;
    
private:
    UPROPERTY(Transient)
    TArray<FTWDRequiredInventory> RequiredInventory;
    
    UPROPERTY(Transient)
    bool bEnabled;
    
public:
    ATWDCharacterHandSlot();
};

