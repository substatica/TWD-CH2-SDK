#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SDIStimAndResponseInterfaceDataContainer.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct SDISTIMANDRESPONSEPLUGIN_API FSDIStimAndResponseInterfaceDataContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FGameplayTagContainer StimulusFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StimulusTickInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStartStimulusTickWhenStimulated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStopStimulusTickWhenNotStimulated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUpdateStimuliOnTick;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    TArray<UPrimitiveComponent*> OnOverlapComponents;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FGameplayTagContainer LastReplicatedStimuli;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FGameplayTagContainer LatentUpdateStimuli;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LastTickTimeStamp;
    
    FSDIStimAndResponseInterfaceDataContainer();
};

