#pragma once
#include "CoreMinimal.h"
#include "SDIGameplayTagActor.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "SDITuningGameplayTagActor.generated.h"

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDITuningGameplayTagActor : public ASDIGameplayTagActor, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
public:
    ASDITuningGameplayTagActor(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

