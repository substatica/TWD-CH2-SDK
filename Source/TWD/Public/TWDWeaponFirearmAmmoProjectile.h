#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponFirearmAmmoProjectile.h"
#include "Curves/CurveFloat.h"
#include "SDITuningAttribute_TWDWeaponFirearmAmmoProjectile.h"
#include "TWDWeaponFirearmAmmoProjectile.generated.h"

class ATWDWeaponFirearmAmmoProjectile;

UCLASS()
class ATWDWeaponFirearmAmmoProjectile : public ASDIWeaponFirearmAmmoProjectile {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve DurabilityAdditionalSpreadDegrees;
    
public:
    ATWDWeaponFirearmAmmoProjectile(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    ATWDWeaponFirearmAmmoProjectile* TuneTWDWeaponFirearmAmmoProjectile(FSDITuningAttribute_TWDWeaponFirearmAmmoProjectile Attr, float PreModifier, float Add, float PostModifier);
    
};

