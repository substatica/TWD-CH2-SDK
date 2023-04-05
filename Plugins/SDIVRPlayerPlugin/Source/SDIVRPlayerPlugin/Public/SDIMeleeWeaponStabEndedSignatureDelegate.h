#pragma once
#include "CoreMinimal.h"
#include "SDIMeleeWeaponStabParams.h"
#include "SDIMeleeWeaponStabEndedSignatureDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSDIMeleeWeaponStabEndedSignature, AActor*, StabbedActor, bool, bRemovedWeapon, const FSDIMeleeWeaponStabParams&, StabParams);

