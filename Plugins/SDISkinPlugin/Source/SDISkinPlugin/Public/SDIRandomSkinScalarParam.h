#pragma once
#include "CoreMinimal.h"
#include "SDIRandomSkinScalarParam.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDIRandomSkinScalarParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<float> Values;
    
    FSDIRandomSkinScalarParam();
};

