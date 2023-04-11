#pragma once
#include "CoreMinimal.h"
#include "SDIAssetLookupTable_Number.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAssetLookupTable_Number {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName Key;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float Number;
    
    FSDIAssetLookupTable_Number();
};

