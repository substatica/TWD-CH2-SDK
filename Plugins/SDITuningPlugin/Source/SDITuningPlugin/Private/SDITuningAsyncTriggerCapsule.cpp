#include "SDITuningAsyncTriggerCapsule.h"
#include "Net/UnrealNetwork.h"

void ASDITuningAsyncTriggerCapsule::OnRep_RepTuningModifiers() {
}

void ASDITuningAsyncTriggerCapsule::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDITuningAsyncTriggerCapsule, RepTuningModifiers);
}

ASDITuningAsyncTriggerCapsule::ASDITuningAsyncTriggerCapsule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

