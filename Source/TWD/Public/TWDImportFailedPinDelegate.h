#pragma once
#include "CoreMinimal.h"
#include "SaveImporterResult.h"
#include "TWDImportFailedPinDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTWDImportFailedPin, FSaveImporterResult, Result);

