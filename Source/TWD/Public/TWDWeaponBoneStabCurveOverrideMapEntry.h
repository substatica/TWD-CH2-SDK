#pragma once
#include "CoreMinimal.h"
#include "TWDWeaponBoneStabCurveOverrideMapEntry.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FTWDWeaponBoneStabCurveOverrideMapEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIncludeChildren;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* Curve;
    
    TWD_API FTWDWeaponBoneStabCurveOverrideMapEntry();
};

