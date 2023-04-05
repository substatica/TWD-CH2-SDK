#pragma once
#include "CoreMinimal.h"
#include "SDIEnterExitTrigger.h"
#include "SDIEnterExitBoxTrigger.generated.h"

class UBoxComponent;

UCLASS()
class SDICOREPLUGIN_API ASDIEnterExitBoxTrigger : public ASDIEnterExitTrigger {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, VisibleAnywhere)
    UBoxComponent* EnterCollisionComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UBoxComponent* ExitCollisionComponent;
    
public:
    ASDIEnterExitBoxTrigger(const FObjectInitializer& ObjectInitializer);
};

