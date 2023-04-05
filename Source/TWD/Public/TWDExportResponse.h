#pragma once
#include "CoreMinimal.h"
#include "ESDIServiceErrorCategory.h"
#include "EExportSaveGameResult.h"
#include "SDISaveExportResponse.h"
#include "TWDExportResponse.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDExportResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly)
    EExportSaveGameResult TWDExportErrorCode;
    
    UPROPERTY(BlueprintReadOnly)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadOnly)
    FSDISaveExportResponse SDIServiceResponse;
    
    UPROPERTY(BlueprintReadOnly)
    int32 HttpResponseCode;
    
    FTWDExportResponse();
};

