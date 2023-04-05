#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TWDAutomationSplineActor.generated.h"

class USplineComponent;

UCLASS()
class ATWDAutomationSplineActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, VisibleAnywhere)
    USplineComponent* SplineComponent;
    
public:
    ATWDAutomationSplineActor(const FObjectInitializer& ObjectInitializer);
};

