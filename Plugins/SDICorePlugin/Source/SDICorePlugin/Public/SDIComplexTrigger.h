#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDITriggerActorBase.h"
#include "Engine/EngineTypes.h"
#include "SDIComplexTrigger.generated.h"

class UPrimitiveComponent;
class AActor;

UCLASS()
class SDICOREPLUGIN_API ASDIComplexTrigger : public ASDITriggerActorBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    TArray<FComponentReference> Collisions;
    
    UPROPERTY(Instanced, Transient)
    TArray<TWeakObjectPtr<UPrimitiveComponent>> CachedCollisions;
    
public:
    ASDIComplexTrigger(const FObjectInitializer& ObjectInitializer);
    UFUNCTION()
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

