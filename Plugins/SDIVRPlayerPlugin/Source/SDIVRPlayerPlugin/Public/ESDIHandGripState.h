#pragma once
#include "CoreMinimal.h"
#include "ESDIHandGripState.generated.h"

UENUM()
enum class ESDIHandGripState : uint8 {
    None,
    HeldActor,
    Interactive,
    World,
    Physics,
    Rope,
};

