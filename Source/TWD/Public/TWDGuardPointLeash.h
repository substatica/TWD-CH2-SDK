#pragma once
#include "CoreMinimal.h"
#include "ECharacterReaction.h"
#include "TWDGuardPointLeash.generated.h"

class AVolume;

USTRUCT(BlueprintType)
struct FTWDGuardPointLeash {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<ECharacterReaction> ReactionKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<AVolume*> InclusionVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<AVolume*> ExclusionVolumes;
    
    TWD_API FTWDGuardPointLeash();
};

