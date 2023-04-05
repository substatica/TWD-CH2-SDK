#pragma once
#include "CoreMinimal.h"
#include "TWDExportResponse.h"
#include "TWDExportFailedPinDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTWDExportFailedPin, FTWDExportResponse, Result);

