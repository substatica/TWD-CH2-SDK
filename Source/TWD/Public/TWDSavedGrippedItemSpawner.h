#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputCoreTypes.h"
#include "TWDSavedGrippedItemSpawner.generated.h"

class ASDIInventoryActor;

UCLASS()
class TWD_API ATWDSavedGrippedItemSpawner : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EControllerHand GripHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bDisableGravity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSoftClassPtr<ASDIInventoryActor>> ProhibitedItems;
    
public:
    ATWDSavedGrippedItemSpawner(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    void SpawnSavedItem();
    
};

