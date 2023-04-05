#pragma once
#include "CoreMinimal.h"
#include "SDICoreGameModePlayerLogoutDelegateDelegate.generated.h"

class ASDICoreGameMode;
class APlayerController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSDICoreGameModePlayerLogoutDelegate, ASDICoreGameMode*, GameMode, APlayerController*, PC);

