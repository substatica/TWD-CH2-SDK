#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SDISaveImportResponse.h"
#include "SaveImportedDelegateDelegate.h"
#include "EImportSaveGameResult.h"
#include "TWDSaveImporter.generated.h"

class USaveGame;

UCLASS(BlueprintType)
class TWD_API UTWDSaveImporter : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    USaveGame* LegacySave;
    
    UPROPERTY(BlueprintAssignable)
    FSaveImportedDelegate OnImportRequestCompleted;
    
    UTWDSaveImporter();
private:
    UFUNCTION()
    void OnImportResponseReceived(FSDISaveImportResponse Response);
    
public:
    UFUNCTION(BlueprintCallable)
    bool ImportLegacySaveFromCode(const FString& RequestCode);
    
    UFUNCTION(BlueprintPure)
    EImportSaveGameResult GetStatus() const;
    
};

