#include "TWDPersistentLevel.h"

class AActor;

void ATWDPersistentLevel::WaitForLevelsToBeLoaded() {
}



void ATWDPersistentLevel::HandlePersistence() {
}

void ATWDPersistentLevel::AddExcludedActor(AActor* ActorToExclude) {
}

void ATWDPersistentLevel::AddDeletionExcludedActor(AActor* ActorToExclude) {
}

ATWDPersistentLevel::ATWDPersistentLevel() {
    this->bPersistenceHandled = false;
}

