#include "SDITuningAsyncTriggerSphere.h"
#include "Net/UnrealNetwork.h"

void ASDITuningAsyncTriggerSphere::OnRep_RepTuningModifiers() {
}

void ASDITuningAsyncTriggerSphere::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDITuningAsyncTriggerSphere, RepTuningModifiers);
}

ASDITuningAsyncTriggerSphere::ASDITuningAsyncTriggerSphere() {
}

