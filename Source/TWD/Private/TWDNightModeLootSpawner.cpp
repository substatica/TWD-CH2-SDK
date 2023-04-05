#include "TWDNightModeLootSpawner.h"

class ATWDNightModeLootSpawnerNetwork;

ATWDNightModeLootSpawnerNetwork* ATWDNightModeLootSpawner::GetSpawnNetwork() const {
    return NULL;
}

ATWDNightModeLootSpawner::ATWDNightModeLootSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AverageSpawnTable = NULL;
    this->RareSpawnTable = NULL;
    this->bRare = false;
    this->SkinOverride = NULL;
    this->PoseOverride = NULL;
}

