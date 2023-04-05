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

ATWDPersistentLevel::ATWDPersistentLevel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bPersistenceHandled = false;
}

