#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "SDIReplicatedTuningModifier.h"
#include "SDITuningTriggerSphere.generated.h"

UCLASS()
class SDITUNINGPLUGIN_API ASDITuningTriggerSphere : public ATriggerSphere, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepTuningModifiers)
    TArray<FSDIReplicatedTuningModifier> RepTuningModifiers;
    
public:
    ASDITuningTriggerSphere(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_RepTuningModifiers();
    
    
    // Fix for true pure virtual functions not being implemented
};

