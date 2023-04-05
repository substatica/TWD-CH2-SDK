#pragma once
#include "CoreMinimal.h"
#include "SDIDamageableActorHealthChangeSignatureDelegate.generated.h"

class ASDIDamageableActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSDIDamageableActorHealthChangeSignature, ASDIDamageableActor*, Actor, int32, Previous, int32, Current);

