#pragma once
#include "CoreMinimal.h"
#include "ESDIServiceErrorCategory.generated.h"

UENUM(BlueprintType)
enum class ESDIServiceErrorCategory : uint8 {
    OK,
    ServerUnreachable = 0xA,
    ServerIsBusy,
    NoContent = 0x14,
    BadRequest,
    ServiceFailureError,
    GeneralError = 0xC8,
};

