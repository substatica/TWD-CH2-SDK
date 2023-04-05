#pragma once
#include "CoreMinimal.h"
#include "SDIBlendOption.h"
#include "SDIDotLerpFloatAdvanced.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIDotLerpFloatAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Reverse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Side;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Forward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ForwardRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ReverseRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SideRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption SideToReverseBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption SideToForwardBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAngularLerp;
    
    FSDIDotLerpFloatAdvanced();
};

