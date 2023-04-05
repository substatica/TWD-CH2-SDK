#pragma once
#include "CoreMinimal.h"
#include "RInt.h"
#include "QIntExpMulti.h"
#include "SpawnerTriggerEvent.generated.h"

USTRUCT(BlueprintType)
struct FSpawnerTriggerEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bSpawnAll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 Count;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUseRandomCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FQIntExpMulti RandomCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bSpecifyTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRInt Tier;
    
    SDICOREPLUGIN_API FSpawnerTriggerEvent();
};

