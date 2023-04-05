#pragma once
#include "CoreMinimal.h"
#include "SDIActorDeactivatedSignatureDelegate.generated.h"

class AActor;
class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSDIActorDeactivatedSignature, AActor*, Actor, AActor*, ActivatedBy, UObject*, OptionalObject, int32, OptionalData);

