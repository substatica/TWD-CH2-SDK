#pragma once
#include "CoreMinimal.h"
#include "ESDIBooleanState.generated.h"

UENUM()
enum class ESDIBooleanState : uint8 {
    IsUnset,
    IsFalse,
    IsTrue,
};

