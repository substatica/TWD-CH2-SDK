#include "TWDFlashlight.h"

void ATWDFlashlight::SetUVMode(bool isUV) {
}

void ATWDFlashlight::SetSwitchedOn(bool inSwitchedOn) {
}

void ATWDFlashlight::SetPowered(bool inPowered) {
}

bool ATWDFlashlight::IsUVMode() const {
    return false;
}

bool ATWDFlashlight::IsSwitchedOn() const {
    return false;
}

bool ATWDFlashlight::IsPowered() const {
    return false;
}

bool ATWDFlashlight::IsOn() const {
    return false;
}

ATWDFlashlight::ATWDFlashlight() {
    this->bInsideOnRep_bRepInsideInventory = false;
    this->bSwitchedOn = false;
    this->bPowered = true;
    this->bUVMode = false;
    this->PerceptionOverrideDotProductMinimum = 0.80f;
}

