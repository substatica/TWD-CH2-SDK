#pragma once
#include "CoreMinimal.h"
#include "TWDExportResponse.h"
#include "TWDSaveExportDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTWDSaveExportDelegate, FTWDExportResponse, Response);

