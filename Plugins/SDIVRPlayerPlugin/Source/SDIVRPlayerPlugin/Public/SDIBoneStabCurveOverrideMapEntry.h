#pragma once
#include "CoreMinimal.h"
#include "SDIBoneStabCurveOverrideMapEntry.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIBoneStabCurveOverrideMapEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIncludeChildren;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* Curve;
    
    FSDIBoneStabCurveOverrideMapEntry();
};

