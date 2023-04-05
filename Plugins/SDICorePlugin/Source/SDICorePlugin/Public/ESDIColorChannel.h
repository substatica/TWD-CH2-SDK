#pragma once
#include "CoreMinimal.h"
#include "ESDIColorChannel.generated.h"

UENUM()
enum class ESDIColorChannel {
    None,
    R,
    G,
    B = 0x4,
    A = 0x8,
    RGB = 0x7,
    RGBA = 0xF,
    RG = 0x3,
    RB = 0x5,
    RA = 0x9,
    GB = 0x6,
    GA = 0xA,
    BA = 0xC,
    RGA = 0xB,
    RBA = 0xD,
    GBA,
    ESDIColorChannel_MAX = 0x10,
};

