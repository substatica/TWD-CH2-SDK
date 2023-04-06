#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "ETWDNonVRInteraction.h"
#include "TWDNonVRInteractionPrompt.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDNonVRInteractionPrompt {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    ETWDNonVRInteraction Command;
    
    UPROPERTY(BlueprintReadWrite)
    FKey InputKey;
    
    UPROPERTY(BlueprintReadWrite)
    bool bCanBeLongPressed;
    
    FTWDNonVRInteractionPrompt();
};

