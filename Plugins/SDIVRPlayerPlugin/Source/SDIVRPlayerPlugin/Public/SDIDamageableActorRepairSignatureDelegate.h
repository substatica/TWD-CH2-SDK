#pragma once
#include "CoreMinimal.h"
#include "SDIDamageableActorRepairSignatureDelegate.generated.h"

class ASDIDamageableActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSDIDamageableActorRepairSignature, ASDIDamageableActor*, Actor);

