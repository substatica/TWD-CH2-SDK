#pragma once
#include "CoreMinimal.h"
#include "SDIAssetLookupTable_Text.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAssetLookupTable_Text {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName Key;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FText Text;
    
    FSDIAssetLookupTable_Text();
};

