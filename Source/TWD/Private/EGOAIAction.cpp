#include "EGOAIAction.h"

FEGOAIAction::FEGOAIAction() {
    this->Disable = false;
    this->OutState = EEGOAIActionTypes::NoAction;
    this->NeedsTarget = false;
    this->MaxCutoff = 0.00f;
    this->MinCutoff = 0.00f;
    this->Weight = 0.00f;
    this->CommitToMemory = false;
}

