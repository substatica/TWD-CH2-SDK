#pragma once
#include "CoreMinimal.h"
#include "ESapGloveEquipState.generated.h"

UENUM()
enum class ESapGloveEquipState {
    Default,
    Guide,
    Equipping,
    Equipped,
    Removing,
    Invalid,
};

