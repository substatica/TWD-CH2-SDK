#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIRandomSkinParamSetEntry.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDIRandomSkinParamSetEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FLinearColor> Colors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, TSoftObjectPtr<UTexture>> Textures;
    
    FSDIRandomSkinParamSetEntry();
};

