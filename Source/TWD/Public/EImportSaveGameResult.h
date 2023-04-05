#pragma once
#include "CoreMinimal.h"
#include "EImportSaveGameResult.generated.h"

UENUM(BlueprintType)
enum class EImportSaveGameResult : uint8 {
    OK,
    DoesNotExist,
    Corrupt,
    UnspecifiedError,
    IncompatibleVersion,
    BadPermissions,
    OsReadError,
    FileReaderError,
    ServiceError,
};

