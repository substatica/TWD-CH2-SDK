#pragma once
#include "CoreMinimal.h"
#include "ESDIAxisType.generated.h"

UENUM()
enum class ESDIAxisType : uint8 {
    Rotation,
    Translation,
    Scale,
};

