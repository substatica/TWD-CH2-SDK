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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USDIAsyncOverlapEventGeneratorComponent* EnterOverlapGenerator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USDIAsyncOverlapEventGeneratorComponent* ExitOverlapGenerator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> CachedEnterCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> CachedExitCollision;
    
public:
    ASDIEnterExitTrigger(const FObjectInitializer& ObjectInitializer);
    UFUNCTION()
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

