#pragma once
#include "CoreMinimal.h"
#include "EEGOAIGraphTypes.generated.h"

UENUM(BlueprintType)
enum class EEGOAIGraphTypes : uint8 {
    None,
    Custom,
    Linear,
    Quadratic,
    Sigmoid,
    OneMinus,
    LessThan,
    GreaterThan,
    InRange,
};

