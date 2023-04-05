#pragma once
#include "CoreMinimal.h"
#include "SaveImportResponseCallbackDelegate.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SDISaveImportSubsystem.generated.h"

UCLASS(BlueprintType)
class SDISAVEIMPORTEXPORTPLUGIN_API USDISaveImportSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSaveImportResponseCallback OnImportResponseCallback;
    
    USDISaveImportSubsystem();
    UFUNCTION(BlueprintCallable)
    bool RequestImportByCode(const FString& RequestCode);
    
};

