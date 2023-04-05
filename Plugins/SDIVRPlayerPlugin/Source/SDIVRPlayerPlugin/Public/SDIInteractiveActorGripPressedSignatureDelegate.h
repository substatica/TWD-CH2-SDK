#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDIInteractiveActorGripPressedSignatureDelegate.generated.h"

class ASDIInteractiveActor;
class ASDIPlayerController;
class APawn;
class ASDIPlayerHand;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FSDIInteractiveActorGripPressedSignature, ASDIInteractiveActor*, Actor, const FHitResult&, GripResult, ASDIPlayerController*, PC, APawn*, Pawn, ASDIPlayerHand*, hand);

