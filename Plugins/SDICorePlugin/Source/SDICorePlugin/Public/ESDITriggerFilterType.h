#pragma once
#include "CoreMinimal.h"
#include "ESDITriggerFilterType.generated.h"

UENUM(BlueprintType)
enum class ESDITriggerFilterType : uint8 {
    All,
    NonPawns,
    AllPawns,
    PlayerPawnsOnly,
    NonPlayerPawnsOnly,
};

