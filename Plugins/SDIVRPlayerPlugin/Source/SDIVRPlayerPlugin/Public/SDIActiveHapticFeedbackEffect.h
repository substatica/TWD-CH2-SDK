#pragma once
#include "CoreMinimal.h"
#include "SDIActiveHapticFeedbackEffect.generated.h"

class UObject;

USTRUCT()
struct SDIVRPLAYERPLUGIN_API FSDIActiveHapticFeedbackEffect {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    UObject* HapticEffect;
    
    UPROPERTY(Transient)
    bool bLoop;
    
    UPROPERTY(Transient)
    float PlayTime;
    
    UPROPERTY(Transient)
    float Scale;
    
    UPROPERTY(Transient)
    float FrequencyScale;
    
    UPROPERTY(Transient)
    float PlaybackSpeed;
    
    FSDIActiveHapticFeedbackEffect();
};

