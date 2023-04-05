#include "SDITriggerActorBase.h"

class AActor;
class UPrimitiveComponent;

void ASDITriggerActorBase::SetActive(bool bActive) {
}

bool ASDITriggerActorBase::IsOccupied() const {
    return false;
}

bool ASDITriggerActorBase::IsOccupant(AActor* Actor) const {
    return false;
}

TArray<AActor*> ASDITriggerActorBase::GetOccupants() const {
    return TArray<AActor*>();
}

void ASDITriggerActorBase::Exited_Implementation(AActor* OtherActor, int32 NumOccupants) {
}

void ASDITriggerActorBase::Entered_Implementation(AActor* OtherActor, int32 NumOccupants) {
}

bool ASDITriggerActorBase::AllowEntrance_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp) const {
    return false;
}

ASDITriggerActorBase::ASDITriggerActorBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsActive = true;
    this->TriggerFilter = ESDITriggerFilterType::AllPawns;
}

