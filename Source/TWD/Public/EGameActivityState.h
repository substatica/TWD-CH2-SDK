#pragma once
#include "CoreMinimal.h"
#include "EGameActivityState.generated.h"

UENUM()
enum class EGameActivityState : uint8 {
    Hidden,
    Available,
    Started,
    Resume,
    Unavailable,
    Cancelled,
    Suspended,
    Completed,
    Terminate,
    Count,
};

