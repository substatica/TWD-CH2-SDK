#pragma once
#include "CoreMinimal.h"
#include "ESDINetQuantizationMode.generated.h"

UENUM()
enum class ESDINetQuantizationMode {
    None,
    Networked,
    Always,
};

