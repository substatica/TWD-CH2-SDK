#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ESDITriggerFilterType.h"
#include "SDIActorActivatedSignatureDelegate.h"
#include "SDIActorDeactivatedSignatureDelegate.h"
#include "SDITriggerActorBase.generated.h"

class UPrimitiveComponent;

UCLASS(Abstract)
class SDICOREPLUGIN_API ASDITriggerActorBase : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bIsActive;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    ESDITriggerFilterType TriggerFilter;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIActorActivatedSignature OnEnter;
    
    UPROPERTY(BlueprintAssignable)
    FSDIActorDeactivatedSignature OnExit;
    
protected:
    UPROPERTY(Transient)
    TArray<AActor*> Occupants;
    
public:
    ASDITriggerActorBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetActive(bool bActive);
    
    UFUNCTION(BlueprintPure)
    bool IsOccupied() const;
    
    UFUNCTION(BlueprintPure)
    bool IsOccupant(AActor* Actor) const;
    
    UFUNCTION(BlueprintPure)
    TArray<AActor*> GetOccupants() const;
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void Exited(AActor* OtherActor, int32 NumOccupants);
    
    UFUNCTION(BlueprintNativeEvent)
    void Entered(AActor* OtherActor, int32 NumOccupants);
    
    UFUNCTION(BlueprintNativeEvent)
    bool AllowEntrance(AActor* OtherActor, UPrimitiveComponent* OtherComp) const;
    
};

