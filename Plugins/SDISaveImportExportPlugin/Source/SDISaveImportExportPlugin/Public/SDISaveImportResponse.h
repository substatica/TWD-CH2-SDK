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
    UPROPERTY(BlueprintReadOnly)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadOnly)
    ESaveImportErrorCode ErrorCode;
    
    UPROPERTY(BlueprintReadOnly)
    int32 HttpResponseCode;
    
    UPROPERTY(BlueprintReadOnly)
    FSDIDataPayload PayloadData;
    
    UPROPERTY(BlueprintReadOnly)
    FString RequestedCode;
    
    FSDISaveImportResponse();
};

