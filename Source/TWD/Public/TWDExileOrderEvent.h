#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDSpawnEvent.h"
#include "TWDExileOrderEventAssociatedActors.h"
#include "TWDExileOrderEvent.generated.h"

class UObject;
class UDataTable;
class UTWDExileOrder;
class ASDIInventoryActor;

UCLASS()
class TWD_API UTWDExileOrderEvent : public UTWDSpawnEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    bool bDeliveryComplete;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    bool bRewardClaimed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDExileOrderEventAssociatedActors AssociatedActors;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    UDataTable* OrderClassTable;
    
    UPROPERTY(EditDefaultsOnly)
    TSoftClassPtr<UTWDExileOrder> OrderClassOverride;
    
private:
    UPROPERTY(Transient)
    TSubclassOf<UTWDExileOrder> AssignedOrderClass;
    
public:
    UTWDExileOrderEvent();
    UFUNCTION(BlueprintPure)
    bool IsOrderSatisfiedByHolder(UObject* RequirementHolder) const;
    
    UFUNCTION(BlueprintPure)
    bool IsAssigned() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<UTWDExileOrder> GetOrderClass() const;
    
    UFUNCTION(BlueprintCallable)
    bool DebugTakeRequirements(UObject* FromRequirementHolder);
    
    UFUNCTION(BlueprintCallable)
    void DebugHandleOrderExchange(UObject* FromRequirementHolder, UObject* ToRewardHolder, bool& bSuccess, TArray<ASDIInventoryActor*>& RewardedInv);
    
    UFUNCTION(BlueprintCallable)
    TArray<ASDIInventoryActor*> DebugGiveRewards(UObject* ToRewardHolder);
    
};

