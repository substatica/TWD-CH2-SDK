#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TWDSaveExportDelegateDelegate.h"
#include "SDISaveExportResponse.h"
#include "TWDSaveExporter.generated.h"

class UTWDSaveGame;

UCLASS(BlueprintType)
class TWD_API UTWDSaveExporter : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FTWDSaveExportDelegate OnExportRequestComplete;
    
    UTWDSaveExporter();
private:
    UFUNCTION()
    void HandleResponse(FSDISaveExportResponse Response);
    
public:
    UFUNCTION(BlueprintCallable)
    bool ExportSaveAtIndex(int32 ProfileIndex, int32 SaveIndex);
    
    UFUNCTION(BlueprintCallable)
    bool ExportSave(const UTWDSaveGame* SaveGame);
    
    UFUNCTION(BlueprintCallable)
    bool ExportMarketingCode(TArray<FString> Flags);
    
};

