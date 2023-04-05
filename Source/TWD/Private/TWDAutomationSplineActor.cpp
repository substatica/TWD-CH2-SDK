#include "TWDAutomationSplineActor.h"
#include "Components/SplineComponent.h"

ATWDAutomationSplineActor::ATWDAutomationSplineActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
}

