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
    UPROPERTY(BlueprintReadWrite)
    EExportSaveGameResult TWDExportErrorCode;
    
    UPROPERTY(BlueprintReadWrite)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadWrite)
    FSDISaveExportResponse SDIServiceResponse;
    
    UPROPERTY(BlueprintReadWrite)
    int32 HttpResponseCode;
    
    FTWDExportResponse();
};

