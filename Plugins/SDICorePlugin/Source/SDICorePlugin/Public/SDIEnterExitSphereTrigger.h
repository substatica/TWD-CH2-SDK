#pragma once
#include "CoreMinimal.h"
#include "SDIEnterExitTrigger.h"
#include "SDIEnterExitSphereTrigger.generated.h"

class USphereComponent;

UCLASS()
class SDICOREPLUGIN_API ASDIEnterExitSphereTrigger : public ASDIEnterExitTrigger {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, VisibleAnywhere)
    USphereComponent* EnterCollisionComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USphereComponent* ExitCollisionComponent;
    
public:
    ASDIEnterExitSphereTrigger();
};

