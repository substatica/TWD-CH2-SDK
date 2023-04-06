#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDWorldEvent.h"
#include "SpawnTagCommand.h"
#include "TWDSpawnEvent.generated.h"

class ASDIInventoryActor;

UCLASS()
class TWD_API UTWDSpawnEvent : public UTWDWorldEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bOverrideSingleCommands;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bOverrideAllCommands;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCheckInventoryToAutoComplete;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSubclassOf<ASDIInventoryActor>> InventoryToCheck;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSpawnTagCommand> SpawnCommands;
    
    UTWDSpawnEvent();
};

