#pragma once
#include "CoreMinimal.h"
#include "ESDIMeleeWeaponStabState.generated.h"

UENUM(BlueprintType)
enum class ESDIMeleeWeaponStabState : uint8 {
    None,
    Interpolate,
    Push,
    Pull,
    Stuck,
};

