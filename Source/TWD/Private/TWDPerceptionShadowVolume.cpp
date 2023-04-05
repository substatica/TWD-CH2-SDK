#include "TWDPerceptionShadowVolume.h"

ADEPRECATED_TWDPerceptionShadowVolume::ADEPRECATED_TWDPerceptionShadowVolume() {
    this->BasePerceptionMultiplier = 0.25f;
    this->BasePerceptionAdditive = 0.00f;
    this->PerceptionCurve = NULL;
    this->bUseCoverageAttenuation = true;
    this->CoverageAttenuationCurve = NULL;
}

