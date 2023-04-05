#pragma once
#include "CoreMinimal.h"
#include "TWDFolderRule.h"
#include "Engine/DeveloperSettings.h"
#include "TWDPrimaryAssetRule.h"
#include "TWDAssetManagerSettings.generated.h"

UCLASS(DefaultConfig, NotPlaceable, Config=Game)
class TWD_API UTWDAssetManagerSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere)
    bool bExcludePlatformFolders;
    
    UPROPERTY(Config, EditAnywhere)
    TArray<FTWDFolderRule> FolderRules;
    
    UPROPERTY(Config, EditAnywhere)
    TArray<FTWDPrimaryAssetRule> PrimaryAssetRules;
    
    UTWDAssetManagerSettings();
};

