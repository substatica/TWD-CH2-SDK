#pragma once
#include "CoreMinimal.h"
#include "ETWDStimType.generated.h"

UENUM(BlueprintType)
enum class ETWDStimType : uint8 {
    None,
    Sight,
    Hearing,
    GOB,
    Damage,
};

