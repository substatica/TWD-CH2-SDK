#pragma once
#include "CoreMinimal.h"
#include "SDIAsyncTriggerBox.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "SDIReplicatedTuningModifier.h"
#include "SDITuningAsyncTriggerBox.generated.h"

UCLASS()
class SDITUNINGPLUGIN_API ASDITuningAsyncTriggerBox : public ASDIAsyncTriggerBox, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepTuningModifiers)
    TArray<FSDIReplicatedTuningModifier> RepTuningModifiers;
    
public:
    ASDITuningAsyncTriggerBox();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_RepTuningModifiers();
    
    
    // Fix for true pure virtual functions not being implemented
};

