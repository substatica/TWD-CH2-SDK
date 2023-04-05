#include "SDIWeightedAnimation.h"

FSDIWeightedAnimation::FSDIWeightedAnimation() {
    this->AnimSequence = NULL;
    this->AnimSequencePlayRate = 0.00f;
    this->bUsesRootMotion = false;
    this->Weight = 0.00f;
    this->CurrentWeight = 0.00f;
}

