#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "SDIReplicatedTuningModifier.h"
#include "SDITuningPawn.generated.h"

UCLASS()
class SDITUNINGPLUGIN_API ASDITuningPawn : public APawn, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepTuningModifiers)
    TArray<FSDIReplicatedTuningModifier> RepTuningModifiers;
    
public:
    ASDITuningPawn(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_RepTuningModifiers();
    
    
    // Fix for true pure virtual functions not being implemented
};

