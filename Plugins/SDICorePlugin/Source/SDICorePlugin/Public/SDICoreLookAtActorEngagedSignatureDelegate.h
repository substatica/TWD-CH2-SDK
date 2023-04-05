#pragma once
#include "CoreMinimal.h"
#include "SDICoreLookAtActorEngagedSignatureDelegate.generated.h"

class ASDICoreLookAtActor;
class APlayerController;
class ACharacter;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSDICoreLookAtActorEngagedSignature, ASDICoreLookAtActor*, LookAtActor, APlayerController*, PlayerController, ACharacter*, LookAtChar);

