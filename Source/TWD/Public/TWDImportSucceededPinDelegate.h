#pragma once
#include "CoreMinimal.h"
#include "SaveImporterResult.h"
#include "TWDImportSucceededPinDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTWDImportSucceededPin, FSaveImporterResult, Result);

