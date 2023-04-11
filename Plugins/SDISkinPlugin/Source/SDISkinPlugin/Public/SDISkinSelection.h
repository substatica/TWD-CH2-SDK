#pragma once
#include "CoreMinimal.h"
#include "SDISkinSelection.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinSelection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 CustomizationIndex;
    
    UPROPERTY(BlueprintReadWrite)
    int32 ArrayIndex;
    
    FSDISkinSelection();
};

