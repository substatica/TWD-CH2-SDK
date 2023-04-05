#include "SDIMeleeWeaponHitCapsuleComponentDamage.h"

FSDIMeleeWeaponHitCapsuleComponentDamage::FSDIMeleeWeaponHitCapsuleComponentDamage() {
    this->VelocityAxis = ESDIAxis::Any;
    this->MinImpactVelocity = 0.00f;
    this->MinContinuousVelocity = 0.00f;
    this->MinContinuousVelocityTime = 0.00f;
    this->DamageFeedback = NULL;
}

