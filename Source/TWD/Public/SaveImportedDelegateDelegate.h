#pragma once
#include "CoreMinimal.h"
#include "SaveImporterResult.h"
#include "SaveImportedDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSaveImportedDelegate, FSaveImporterResult, Response);

