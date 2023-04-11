#pragma once
#include "CoreMinimal.h"
#include "SDIBoneStabCurveOverrideMapEntry.h"
#include "SDIBoneStabCurveOverrideMap.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIBoneStabCurveOverrideMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, FSDIBoneStabCurveOverrideMapEntry> BoneStabCurveOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, FSDIBoneStabCurveOverrideMapEntry> BoneStabPullCurveOverrides;
    
    FSDIBoneStabCurveOverrideMap();
};

