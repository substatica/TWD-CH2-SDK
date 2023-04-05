#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SDIReplicatedStimAndResponseInterfaceDataContainer.generated.h"

USTRUCT(BlueprintType)
struct SDISTIMANDRESPONSEPLUGIN_API FSDIReplicatedStimAndResponseInterfaceDataContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FGameplayTagContainer Stimuli;
    
    FSDIReplicatedStimAndResponseInterfaceDataContainer();
};

