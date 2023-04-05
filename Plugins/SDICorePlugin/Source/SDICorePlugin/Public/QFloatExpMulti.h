#pragma once
#include "CoreMinimal.h"
#include "QFloatExp.h"
#include "QFloatExpMulti.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FQFloatExpMulti : public FQFloatExp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float NumSamples;
    
    FQFloatExpMulti();
};

