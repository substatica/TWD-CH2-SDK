#pragma once
#include "CoreMinimal.h"
#include "EMapTerritoryNodeType.h"
#include "MapBiomeTerritorySet.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FMapBiomeTerritorySet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSet<EMapTerritoryNodeType> TerritoryTypeSet;
    
    FMapBiomeTerritorySet();
};

