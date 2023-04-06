#pragma once
#include "CoreMinimal.h"
#include "SDIActorSpawnerNetwork.h"
#include "QIntExpMulti.h"
#include "TWDNightModeLootSpawnerNetwork.generated.h"

UCLASS()
class TWD_API ATWDNightModeLootSpawnerNetwork : public ASDIActorSpawnerNetwork {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FQIntExpMulti RareSpawnCount;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RareSpawnersActivated;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<UClass*> SkinTemplates;
    
public:
    ATWDNightModeLootSpawnerNetwork(const FObjectInitializer& ObjectInitializer);
};

