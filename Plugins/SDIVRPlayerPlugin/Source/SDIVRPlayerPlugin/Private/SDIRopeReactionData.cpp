#include "SDIRopeReactionData.h"

FSDIRopeReactionData::FSDIRopeReactionData() {
    this->bAutoUpdateTautElasticity = false;
    this->bAutoUpdateTautElasticityWorldLocation = false;
    this->bAutoUpdateTautElasticityAvoidShoulderDislocation = false;
    this->bAutoFaceOnTaut = false;
    this->bContinualFaceOnTaut = false;
    this->AutoFaceOnTautMinYawDeltaDegrees = 0.00f;
    this->bTugEvents = false;
    this->bTugRequireTwoHands = false;
    this->bTugAllowLateral = false;
    this->TugEngage = 0.00f;
    this->TugDisengage = 0.00f;
    this->TugMinTime = 0.00f;
    this->TugSound = NULL;
    this->bPullTick = false;
    this->bPullRequireTwoHands = false;
    this->bStruggleTick = false;
    this->StruggleMinTautLength = 0.00f;
    this->bStruggleTugRequireTwoHands = false;
    this->bStruggleTugRequiredToComplete = false;
    this->StruggleTugEngage = 0.00f;
    this->StruggleTugDisengage = 0.00f;
    this->StruggleTugMinTime = 0.00f;
    this->StruggleStickSpeed = 0.00f;
    this->bStruggleStickRequireTwoHands = false;
    this->StruggleHandOffsetSpeed = 0.00f;
    this->bStruggleHandOffsetRequireTwoHands = false;
    this->StruggleDecayDelay = 0.00f;
    this->StruggleDecaySpeedCurve = NULL;
    this->StruggleDecaySpeed = 0.00f;
    this->StruggleFeedbackLoop = NULL;
    this->StruggleStartFeedback = NULL;
    this->StruggleCompleteFeedback = NULL;
    this->StruggleTugSound = NULL;
    this->StruggleCancelSound = NULL;
    this->StruggleCompleteSound = NULL;
    this->DetachHandForceCurve = NULL;
    this->DetachRopeImpulse = 0.00f;
    this->DetachRopeImpulseVerticality = 0.00f;
    this->bWasTaut = false;
    this->TugTime = 0.00f;
    this->StruggleAmount = 0.00f;
    this->LastStruggleAmount = 0.00f;
    this->LastStruggleAmountDelta = 0.00f;
    this->StruggleTugTime = 0.00f;
    this->StruggleNoInputTime = 0.00f;
    this->StruggleFeedbackLoopId[0] = 0;
    this->StruggleFeedbackLoopId[1] = 0;
    this->bStrugglePaused = false;
}

