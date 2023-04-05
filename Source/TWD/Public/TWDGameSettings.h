#pragma once
#include "CoreMinimal.h"
#include "EDemoModeType.h"
#include "Engine/DeveloperSettings.h"
#include "TWDDemoModeDeviceProfileOverride.h"
#include "TWDGameSettings.generated.h"

UCLASS(BlueprintType, DefaultConfig, Config=Game)
class TWD_API UTWDGameSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Config)
    bool bChapterTwoEnabled;
    
    UPROPERTY(Config)
    EDemoModeType DemoModeType;
    
    UPROPERTY(Config)
    TArray<FTWDDemoModeDeviceProfileOverride> DemoModeTypeDeviceProfileOverrides;
    
    UPROPERTY(Transient)
    TMap<EDemoModeType, FString> DemoModeTypeDeviceProfileOverrideMap;
    
public:
    UTWDGameSettings();
    UFUNCTION(BlueprintPure)
    bool IsDemoMode(EDemoModeType DemoType) const;
    
    UFUNCTION(BlueprintPure)
    FString GetDemoModeDeviceProfileOverride() const;
    
    UFUNCTION(BlueprintPure)
    EDemoModeType GetDemoMode() const;
    
};

