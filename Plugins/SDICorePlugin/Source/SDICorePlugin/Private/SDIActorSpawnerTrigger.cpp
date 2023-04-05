#include "SDIActorSpawnerTrigger.h"

class AActor;

void ASDIActorSpawnerTrigger::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActors) {
}

void ASDIActorSpawnerTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActors) {
}

ASDIActorSpawnerTrigger::ASDIActorSpawnerTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnNetwork = NULL;
}

