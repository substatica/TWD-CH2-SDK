#pragma once
#include "CoreMinimal.h"
#include "SDIReplicatedTuningModifier.h"
#include "SDIAsyncTriggerCapsule.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "SDITuningAsyncTriggerCapsule.generated.h"

UCLASS()
class SDITUNINGPLUGIN_API ASDITuningAsyncTriggerCapsule : public ASDIAsyncTriggerCapsule, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepTuningModifiers)
    TArray<FSDIReplicatedTuningModifier> RepTuningModifiers;
    
public:
    ASDITuningAsyncTriggerCapsule();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_RepTuningModifiers();
    
    
    // Fix for true pure virtual functions not being implemented
};

