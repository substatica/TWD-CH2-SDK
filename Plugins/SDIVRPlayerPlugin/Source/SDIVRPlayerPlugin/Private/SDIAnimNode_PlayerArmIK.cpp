#include "SDIAnimNode_PlayerArmIK.h"

FSDIAnimNode_PlayerArmIK::FSDIAnimNode_PlayerArmIK() {
    this->ExtensionScaleCurve = NULL;
    this->ExtensionShoulderOffsetCurve = NULL;
    this->bUseNewElbowIK = false;
    this->ElbowSideRotationDefaultDeg = 0.00f;
    this->ElbowSideRotationMaxDeg = 0.00f;
    this->ElbowSideRotationSideContribution = 0.00f;
    this->ElbowSideRotationSideExp = 0.00f;
    this->ElbowSideRotationUpContribution = 0.00f;
    this->ElbowSideRotationUpExp = 0.00f;
    this->ElbowSideRotationForwardContribution = 0.00f;
    this->ElbowSideRotationForwardExp = 0.00f;
    this->ElbowSideRotationForwardDownExp = 0.00f;
    this->ElbowSideRotationPalmUpExp = 0.00f;
}

