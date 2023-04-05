#pragma once
#include "CoreMinimal.h"
#include "SDIBoneStabCurveOverrideMapEntry.h"
#include "SDIBoneStabCurveOverrideMap.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIBoneStabCurveOverrideMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<FName, FSDIBoneStabCurveOverrideMapEntry> BoneStabCurveOverrides;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<FName, FSDIBoneStabCurveOverrideMapEntry> BoneStabPullCurveOverrides;
    
    FSDIBoneStabCurveOverrideMap();
};

