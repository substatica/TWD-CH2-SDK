#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "SDILoopingHapticEffect.generated.h"

class UHapticFeedbackEffect_Base;
class ASDIPlayerController;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDILoopingHapticEffect {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    UHapticFeedbackEffect_Base* Effect;
    
    UPROPERTY(Transient)
    float Scale;
    
    UPROPERTY(Transient)
    float FrequencyScale;
    
    UPROPERTY(Transient)
    float PlaybackSpeed;
    
    UPROPERTY(Transient)
    int32 Priority;
    
    UPROPERTY(Transient)
    EControllerHand hand;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIPlayerController> WeakPC;
    
    UPROPERTY(Transient)
    int32 PlayingID;
    
    UPROPERTY(Transient)
    bool bSynchronized;
    
    FSDILoopingHapticEffect();
};

