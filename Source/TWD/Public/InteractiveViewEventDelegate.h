#pragma once
#include "CoreMinimal.h"
#include "InteractiveViewEventDelegate.generated.h"

class UInteractiveViewComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractiveViewEvent, UInteractiveViewComponent*, TWDInteractiveViewComponent);

