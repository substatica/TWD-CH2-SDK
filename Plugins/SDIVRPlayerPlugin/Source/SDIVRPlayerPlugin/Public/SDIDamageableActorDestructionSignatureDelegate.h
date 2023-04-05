#pragma once
#include "CoreMinimal.h"
#include "SDIReplicatedDamageData.h"
#include "SDIDamageableActorDestructionSignatureDelegate.generated.h"

class ASDIDamageableActor;
class AController;
class APawn;
class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FSDIDamageableActorDestructionSignature, ASDIDamageableActor*, Actor, AController*, InstigatorController, APawn*, InstigatorPawn, AActor*, DamageCauser, const FSDIReplicatedDamageData&, DamageTakenData);

