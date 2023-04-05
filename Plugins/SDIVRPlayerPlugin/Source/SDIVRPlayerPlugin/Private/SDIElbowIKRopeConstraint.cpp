#include "SDIElbowIKRopeConstraint.h"

FSDIElbowIKRopeConstraint::FSDIElbowIKRopeConstraint() {
    this->bIsOtherHand = false;
    this->bEndPivotIsOtherHand = false;
    this->bIsTaut = false;
    this->TautTime = 0.00f;
    this->TautLength = 0.00f;
    this->Distance = 0.00f;
    this->TautPct = 0.00f;
}

