#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TWDAutomationCoordinator.generated.h"

class ASDIPath;
class ATWDAutomationSplineActor;
class ATargetPoint;

UCLASS()
class ATWDAutomationCoordinator : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
    TArray<TSoftObjectPtr<ATargetPoint>> ObservationPoints;
    
    UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
    TSoftObjectPtr<ATWDAutomationSplineActor> WalkThroughSplineActor;
    
    UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
    TSoftObjectPtr<ASDIPath> WalkThroughPath;
    
public:
    ATWDAutomationCoordinator(const FObjectInitializer& ObjectInitializer);
};

