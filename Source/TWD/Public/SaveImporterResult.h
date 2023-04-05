#pragma once
#include "CoreMinimal.h"
#include "EImportSaveGameResult.h"
#include "ESDIServiceErrorCategory.h"
#include "ESaveImportErrorCode.h"
#include "SaveImporterResult.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FSaveImporterResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly)
    EImportSaveGameResult TWDImportErrorCode;
    
    UPROPERTY(BlueprintReadOnly)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadOnly)
    ESaveImportErrorCode SDIImportErrorCode;
    
    UPROPERTY(BlueprintReadOnly)
    FString RequestedCode;
    
    UPROPERTY(BlueprintReadOnly)
    int32 HttpResponseCode;
    
    UPROPERTY(BlueprintReadOnly)
    bool bShippingCheatsEnabled;
    
    FSaveImporterResult();
};

