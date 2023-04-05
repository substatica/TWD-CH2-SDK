#pragma once
#include "CoreMinimal.h"
#include "EWeaponAnimation.h"
#include "EGender.h"
#include "GenderWeaponKey.generated.h"

USTRUCT()
struct FGenderWeaponKey {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    EGender Gender;
    
    UPROPERTY(EditAnywhere)
    EWeaponAnimation Weapon;
    
    TWD_API FGenderWeaponKey();
};

