#include "SDITuningTriggerBox.h"
#include "Net/UnrealNetwork.h"

void ASDITuningTriggerBox::OnRep_RepTuningModifiers() {
}

void ASDITuningTriggerBox::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDITuningTriggerBox, RepTuningModifiers);
}

ASDITuningTriggerBox::ASDITuningTriggerBox() {
}

