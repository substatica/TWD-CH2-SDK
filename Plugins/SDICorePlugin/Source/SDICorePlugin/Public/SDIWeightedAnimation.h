#pragma once
#include "CoreMinimal.h"
#include "SDIWeightedAnimation.generated.h"

class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIWeightedAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAnimSequenceBase* AnimSequence;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float AnimSequencePlayRate;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bUsesRootMotion;
    
    UPROPERTY(EditDefaultsOnly)
    float Weight;
    
protected:
    UPROPERTY(Transient)
    float CurrentWeight;
    
public:
    FSDIWeightedAnimation();
};

