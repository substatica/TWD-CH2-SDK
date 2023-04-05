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
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve DurabilityAdditionalSpreadDegrees;
    
public:
    ATWDWeaponFirearmAmmoProjectile();
    UFUNCTION(BlueprintCallable)
    ATWDWeaponFirearmAmmoProjectile* TuneTWDWeaponFirearmAmmoProjectile(FSDITuningAttribute_TWDWeaponFirearmAmmoProjectile Attr, float PreModifier, float Add, float PostModifier);
    
};

