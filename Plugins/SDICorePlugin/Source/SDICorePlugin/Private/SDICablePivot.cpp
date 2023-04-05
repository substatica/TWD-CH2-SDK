#include "SDICablePivot.h"

FSDICablePivot::FSDICablePivot() {
    this->hand = EControllerHand::Left;
    this->Length = 0.00f;
    this->ElasticLength = 0.00f;
    this->NonElasticLength = 0.00f;
    this->BodyParentLength = 0.00f;
    this->Time = 0.00f;
    this->TautTime = 0.00f;
    this->bIsTaut = false;
    this->bAllowElasticTautPhysics = false;
    this->bCanBeUsedForMovement = false;
}

