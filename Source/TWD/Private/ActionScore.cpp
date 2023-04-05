#include "ActionScore.h"

FActionScore::FActionScore() {
    this->WeightedScore = 0.00f;
    this->RawScore = 0.00f;
    this->Weight = 0.00f;
    this->OutState = EEGOAIActionTypes::NoAction;
    this->CommitToMemory = false;
    this->GOBReservationId = 0;
}

