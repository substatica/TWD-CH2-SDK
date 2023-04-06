#pragma once
#include "CoreMinimal.h"
#include "EMapTerritoryNodeStatus.h"
#include "EMapTerritoryNodeType.h"
#include "MapTerritoryAttribute.h"
#include "EMapBiomeType.h"
#include "MapTerritoryNode.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FMapTerritoryNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EMapTerritoryNodeType Type;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EMapBiomeType Biome;
    
    UPROPERTY(BlueprintReadWrite)
    EMapTerritoryNodeStatus Status;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FMapTerritoryAttribute> Attributes;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<int32> Connections;
    
    FMapTerritoryNode();
};

