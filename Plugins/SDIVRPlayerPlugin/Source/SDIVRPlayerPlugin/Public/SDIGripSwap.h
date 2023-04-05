#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDIGripSwap.generated.h"

class UHapticFeedbackEffect_Base;
class UAkAudioEvent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIGripSwap {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference CurrentGripRef;
    
    UPROPERTY(EditDefaultsOnly)
    FComponentReference TargetGripRef;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* GripSwapSound;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* GripSwapFeedback;
    
public:
    FSDIGripSwap();
};

