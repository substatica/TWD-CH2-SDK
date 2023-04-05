#pragma once
#include "CoreMinimal.h"
#include "SDIMeleeWeaponStabParams.h"
#include "SDIMeleeWeaponStabCompletedSignatureDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSDIMeleeWeaponStabCompletedSignature, AActor*, StabbedActor, const FSDIMeleeWeaponStabParams&, StabParams);

