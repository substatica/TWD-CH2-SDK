#include "SDIWeaponFirearmAmmoProjectile.h"
#include "Templates/SubclassOf.h"

class ASDIProjectileActor;
class AActor;

ASDIProjectileActor* ASDIWeaponFirearmAmmoProjectile::SpawnProjectile_Implementation(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, TSubclassOf<ASDIProjectileActor> SpawnProjectileClass, AActor* ProjectileOwner) {
    return NULL;
}

void ASDIWeaponFirearmAmmoProjectile::ServerSpawnProjectile_Implementation(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, TSubclassOf<ASDIProjectileActor> SpawnProjectileClass, AActor* ProjectileOwner) {
}
bool ASDIWeaponFirearmAmmoProjectile::ServerSpawnProjectile_Validate(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, TSubclassOf<ASDIProjectileActor> SpawnProjectileClass, AActor* ProjectileOwner) {
    return true;
}

TSubclassOf<ASDIProjectileActor> ASDIWeaponFirearmAmmoProjectile::GetProjectileClass_Implementation(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform) {
    return NULL;
}

ASDIWeaponFirearmAmmoProjectile::ASDIWeaponFirearmAmmoProjectile() {
    this->ProjectileClass = NULL;
}

