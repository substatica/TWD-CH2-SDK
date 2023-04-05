#pragma once
#include "CoreMinimal.h"
#include "TWDImportFailedPinDelegate.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TWDImportSucceededPinDelegate.h"
#include "SaveImporterResult.h"
#include "TWDSaveImportNode.generated.h"

class UObject;
class UTWDSaveImportNode;

UCLASS()
class TWD_API UTWDSaveImportNode : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FTWDImportSucceededPin ImportSucceeded;
    
    UPROPERTY(BlueprintAssignable)
    FTWDImportFailedPin ImportFailed;
    
    UTWDSaveImportNode();
private:
    UFUNCTION()
    void ResponseReceived(FSaveImporterResult Response);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UTWDSaveImportNode* RequestImportSaveUsingCode(const UObject* WorldContextObject, const FString& RequestCode);
    
};

