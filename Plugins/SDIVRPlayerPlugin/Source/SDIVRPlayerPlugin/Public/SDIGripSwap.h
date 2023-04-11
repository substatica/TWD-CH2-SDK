#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDIGripSwap.generated.h"

class UObject;
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
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* GripSwapSound;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* GripSwapFeedback;
    
public:
    FSDIGripSwap();
};

