#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponFirearmFiredShotInfo.generated.h"

class USDIWeaponFirearmFireModeComponent;
class ASDIWeaponFirearm;
class AController;
class ASDIWeaponFirearmAmmo;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIWeaponFirearmFiredShotInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    AController* EventInstigator;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIWeaponFirearm* Firearm;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    USDIWeaponFirearmFireModeComponent* Firemode;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIWeaponFirearmAmmo* FiredAmmo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsPlayer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsADS;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Accuracy;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 NumRoundsFired;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 Burst;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 BurstCount;
    
    FSDIWeaponFirearmFiredShotInfo();
};

