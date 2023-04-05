#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkWinGDKAdvancedInitializationSettings.h"
#include "AkCommonInitializationSettingsWithSampleRate.h"
#include "AkPlatformInitialisationSettingsBase.h"
#include "AkCommunicationSettingsWithSystemInitialization.h"
#include "AkWinGDKInitializationSettings.generated.h"

UCLASS(DefaultConfig, Config=Game)
class AKAUDIO_API UAkWinGDKInitializationSettings : public UObject, public IAkPlatformInitialisationSettingsBase {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere)
    FAkCommonInitializationSettingsWithSampleRate CommonSettings;
    
    UPROPERTY(Config, EditAnywhere)
    FAkCommunicationSettingsWithSystemInitialization CommunicationSettings;
    
    UPROPERTY(AdvancedDisplay, Config, EditAnywhere)
    FAkWinGDKAdvancedInitializationSettings AdvancedSettings;
    
    UAkWinGDKInitializationSettings();
    UFUNCTION()
    void MigrateMultiCoreRendering(bool NewValue);
    
    
    // Fix for true pure virtual functions not being implemented
};

