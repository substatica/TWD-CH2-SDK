#pragma once
#include "CoreMinimal.h"
#include "SDISkinSelection.h"
#include "SDISkinParamSelections.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinParamSelections {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 CustomizationStartIndex;
    
    UPROPERTY(BlueprintReadWrite)
    int32 Count;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FSDISkinSelection> ScalarParamSelections;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FSDISkinSelection> ColorParamSelections;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FSDISkinSelection> TextureParamSelections;
    
    UPROPERTY(BlueprintReadWrite)
    TMap<FName, FSDISkinSelection> ParamSetSelections;
    
    FSDISkinParamSelections();
};

