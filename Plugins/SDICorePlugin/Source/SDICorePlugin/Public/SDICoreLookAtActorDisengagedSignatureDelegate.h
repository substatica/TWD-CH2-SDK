#pragma once
#include "CoreMinimal.h"
#include "SDICoreLookAtActorDisengagedSignatureDelegate.generated.h"

class ASDICoreLookAtActor;
class APlayerController;
class ACharacter;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSDICoreLookAtActorDisengagedSignature, ASDICoreLookAtActor*, LookAtActor, APlayerController*, PlayerController, ACharacter*, LookAtChar);

