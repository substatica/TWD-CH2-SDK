#include "TWDWaveModeGameMode.h"

class USDIWeaponFirearmFireModeComponent;
class ASDIWeaponFirearm;
class AController;
class APawn;
class ASDIWeaponFirearmAmmo;

void ATWDWaveModeGameMode::SetAllWavesCompleted(bool bSet) {
}

void ATWDWaveModeGameMode::OnFiringWeapon_Implementation(AController* Controller, APawn* Pawn, ASDIWeaponFirearm* Firearm, USDIWeaponFirearmFireModeComponent* Firemode, ASDIWeaponFirearmAmmo* Ammo, int32 ShotID) {
}

bool ATWDWaveModeGameMode::AllWavesCompleted() const {
    return false;
}

ATWDWaveModeGameMode::ATWDWaveModeGameMode() {
    this->BalancedWaveCount = 0;
}

