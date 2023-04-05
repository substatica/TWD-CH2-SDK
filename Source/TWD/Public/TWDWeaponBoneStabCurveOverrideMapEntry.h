#pragma once
#include "CoreMinimal.h"
#include "TWDWeaponBoneStabCurveOverrideMapEntry.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FTWDWeaponBoneStabCurveOverrideMapEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bIncludeChildren;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* Curve;
    
    TWD_API FTWDWeaponBoneStabCurveOverrideMapEntry();
};

