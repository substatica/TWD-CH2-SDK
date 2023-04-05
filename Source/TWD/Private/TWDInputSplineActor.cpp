#include "TWDInputSplineActor.h"

ATWDInputSplineActor::ATWDInputSplineActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TimeDilation = 0.10f;
    this->TimeDilationMaxDuration = -1.00f;
}

