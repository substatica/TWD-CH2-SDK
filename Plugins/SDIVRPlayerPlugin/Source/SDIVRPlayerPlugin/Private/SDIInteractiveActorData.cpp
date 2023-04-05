#include "SDIInteractiveActorData.h"

FSDIInteractiveActorData::FSDIInteractiveActorData() {
    this->HighlightFeedback = NULL;
    this->GripFeedback = NULL;
    this->InteractFeedback = NULL;
    this->PhysicalInteractFeedback = NULL;
    this->bUseInteractTriggerResistanceCurveForHighlightedInteractions = false;
    this->InteractTriggerResistanceCurve = NULL;
    this->bInteractiveGripOverride = false;
    this->bDisableNonVRInteractionMovement = false;
    this->bDisableNonVRObjectInteraction = false;
}

