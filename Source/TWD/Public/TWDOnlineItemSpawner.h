#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIActorSpawner.h"
#include "TWDUniqueEntitlementItemID.h"
#include "TWDOnlineItemSpawner.generated.h"

class AActor;

UCLASS()
class TWD_API ATWDOnlineItemSpawner : public ASDIActorSpawner {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDUniqueEntitlementItemID OnlineItemID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName OnlineEntitlementName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<AActor> ItemToSpawn;
    
public:
    ATWDOnlineItemSpawner(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    void SpawnActor();
    
};

