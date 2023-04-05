#include "TWDSpawnControlVolume.h"
#include "Components/BoxComponent.h"

void ATWDSpawnControlVolume::RevertLastCommand() {
}

void ATWDSpawnControlVolume::GatherAllSpawners() {
}

void ATWDSpawnControlVolume::DisableAllSpawners() {
}

ATWDSpawnControlVolume::ATWDSpawnControlVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bDisableOnLoad = true;
    this->Volume = CreateDefaultSubobject<UBoxComponent>(TEXT("ControlVolume"));
    this->bEnabled = true;
}

