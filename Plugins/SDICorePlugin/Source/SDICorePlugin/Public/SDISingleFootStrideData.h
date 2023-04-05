#pragma once
#include "CoreMinimal.h"
#include "SDIStrideDataFootCycleDefinition.h"
#include "SDIStrideDataFootBaseTrajectory.h"
#include "SDISingleFootStrideData.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDISingleFootStrideData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIStrideDataFootCycleDefinition> FootCycleDef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIStrideDataFootBaseTrajectory> FootTrajectory;
    
    FSDISingleFootStrideData();
};

