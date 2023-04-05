#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveExportResponseCallbackDelegate.h"
#include "SDIJsonExportSettings.h"
#include "SDISaveExportSubsystem.generated.h"

class UObject;

UCLASS(BlueprintType)
class SDISAVEIMPORTEXPORTPLUGIN_API USDISaveExportSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSaveExportResponseCallback OnExportResponseCallback;
    
    USDISaveExportSubsystem();
    UFUNCTION(BlueprintCallable)
    bool K2ExportObject(const UObject* ObjPayload, FSDIJsonExportSettings Settings);
    
    UFUNCTION(BlueprintCallable)
    bool ExportString(const FString& SerializedString);
    
};

