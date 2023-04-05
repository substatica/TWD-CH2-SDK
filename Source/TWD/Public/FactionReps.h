#pragma once
#include "CoreMinimal.h"
#include "EFaction.h"
#include "FactionReps.generated.h"

USTRUCT(BlueprintType)
struct FFactionReps {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<EFaction, float> Reps;
    
    TWD_API FFactionReps();
};

