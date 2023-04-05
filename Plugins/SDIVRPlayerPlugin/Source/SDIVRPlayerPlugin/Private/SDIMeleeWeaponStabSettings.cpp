#include "SDIMeleeWeaponStabSettings.h"

FSDIMeleeWeaponStabSettings::FSDIMeleeWeaponStabSettings() {
    this->StabAxis = ESDIAxis::Any;
    this->StabAngleDeg = 0.00f;
    this->StabInterpolationDuration = 0.00f;
    this->StabNormalAngleDeg = 0.00f;
    this->StabForcedCapsuleOffset = 0.00f;
    this->StabStartDepth = 0.00f;
    this->StabMaxDepth = 0.00f;
    this->StabExtractionDepth = 0.00f;
    this->StabExtractionDelay = 0.00f;
    this->StabExtractionTime = 0.00f;
    this->StabInitialDepthVelocityCurve = NULL;
    this->bStabCanPush = false;
    this->StabCurve = NULL;
    this->StabPullCurve = NULL;
    this->StabStartAudio = NULL;
    this->StabCompleteAudio = NULL;
    this->StabPullAudio = NULL;
    this->StabStartFeedback = NULL;
    this->StabCompleteFeedback = NULL;
    this->StabPullFeedback = NULL;
    this->StabPushLoopFeedback = NULL;
    this->StabPushLoopFeedbackScaleCurve = NULL;
    this->StabPullLoopFeedback = NULL;
    this->StabPullLoopFeedbackScaleCurve = NULL;
    this->StabSawIncrements = 0;
    this->StabIncrementalSawInFeedback = NULL;
    this->StabIncrementalSawOutFeedback = NULL;
}

