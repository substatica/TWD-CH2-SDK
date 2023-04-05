#pragma once
#include "CoreMinimal.h"
#include "ESDIGripMovement.generated.h"

UENUM()
enum class ESDIGripMovement : uint8 {
    Locked,
    Maintain,
    Adjust,
    Free,
    MaintainCosmetic,
    AdjustCosmetic,
    RemapCosmetic,
    FreeCosmetic,
};

