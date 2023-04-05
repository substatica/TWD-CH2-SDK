#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "SDIReplicatedTuningModifier.h"
#include "SDITuningTriggerBox.generated.h"

UCLASS()
class SDITUNINGPLUGIN_API ASDITuningTriggerBox : public ATriggerBox, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepTuningModifiers)
    TArray<FSDIReplicatedTuningModifier> RepTuningModifiers;
    
public:
    ASDITuningTriggerBox();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_RepTuningModifiers();
    
    
    // Fix for true pure virtual functions not being implemented
};

