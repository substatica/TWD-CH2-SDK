#pragma once
#include "CoreMinimal.h"
#include "TWDPlayerController_OnAICommandUnpossessDelegate.generated.h"

class ATWDCharacter;
class ATWDPlayerController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTWDPlayerController_OnAICommandUnpossess, ATWDPlayerController*, PC, ATWDCharacter*, Char);

