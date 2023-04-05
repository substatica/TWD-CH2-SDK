#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDITriggerActorBase.h"
#include "Engine/EngineTypes.h"
#include "SDIEnterExitTrigger.generated.h"

class USDIAsyncOverlapEventGeneratorComponent;
class UPrimitiveComponent;
class AActor;

UCLASS()
class SDICOREPLUGIN_API ASDIEnterExitTrigger : public ASDITriggerActorBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    FComponentReference EnterCollision;
    
    UPROPERTY(EditAnywhere)
    FComponentReference ExitCollision;
    
    UPROPERTY(Instanced)
    USDIAsyncOverlapEventGeneratorComponent* EnterOverlapGenerator;
    
    UPROPERTY(Instanced)
    USDIAsyncOverlapEventGeneratorComponent* ExitOverlapGenerator;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<UPrimitiveComponent> CachedEnterCollision;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<UPrimitiveComponent> CachedExitCollision;
    
public:
    ASDIEnterExitTrigger();
    UFUNCTION()
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

