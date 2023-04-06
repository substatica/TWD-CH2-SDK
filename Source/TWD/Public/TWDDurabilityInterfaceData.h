#pragma once
#include "CoreMinimal.h"
#include "RFloatExp.h"
#include "TWDDurabilityInterfaceData.generated.h"

USTRUCT(BlueprintType)
struct FTWDDurabilityInterfaceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxDurability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloatExp InitialDurability;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LocalDurability;
    
    TWD_API FTWDDurabilityInterfaceData();
};

