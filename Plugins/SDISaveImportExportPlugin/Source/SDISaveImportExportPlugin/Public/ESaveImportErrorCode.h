#pragma once
#include "CoreMinimal.h"
#include "ESaveImportErrorCode.generated.h"

UENUM(BlueprintType)
enum class ESaveImportErrorCode : uint8 {
    NotInitialized,
    Success,
    JsonReadError = 0xA,
    JsonConversionError,
    BadResponseFormat,
    IncompatibleAppId,
    HttpRequestFailure = 0x14,
    HttpResponseFailure,
    EmptyResponse,
    GeneralError = 0xC8,
};

