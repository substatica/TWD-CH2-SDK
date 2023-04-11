#pragma once
#include "CoreMinimal.h"
#include "SDIBoneStabCurveOverrideMap.h"
#include "SDIMeleeWeaponBoneStabCurveOverrideMap.generated.h"

class ASDIMeleeWeaponActor;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIMeleeWeaponBoneStabCurveOverrideMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<TSoftClassPtr<ASDIMeleeWeaponActor>, FSDIBoneStabCurveOverrideMap> BoneStabCurveOverrideMap;
    
    FSDIMeleeWeaponBoneStabCurveOverrideMap();
};

