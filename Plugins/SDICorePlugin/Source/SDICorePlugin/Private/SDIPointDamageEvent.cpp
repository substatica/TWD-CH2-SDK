#include "SDIPointDamageEvent.h"

FSDIPointDamageEvent::FSDIPointDamageEvent() {
    this->ImpactMass = 0.00f;
    this->HitReactImpulseMultiplier = 0.00f;
    this->HitReactMinSpeed = 0.00f;
    this->bApplyCameraShake = false;
    this->DamageID = 0;
}

