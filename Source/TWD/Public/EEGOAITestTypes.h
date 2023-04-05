#pragma once
#include "CoreMinimal.h"
#include "EEGOAITestTypes.generated.h"

UENUM(BlueprintType)
enum class EEGOAITestTypes : uint8 {
    None,
    BlueprintCustom,
    ConstantZERO,
    ConstantONE,
    Constant,
    UsePerceptionValue,
    IsEnemy,
    IsFriendly,
    IsNeutral,
    DistanceToTarget,
    IsTargetClose,
    MyHealth,
    TargetHealth,
    Random,
    IsSound,
    IsLastSeen,
    IsVisible,
    IsSight,
    IsStateAgeAtMost,
    IsStateAgeAtLeast,
    IsStateAgeInRange,
    IsStateNeverUsed,
    IsOnCooldown,
    IsOffCooldown,
    ReceivedDamage,
    IsTag,
    IsDownedOrDead,
    IsCharacter,
    IsGrappleAttacking,
    IsPlayer,
    IsTargetStateAgeAtMost,
    IsTargetStateAgeAtLeast,
    IsTargetStateAgeInRange,
    IsTargetStateNeverUsed,
    IsTargetStateOnCooldown,
    IsTargetStateOffCooldown,
};

