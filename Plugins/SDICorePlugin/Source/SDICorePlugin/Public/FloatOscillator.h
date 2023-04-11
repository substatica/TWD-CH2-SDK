#pragma once
#include "CoreMinimal.h"
#include "QFloatExp.h"
#include "RFloatExp.h"
#include "QIntExp.h"
#include "FloatOscillator.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FFloatOscillator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 Cycles;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CurrentCycle;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Current;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FQFloatExp Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloatExp Amplitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FQIntExp ResetFrequencyCycles;
    
    FFloatOscillator();
};

