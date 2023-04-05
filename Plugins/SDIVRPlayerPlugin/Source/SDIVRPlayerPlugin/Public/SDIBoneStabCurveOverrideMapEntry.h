#pragma once
#include "CoreMinimal.h"
#include "SDIBoneStabCurveOverrideMapEntry.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIBoneStabCurveOverrideMapEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bIncludeChildren;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* Curve;
    
    FSDIBoneStabCurveOverrideMapEntry();
};

