#pragma once
#include "CoreMinimal.h"
#include "SDISaveExportResponse.h"
#include "SaveExportResponseCallbackDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSaveExportResponseCallback, FSDISaveExportResponse, Response);

