#pragma once
#include "CoreMinimal.h"
#include "SDISaveImportResponse.h"
#include "SaveImportResponseCallbackDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSaveImportResponseCallback, FSDISaveImportResponse, Response);

