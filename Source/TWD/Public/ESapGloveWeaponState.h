#pragma once
#include "CoreMinimal.h"
#include "ESapGloveWeaponState.generated.h"

UENUM()
enum class ESapGloveWeaponState {
    Deactivated,
    Attached,
    Grabbed,
    GrippingCharacter,
};

