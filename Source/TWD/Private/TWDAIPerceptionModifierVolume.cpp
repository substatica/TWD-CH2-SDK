#include "TWDAIPerceptionModifierVolume.h"

class ATWDCharacter;

float ATWDAIPerceptionModifierVolume::GetCanBeSeenDistanceFactor(const ATWDCharacter* Observered, const ATWDCharacter* Observer) const {
    return 0.0f;
}

ATWDAIPerceptionModifierVolume::ATWDAIPerceptionModifierVolume() {
    this->bNightModifier = false;
    this->StickinessInSeconds = 4.00f;
    this->bIncludeRayCastFromPointSource = false;
    this->RayCastInterval = 0.00f;
}

