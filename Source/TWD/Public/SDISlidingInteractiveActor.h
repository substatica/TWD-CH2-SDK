#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "SDISlidingInteractiveActor.generated.h"

class UPrimitiveComponent;
class ASDIHingedActorHandle;
class ASDIPlayerHand;

UCLASS()
class TWD_API ASDISlidingInteractiveActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced)
    UPrimitiveComponent* SlidingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ASDIHingedActorHandle* HandleActor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector LocalClosedPosition;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector LocalOpenPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxOpenSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Deceleration;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ASDIPlayerHand* PlayerHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsLocked;
    
public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float CurrentOpenPercentage;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float CurrentSpeed;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bIsClosed;
    
    ASDISlidingInteractiveActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetLocked(bool bWillLock);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnSlidingObjectMoveEnd();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnSlidingObjectMoved(float CurrentPosition);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsLocked() const;
    
};

