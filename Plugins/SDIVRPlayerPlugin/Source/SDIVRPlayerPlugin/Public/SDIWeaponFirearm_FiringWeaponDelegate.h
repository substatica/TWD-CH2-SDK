#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponFirearm_FiringWeaponDelegate.generated.h"

class USDIWeaponFirearmFireModeComponent;
class ASDIWeaponFirearm;
class AController;
class APawn;
class ASDIWeaponFirearmAmmo;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FSDIWeaponFirearm_FiringWeapon, AController*, Controller, APawn*, Pawn, ASDIWeaponFirearm*, Firearm, USDIWeaponFirearmFireModeComponent*, Firemode, ASDIWeaponFirearmAmmo*, Ammo, int32, ShotID);

