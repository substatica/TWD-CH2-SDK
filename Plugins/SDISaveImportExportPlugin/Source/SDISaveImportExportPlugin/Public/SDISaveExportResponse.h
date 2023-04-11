#pragma once
#include "CoreMinimal.h"
#include "ESaveExportErrorCode.h"
#include "ESDIServiceErrorCategory.h"
#include "SDISaveExportResponse.generated.h"

USTRUCT(BlueprintType)
struct SDISAVEIMPORTEXPORTPLUGIN_API FSDISaveExportResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadWrite)
    ESaveExportErrorCode ErrorCode;
    
    UPROPERTY(BlueprintReadWrite)
    int32 HttpResponseCode;
    
    UPROPERTY(BlueprintReadWrite)
    FString FileCode;
    
    FSDISaveExportResponse();
};

