#pragma once
#include "CoreMinimal.h"
#include "SDIBlendOption.h"
#include "SDIBlendAnimation.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIBlendAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption Blend;
    
    UPROPERTY(Transient)
    float Time;
    
    FSDIBlendAnimation();
};

