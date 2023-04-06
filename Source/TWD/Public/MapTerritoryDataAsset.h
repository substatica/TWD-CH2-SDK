#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PerPlatformString.h"
#include "TWDLightingScenarioOverlay.h"
#include "MapTerritoryDataAsset.generated.h"

class UTexture2D;

UCLASS(BlueprintType)
class TWD_API UMapTerritoryDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText TerritoryName;
    
    UPROPERTY(EditAnywhere)
    FPerPlatformString Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UTexture2D* TerritoryIcon;
    
    UPROPERTY(EditAnywhere)
    float HDRGammaDay;
    
    UPROPERTY(EditAnywhere)
    float HDRGammaNight;
    
    UPROPERTY(EditAnywhere)
    float HDRSpectatorGammaDay;
    
    UPROPERTY(EditAnywhere)
    float HDRSpectatorGammaNight;
    
    UPROPERTY(EditAnywhere)
    float MobileGammaDay;
    
    UPROPERTY(EditAnywhere)
    float MobileGammaNight;
    
    UPROPERTY(EditAnywhere)
    float MobileGammaDayOverrun;
    
    UPROPERTY(EditAnywhere)
    float MobileGammaNightOverrun;
    
    UPROPERTY(EditAnywhere)
    FPerPlatformString NightLightingScenario;
    
    UPROPERTY(EditAnywhere)
    FPerPlatformString DayLightingScenario;
    
    UPROPERTY(EditAnywhere)
    FTWDLightingScenarioOverlay LightingScenarioOverlay;
    
    UPROPERTY(EditAnywhere)
    FTWDLightingScenarioOverlay OverrunLightingScenarioOverlay;
    
    UMapTerritoryDataAsset();
    UFUNCTION()
    FName GetUMAPName() const;
    
    UFUNCTION()
    FName GetNightLightingScenarioName() const;
    
    UFUNCTION()
    TArray<FName> GetLightingScenarioOverlayNames(bool bNighttime, bool bOverrun) const;
    
    UFUNCTION()
    FName GetDayLightingScenarioName() const;
    
    UFUNCTION()
    void ApplyGamma(bool bNighttime, bool bOverrun) const;
    
};

