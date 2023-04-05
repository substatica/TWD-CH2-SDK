#include "SDIThrusterEntry.h"

FSDIThrusterEntry::FSDIThrusterEntry() {
    this->bAttached = false;
    this->bAccelChange = false;
    this->Force = 0.00f;
    this->ForceCurve = NULL;
    this->Duration = 0.00f;
    this->LoopCount = 0;
    this->CurrentTime = 0.00f;
}

