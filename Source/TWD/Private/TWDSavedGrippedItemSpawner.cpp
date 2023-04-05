#include "TWDSavedGrippedItemSpawner.h"

void ATWDSavedGrippedItemSpawner::SpawnSavedItem() {
}

ATWDSavedGrippedItemSpawner::ATWDSavedGrippedItemSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GripHand = EControllerHand::Left;
    this->bDisableGravity = false;
}

