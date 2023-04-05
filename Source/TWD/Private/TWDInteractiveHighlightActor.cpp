#include "TWDInteractiveHighlightActor.h"
#include "TWDInteractionWidgetComponent.h"


ATWDInteractiveHighlightActor::ATWDInteractiveHighlightActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WidgetComponent = CreateDefaultSubobject<UTWDInteractionWidgetComponent>(TEXT("WidgetComponent"));
    this->HighlightSpeed = 5.00f;
    this->UnHighlightSpeed = 5.00f;
    this->ScaleCurve = NULL;
}

