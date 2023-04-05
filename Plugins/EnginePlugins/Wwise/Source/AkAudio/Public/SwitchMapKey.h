#pragma once
#include "CoreMinimal.h"
#include "SwitchMapKey.generated.h"

class UAkSwitchValue;

USTRUCT(BlueprintType)
struct FSwitchMapKey {
    GENERATED_BODY()
public:
    UPROPERTY()
    UAkSwitchValue* SwitchValue;
    
    UPROPERTY()
    FString SwitchGroup;
    
    AKAUDIO_API FSwitchMapKey();
};

