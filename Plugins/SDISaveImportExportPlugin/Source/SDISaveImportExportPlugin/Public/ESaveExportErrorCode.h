#pragma once
#include "CoreMinimal.h"
#include "ESaveExportErrorCode.generated.h"

UENUM(BlueprintType)
enum class ESaveExportErrorCode : uint8 {
    NotInitialized,
    Success,
    HttpResponseFailure,
    JsonReadError,
    JsonConversionError,
    MissingResponseData,
    IncorrectResponseFormat,
    GeneralError = 0xC8,
};

