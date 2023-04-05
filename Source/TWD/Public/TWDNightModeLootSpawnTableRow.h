#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDNightModeLootSpawnTableRow.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FTWDNightModeLootSpawnTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSoftClassPtr<AActor> SpawnClass;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float Weight;
    
    TWD_API FTWDNightModeLootSpawnTableRow();
};

