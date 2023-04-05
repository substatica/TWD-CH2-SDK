#include "SDITuningTriggerCapsule.h"
#include "Net/UnrealNetwork.h"

void ASDITuningTriggerCapsule::OnRep_RepTuningModifiers() {
}

void ASDITuningTriggerCapsule::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDITuningTriggerCapsule, RepTuningModifiers);
}

ASDITuningTriggerCapsule::ASDITuningTriggerCapsule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

