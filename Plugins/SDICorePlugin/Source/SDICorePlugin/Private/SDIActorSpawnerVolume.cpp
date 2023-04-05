#include "SDIActorSpawnerVolume.h"

ASDIActorSpawnerVolume::ASDIActorSpawnerVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActiveSpawnerVolumeIndex = -1;
    this->SpawnerModel = NULL;
}

