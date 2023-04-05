#pragma once
#include "CoreMinimal.h"
#include "ESaveExportErrorCode.h"
#include "ESDIServiceErrorCategory.h"
#include "SDISaveExportResponse.generated.h"

USTRUCT(BlueprintType)
struct SDISAVEIMPORTEXPORTPLUGIN_API FSDISaveExportResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadOnly)
    ESaveExportErrorCode ErrorCode;
    
    UPROPERTY(BlueprintReadOnly)
    int32 HttpResponseCode;
    
    UPROPERTY(BlueprintReadOnly)
    FString FileCode;
    
    FSDISaveExportResponse();
};

