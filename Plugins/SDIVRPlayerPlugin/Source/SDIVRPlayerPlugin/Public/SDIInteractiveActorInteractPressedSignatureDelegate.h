#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ESDIInteractiveInteractType.h"
#include "SDIInteractiveActorInteractPressedSignatureDelegate.generated.h"

class ASDIInteractiveActor;
class ASDIPlayerController;
class APawn;
class ASDIPlayerHand;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FSDIInteractiveActorInteractPressedSignature, ASDIInteractiveActor*, Actor, const FHitResult&, InteractResult, ESDIInteractiveInteractType, Type, ASDIPlayerController*, PC, APawn*, Pawn, ASDIPlayerHand*, hand);

