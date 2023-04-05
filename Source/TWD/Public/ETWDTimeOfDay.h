#pragma once
#include "CoreMinimal.h"
#include "ETWDTimeOfDay.generated.h"

UENUM(BlueprintType)
enum class ETWDTimeOfDay : uint8 {
    Morning,
    Day,
    Night,
    LateNight,
    COUNT,
};

