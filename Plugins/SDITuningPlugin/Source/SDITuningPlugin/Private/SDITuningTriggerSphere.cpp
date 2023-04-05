#include "SDITuningTriggerSphere.h"
#include "Net/UnrealNetwork.h"

void ASDITuningTriggerSphere::OnRep_RepTuningModifiers() {
}

void ASDITuningTriggerSphere::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDITuningTriggerSphere, RepTuningModifiers);
}

ASDITuningTriggerSphere::ASDITuningTriggerSphere() {
}

