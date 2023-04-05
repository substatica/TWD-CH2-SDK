#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TWDExportSucceededPinDelegate.h"
#include "TWDExportFailedPinDelegate.h"
#include "TWDExportResponse.h"
#include "TWDSaveExportNode.generated.h"

class UObject;
class UTWDSaveExportNode;

UCLASS()
class TWD_API UTWDSaveExportNode : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FTWDExportSucceededPin ExportSucceeded;
    
    UPROPERTY(BlueprintAssignable)
    FTWDExportFailedPin ExportFailed;
    
    UTWDSaveExportNode();
private:
    UFUNCTION()
    void ResponseReceived(FTWDExportResponse Response);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UTWDSaveExportNode* RequestExportSaveAtIndex(const UObject* WorldContextObject, int32 ProfileIndex, int32 SaveIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UTWDSaveExportNode* RequestExportLegacySave(const UObject* WorldContextObject);
    
};

