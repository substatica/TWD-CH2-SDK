#pragma once
#include "CoreMinimal.h"
#include "FloatRandomOscillator.h"
#include "VectorRandomOscillator.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FVectorRandomOscillator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRandomOscillator X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRandomOscillator Y;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRandomOscillator Z;
    
    FVectorRandomOscillator();
};

