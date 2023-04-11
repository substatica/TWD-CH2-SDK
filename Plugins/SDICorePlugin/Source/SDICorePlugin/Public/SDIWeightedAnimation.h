#pragma once
#include "CoreMinimal.h"
#include "SDIWeightedAnimation.generated.h"

class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIWeightedAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAnimSequenceBase* AnimSequence;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AnimSequencePlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUsesRootMotion;
    
    UPROPERTY(EditDefaultsOnly)
    float Weight;
    
protected:
    UPROPERTY(Transient)
    float CurrentWeight;
    
public:
    FSDIWeightedAnimation();
};

