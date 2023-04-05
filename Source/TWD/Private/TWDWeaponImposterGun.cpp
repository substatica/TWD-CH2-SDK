#include "TWDWeaponImposterGun.h"
#include "Components/SkeletalMeshComponent.h"
#include "TWDAutoTickAkComponent.h"

class ATWDCharacter;

bool ATWDWeaponImposterGun::PredictFireModeTransform(ESDIInteractiveInteractType Type, FTransform& OutTransform) const {
    return false;
}

bool ATWDWeaponImposterGun::IsThreat(ATWDCharacter* Character) {
    return false;
}

bool ATWDWeaponImposterGun::IsHighThreat(ATWDCharacter* Character) {
    return false;
}

ATWDWeaponImposterGun::ATWDWeaponImposterGun() {
    this->FirearmToSpawnOnDrop = NULL;
    this->BrokenFirearmToSpawnOnDrop = NULL;
    this->BrokenFirearmSpawnChance = 0.50f;
    this->bReturningToInventory = false;
    this->WeaponAnimType = EWeaponAnimation::Pistol;
    this->bIsRevolver = false;
    this->HitAccuracyMultiplier = 1.00f;
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    this->AkAudioComponent = CreateDefaultSubobject<UTWDAutoTickAkComponent>(TEXT("AkAudioComponent"));
    this->FiredRoundAudioEvent = NULL;
}

