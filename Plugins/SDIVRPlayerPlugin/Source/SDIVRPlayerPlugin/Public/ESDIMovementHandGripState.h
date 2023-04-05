#pragma once
#include "CoreMinimal.h"
#include "ESDIMovementHandGripState.generated.h"

UENUM()
enum class ESDIMovementHandGripState : uint8 {
    None,
    Rope,
    GrabAndPull,
    Climbing,
    Moving,
};

