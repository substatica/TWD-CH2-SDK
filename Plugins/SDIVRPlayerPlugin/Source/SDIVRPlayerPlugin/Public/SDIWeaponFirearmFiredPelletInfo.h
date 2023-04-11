#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponFirearmFiredShotInfo.h"
#include "SDIWeaponFirearmFiredPelletInfo.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIWeaponFirearmFiredPelletInfo : public FSDIWeaponFirearmFiredShotInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 Pellet;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 PelletCount;
    
    FSDIWeaponFirearmFiredPelletInfo();
};

