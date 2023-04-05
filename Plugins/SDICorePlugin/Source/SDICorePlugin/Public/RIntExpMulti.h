#pragma once
#include "CoreMinimal.h"
#include "RIntExp.h"
#include "RIntExpMulti.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FRIntExpMulti : public FRIntExp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float NumSamples;
    
    FRIntExpMulti();
};

