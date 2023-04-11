#pragma once
#include "CoreMinimal.h"
#include "SDIMeleeWeaponBoneStabCurveOverrideMap.h"
#include "Engine/EngineTypes.h"
#include "SDIMeleeWeaponStabInterfaceData.generated.h"

class ASDIMeleeWeaponActor;
class USDIActiveRagdollComponent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIMeleeWeaponStabInterfaceData {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIMeleeWeaponBoneStabCurveOverrideMap BoneStabCurveOverrideMap;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, bool> BoneStabMap;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName StabConstraintProfile;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName StabPhysicalAnimationProfile;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<ASDIMeleeWeaponActor>> StabWeapons;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ASDIMeleeWeaponActor>, FTimerHandle> StuckWeapons;
    
    UPROPERTY(EditAnywhere, Export, Transient)
    TWeakObjectPtr<USDIActiveRagdollComponent> WeakARComp;
    
    UPROPERTY(Transient)
    int32 StabConstraintProfileOverrideId;
    
    UPROPERTY(Transient)
    int32 StabPhysicalAnimationProfileOverrideId;
    
public:
    FSDIMeleeWeaponStabInterfaceData();
};

