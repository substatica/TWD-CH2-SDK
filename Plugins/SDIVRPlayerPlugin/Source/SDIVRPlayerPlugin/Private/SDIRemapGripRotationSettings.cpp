#include "SDIRemapGripRotationSettings.h"

FSDIRemapGripRotationSettings::FSDIRemapGripRotationSettings() {
    this->TwistThreshold = 0.00f;
    this->Swing1Threshold = 0.00f;
    this->Swing2Threshold = 0.00f;
    this->TwistCurve = NULL;
    this->Swing1Curve = NULL;
    this->Swing2Curve = NULL;
}

