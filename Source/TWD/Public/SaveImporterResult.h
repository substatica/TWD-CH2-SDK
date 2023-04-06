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
    UPROPERTY(BlueprintReadWrite)
    EImportSaveGameResult TWDImportErrorCode;
    
    UPROPERTY(BlueprintReadWrite)
    ESDIServiceErrorCategory ErrorCategory;
    
    UPROPERTY(BlueprintReadWrite)
    ESaveImportErrorCode SDIImportErrorCode;
    
    UPROPERTY(BlueprintReadWrite)
    FString RequestedCode;
    
    UPROPERTY(BlueprintReadWrite)
    int32 HttpResponseCode;
    
    UPROPERTY(BlueprintReadWrite)
    bool bShippingCheatsEnabled;
    
    FSaveImporterResult();
};

