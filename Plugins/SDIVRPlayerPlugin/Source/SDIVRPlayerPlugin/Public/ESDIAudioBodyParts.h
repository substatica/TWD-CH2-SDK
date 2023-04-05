#pragma once
#include "CoreMinimal.h"
#include "ESDIAudioBodyParts.generated.h"

UENUM()
enum class ESDIAudioBodyParts : uint8 {
    None,
    LeftFoot,
    RightFoot,
    LeftHand,
    RightHand,
    Chest,
    Mouth,
    Misc1,
};

