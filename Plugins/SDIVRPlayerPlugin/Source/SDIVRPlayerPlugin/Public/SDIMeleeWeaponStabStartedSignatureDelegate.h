#pragma once
#include "CoreMinimal.h"
#include "SDIMeleeWeaponStabParams.h"
#include "SDIMeleeWeaponStabStartedSignatureDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSDIMeleeWeaponStabStartedSignature, AActor*, StabbedActor, const FSDIMeleeWeaponStabParams&, StabParams);

