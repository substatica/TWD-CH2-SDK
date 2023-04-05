#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDIInteractiveActorGripReleasedSignatureDelegate.generated.h"

class ASDIInteractiveActor;
class ASDIPlayerController;
class APawn;
class ASDIPlayerHand;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FSDIInteractiveActorGripReleasedSignature, ASDIInteractiveActor*, Actor, const FHitResult&, GripResult, ASDIPlayerController*, PC, APawn*, Pawn, ASDIPlayerHand*, hand);

