#pragma once
#include "CoreMinimal.h"
#include "SDICorePlayerControllerInputComponentSetupSignatureDelegate.generated.h"

class ASDICorePlayerController;
class UInputComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSDICorePlayerControllerInputComponentSetupSignature, ASDICorePlayerController*, PC, UInputComponent*, NewInputComponent);

