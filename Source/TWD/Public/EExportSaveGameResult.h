#pragma once
#include "CoreMinimal.h"
#include "EExportSaveGameResult.generated.h"

UENUM(BlueprintType)
enum class EExportSaveGameResult : uint8 {
    OK,
    NoSaveGame,
    ServiceError,
    UnspecifiedError,
};

