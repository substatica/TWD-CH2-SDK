#include "SDIAxisControlCurve.h"

FSDIAxisControlCurve::FSDIAxisControlCurve() {
    this->InputAxis = EAxis::None;
    this->InputAxisType = ESDIAxisType::Rotation;
    this->OutputAxis = EAxis::None;
    this->OutputAxisType = ESDIAxisType::Rotation;
    this->OutputScale = 0.00f;
    this->bOutputAdditive = false;
    this->bResetSpring = false;
}

