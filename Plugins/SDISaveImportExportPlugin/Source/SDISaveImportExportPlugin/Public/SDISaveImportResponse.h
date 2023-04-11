#pragma once
#include "CoreMinimal.h"
#include "ESDIServiceErrorCategory.h"
#include "ESaveImportErrorCode.h"
#include "SDIDataPayload.h"
#include "SDISaveImportResponse.generated.h"

USTRUCT(BlueprintType)
struct SDISAVEIMPORTEXPORTPLUGIN_API FSDISaveImportResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadWrite)
    ESaveImportErrorCode ErrorCode;
    
    UPROPERTY(BlueprintReadWrite)
    int32 HttpResponseCode;
    
    UPROPERTY(BlueprintReadWrite)
    FSDIDataPayload PayloadData;
    
    UPROPERTY(BlueprintReadWrite)
    FString RequestedCode;
    
    FSDISaveImportResponse();
};

