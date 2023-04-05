#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkAudioSession.h"
#include "AkCommonInitializationSettingsWithSampleRate.h"
#include "AkPlatformInitialisationSettingsBase.h"
#include "AkAdvancedInitializationSettings.h"
#include "AkCommunicationSettingsWithSystemInitialization.h"
#include "AkTVOSInitializationSettings.generated.h"

UCLASS(DefaultConfig, Config=Game)
class AKAUDIO_API UAkTVOSInitializationSettings : public UObject, public IAkPlatformInitialisationSettingsBase {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere)
    FAkCommonInitializationSettingsWithSampleRate CommonSettings;
    
    UPROPERTY(Config, EditAnywhere)
    FAkAudioSession AudioSession;
    
    UPROPERTY(Config, EditAnywhere)
    FAkCommunicationSettingsWithSystemInitialization CommunicationSettings;
    
    UPROPERTY(AdvancedDisplay, Config, EditAnywhere)
    FAkAdvancedInitializationSettings AdvancedSettings;
    
    UAkTVOSInitializationSettings();
    
    // Fix for true pure virtual functions not being implemented
};

