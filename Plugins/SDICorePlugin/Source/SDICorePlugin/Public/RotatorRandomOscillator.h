#pragma once
#include "CoreMinimal.h"
#include "FloatRandomOscillator.h"
#include "RotatorRandomOscillator.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FRotatorRandomOscillator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRandomOscillator Pitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRandomOscillator Yaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRandomOscillator Roll;
    
    FRotatorRandomOscillator();
};

