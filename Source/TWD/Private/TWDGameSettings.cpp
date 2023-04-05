#include "TWDGameSettings.h"

bool UTWDGameSettings::IsDemoMode(EDemoModeType DemoType) const {
    return false;
}

FString UTWDGameSettings::GetDemoModeDeviceProfileOverride() const {
    return TEXT("");
}

EDemoModeType UTWDGameSettings::GetDemoMode() const {
    return EDemoModeType::DemoMode_None;
}

UTWDGameSettings::UTWDGameSettings() {
    this->bChapterTwoEnabled = true;
    this->DemoModeType = EDemoModeType::DemoMode_None;
}

