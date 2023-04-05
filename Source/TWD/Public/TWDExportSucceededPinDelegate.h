#pragma once
#include "CoreMinimal.h"
#include "TWDExportResponse.h"
#include "TWDExportSucceededPinDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTWDExportSucceededPin, FTWDExportResponse, Result);

