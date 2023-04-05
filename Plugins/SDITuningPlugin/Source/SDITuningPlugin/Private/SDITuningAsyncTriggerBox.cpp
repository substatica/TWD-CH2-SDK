#include "SDITuningAsyncTriggerBox.h"
#include "Net/UnrealNetwork.h"

void ASDITuningAsyncTriggerBox::OnRep_RepTuningModifiers() {
}

void ASDITuningAsyncTriggerBox::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDITuningAsyncTriggerBox, RepTuningModifiers);
}

ASDITuningAsyncTriggerBox::ASDITuningAsyncTriggerBox() {
}

