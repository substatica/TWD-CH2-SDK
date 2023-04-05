#pragma once
#include "CoreMinimal.h"
#include "SDIInventoryActor.h"
#include "SDITuningAccumulator.h"
#include "SDITuningInterface.h"
#include "SDITuningInventoryActor.generated.h"

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDITuningInventoryActor : public ASDIInventoryActor, public ISDITuningInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
public:
    ASDITuningInventoryActor(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

