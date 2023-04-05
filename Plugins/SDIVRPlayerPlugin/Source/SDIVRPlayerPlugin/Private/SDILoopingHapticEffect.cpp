#include "SDILoopingHapticEffect.h"

FSDILoopingHapticEffect::FSDILoopingHapticEffect() {
    this->Effect = NULL;
    this->Scale = 0.00f;
    this->FrequencyScale = 0.00f;
    this->PlaybackSpeed = 0.00f;
    this->Priority = 0;
    this->hand = EControllerHand::Left;
    this->PlayingID = 0;
    this->bSynchronized = false;
}

