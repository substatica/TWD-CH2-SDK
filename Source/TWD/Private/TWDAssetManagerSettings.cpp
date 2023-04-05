#include "TWDAssetManagerSettings.h"

UTWDAssetManagerSettings::UTWDAssetManagerSettings() {
    this->bExcludePlatformFolders = false;
    this->FolderRules.AddDefaulted(3);
    this->PrimaryAssetRules.AddDefaulted(66);
}

