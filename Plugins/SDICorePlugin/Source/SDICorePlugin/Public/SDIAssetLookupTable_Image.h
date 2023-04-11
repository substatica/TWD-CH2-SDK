#pragma once
#include "CoreMinimal.h"
#include "SDIAssetLookupTable_Image.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAssetLookupTable_Image {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName Key;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSoftObjectPtr<UTexture2D> Image;
    
    FSDIAssetLookupTable_Image();
};

