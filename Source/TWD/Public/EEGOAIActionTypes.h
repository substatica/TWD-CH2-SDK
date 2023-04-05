#pragma once
#include "CoreMinimal.h"
#include "EEGOAIActionTypes.generated.h"

UENUM(BlueprintType)
enum class EEGOAIActionTypes : uint8 {
    NoAction,
    Dead,
    Pause,
    Idle,
    Patrol,
    MoveToAttack,
    PrimaryAttack,
    SecondaryAttack,
    TertiaryAttack,
    Tethered,
    Impaled,
    Attack4,
    Attack5,
    Attack6,
};

