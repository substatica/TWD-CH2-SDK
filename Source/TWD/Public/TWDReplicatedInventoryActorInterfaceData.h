#pragma once
#include "CoreMinimal.h"
#include "TWDReplicatedInventoryActorInterfaceData.generated.h"

USTRUCT(BlueprintType)
struct FTWDReplicatedInventoryActorInterfaceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    uint8 RepInventorySlotIdx;
    
    TWD_API FTWDReplicatedInventoryActorInterfaceData();
};

