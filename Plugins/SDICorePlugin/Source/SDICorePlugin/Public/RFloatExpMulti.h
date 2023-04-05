#pragma once
#include "CoreMinimal.h"
#include "RFloatExp.h"
#include "RFloatExpMulti.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FRFloatExpMulti : public FRFloatExp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float NumSamples;
    
    FRFloatExpMulti();
};

