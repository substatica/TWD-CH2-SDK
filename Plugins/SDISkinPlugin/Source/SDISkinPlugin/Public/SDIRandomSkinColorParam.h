#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIRandomSkinColorParam.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDIRandomSkinColorParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FLinearColor> Values;
    
    FSDIRandomSkinColorParam();
};

