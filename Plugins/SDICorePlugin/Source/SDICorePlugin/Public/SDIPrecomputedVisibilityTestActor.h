#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SDIPrecomputedVisibilityTestActor.generated.h"

class UCapsuleComponent;

UCLASS(Transient)
class SDICOREPLUGIN_API ASDIPrecomputedVisibilityTestActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(EditInstanceOnly)
    bool bEnablePrecomputedVisibility;
    
protected:
    UPROPERTY(Instanced)
    UCapsuleComponent* CapsuleComponent;
    
public:
    ASDIPrecomputedVisibilityTestActor(const FObjectInitializer& ObjectInitializer);
};

