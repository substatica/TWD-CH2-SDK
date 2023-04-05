#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UObject/NoExportTypes.h"
#include "SDIExportInterface.h"
#include "SDIExportData.h"
#include "SDICoreGameModePlayerLoginDelegateDelegate.h"
#include "SDIQueuedRagdoll.h"
#include "SDICoreGameModePlayerLogoutDelegateDelegate.h"
#include "Engine/EngineTypes.h"
#include "SDICoreGameMode.generated.h"

UCLASS(NonTransient)
class SDICOREPLUGIN_API ASDICoreGameMode : public AGameMode, public ISDIExportInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    FSDIExportData ExportData;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDICoreGameModePlayerLoginDelegate OnPlayerLoginDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDICoreGameModePlayerLogoutDelegate OnPlayerLogoutDelegate;
    
protected:
    UPROPERTY(Transient)
    TArray<FSDIQueuedRagdoll> QueuedRagdolls;
    
    UPROPERTY(Transient)
    FTimerHandle QueuedRagdollTimerHandle;
    
public:
    ASDICoreGameMode();
protected:
    UFUNCTION()
    void ProcessQueuedRagdolls();
    
public:
    UFUNCTION(BlueprintPure)
    float GetServerTimestamp() const;
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    FGuid K2GetExportGuid() const override PURE_VIRTUAL(K2GetExportGuid, return FGuid{};);
    
    UFUNCTION(BlueprintCallable)
    FText GetExportText(FName Key) const override PURE_VIRTUAL(GetExportText, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    FText GetExportDisplayName() const override PURE_VIRTUAL(GetExportDisplayName, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    FText GetExportDescription() const override PURE_VIRTUAL(GetExportDescription, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    bool FindExportText(FName Key, FText& OutText) const override PURE_VIRTUAL(FindExportText, return false;);
    
};

