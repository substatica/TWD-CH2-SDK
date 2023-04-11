#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIAssetLookupTable_GuidReferences.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAssetLookupTable_GuidReferences {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FName Key;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FGuid> Guids;
    
    FSDIAssetLookupTable_GuidReferences();
};

