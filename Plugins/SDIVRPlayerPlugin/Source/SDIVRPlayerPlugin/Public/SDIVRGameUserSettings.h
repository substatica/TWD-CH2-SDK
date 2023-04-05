#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "SDIVRGameUserSettings.generated.h"

class USDIVRGameUserSettings;

UCLASS()
class SDIVRPLAYERPLUGIN_API USDIVRGameUserSettings : public UGameUserSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    bool bDeferredSaveSettingsRequested;
    
    UPROPERTY(Config)
    bool bMicEnabled;
    
    UPROPERTY(Config)
    bool bMicPermissionRequestedEver;
    
    UPROPERTY(Config)
    bool bMicPermission;
    
    UPROPERTY(Config)
    bool bWritePermission;
    
    UPROPERTY(Config)
    bool bReadPermission;
    
    UPROPERTY(Config)
    bool bAppPermissionRequestedEver;
    
    UPROPERTY(Config)
    bool bUseThrowingReleaseTimeOffsetQuestLink;
    
    UPROPERTY(Config)
    float UserThrowingReleaseVelocityMultiplier;
    
    USDIVRGameUserSettings();
    UFUNCTION(BlueprintCallable)
    void SetWritePermissions(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetUseThrowingReleaseTimeOffsetQuestLink(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetUserThrowingReleaseVelocityMultiplier(float Multiplier);
    
    UFUNCTION(BlueprintCallable)
    void SetToDefaultsControls();
    
    UFUNCTION(BlueprintCallable)
    void SetReadPermissions(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetMicPermissionRequestedEver(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetMicPermission(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetAppPermissionRequestedEver(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void RequestDeferredSaveSettings();
    
    UFUNCTION(BlueprintPure)
    bool IsEnableOculusSteamVR() const;
    
    UFUNCTION(BlueprintPure)
    bool GetWritePermissions() const;
    
    UFUNCTION(BlueprintPure)
    bool GetUseThrowingReleaseTimeOffsetQuestLink() const;
    
    UFUNCTION(BlueprintPure)
    float GetUserThrowingReleaseVelocityMultiplier() const;
    
    UFUNCTION(BlueprintPure)
    static USDIVRGameUserSettings* GetSDIVRGameUserSettings();
    
    UFUNCTION(BlueprintPure)
    bool GetReadPermissions() const;
    
    UFUNCTION(BlueprintPure)
    bool GetMicPermissionRequestedEver() const;
    
    UFUNCTION(BlueprintPure)
    bool GetMicPermission() const;
    
    UFUNCTION(BlueprintPure)
    bool GetMicEnabled() const;
    
    UFUNCTION(BlueprintPure)
    bool GetAppPermissionRequestedEver() const;
    
};

