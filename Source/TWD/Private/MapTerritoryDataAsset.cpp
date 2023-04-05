#include "MapTerritoryDataAsset.h"

FName UMapTerritoryDataAsset::GetUMAPName() const {
    return NAME_None;
}

FName UMapTerritoryDataAsset::GetNightLightingScenarioName() const {
    return NAME_None;
}

TArray<FName> UMapTerritoryDataAsset::GetLightingScenarioOverlayNames(bool bNighttime, bool bOverrun) const {
    return TArray<FName>();
}

FName UMapTerritoryDataAsset::GetDayLightingScenarioName() const {
    return NAME_None;
}

void UMapTerritoryDataAsset::ApplyGamma(bool bNighttime, bool bOverrun) const {
}

UMapTerritoryDataAsset::UMapTerritoryDataAsset() {
    this->TerritoryIcon = NULL;
    this->HDRGammaDay = -1.00f;
    this->HDRGammaNight = -1.00f;
    this->HDRSpectatorGammaDay = -1.00f;
    this->HDRSpectatorGammaNight = -1.00f;
    this->MobileGammaDay = -1.00f;
    this->MobileGammaNight = -1.00f;
    this->MobileGammaDayOverrun = -1.00f;
    this->MobileGammaNightOverrun = -1.00f;
}

