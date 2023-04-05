#include "SDISignificanceStasisActor.h"

ASDISignificanceStasisActor::ASDISignificanceStasisActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxActiveBin = 0;
    this->MaxVisibleBin = 0;
    this->ActorPreviouslyDeactivated = false;
}

