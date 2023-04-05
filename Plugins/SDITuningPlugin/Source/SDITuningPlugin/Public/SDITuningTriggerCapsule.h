#pragma once
#include "CoreMinimal.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "Engine/TriggerCapsule.h"
#include "SDIReplicatedTuningModifier.h"
#include "SDITuningTriggerCapsule.generated.h"

UCLASS()
class SDITUNINGPLUGIN_API ASDITuningTriggerCapsule : public ATriggerCapsule, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepTuningModifiers)
    TArray<FSDIReplicatedTuningModifier> RepTuningModifiers;
    
public:
    ASDITuningTriggerCapsule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_RepTuningModifiers();
    
    
    // Fix for true pure virtual functions not being implemented
};

