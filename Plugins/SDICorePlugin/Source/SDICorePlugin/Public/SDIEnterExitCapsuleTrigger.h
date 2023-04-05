#pragma once
#include "CoreMinimal.h"
#include "SDIEnterExitTrigger.h"
#include "SDIEnterExitCapsuleTrigger.generated.h"

class UCapsuleComponent;

UCLASS()
class SDICOREPLUGIN_API ASDIEnterExitCapsuleTrigger : public ASDIEnterExitTrigger {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, VisibleAnywhere)
    UCapsuleComponent* EnterCollisionComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UCapsuleComponent* ExitCollisionComponent;
    
public:
    ASDIEnterExitCapsuleTrigger(const FObjectInitializer& ObjectInitializer);
};

