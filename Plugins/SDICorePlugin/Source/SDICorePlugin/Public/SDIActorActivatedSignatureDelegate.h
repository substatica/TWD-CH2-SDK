#pragma once
#include "CoreMinimal.h"
#include "SDIActorActivatedSignatureDelegate.generated.h"

class AActor;
class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSDIActorActivatedSignature, AActor*, Actor, AActor*, ActivatedBy, UObject*, OptionalObject, int32, OptionalData);

