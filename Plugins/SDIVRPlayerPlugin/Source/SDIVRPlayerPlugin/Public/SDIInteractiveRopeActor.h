#pragma once
#include "CoreMinimal.h"
#include "SDIPooledObjectBlueprintInterface.h"
#include "SDIInteractiveActor.h"
#include "SDIRopeInterpolationConstraint.h"
#include "SDIPooledObjectInterface.h"
#include "SDIPooledObjectData.h"
#include "SDIInteractiveRopeActor.generated.h"

class ASDIPlayerHand;
class USDIInteractiveRopeComponent;
class UAkAudioEvent;
class APawn;
class ASDIObjectPool;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIInteractiveRopeActor : public ASDIInteractiveActor, public ISDIPooledObjectInterface, public ISDIPooledObjectBlueprintInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIInteractiveRopeComponent* RopeComponent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bCanBeUsedForMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAllowRangedGrab;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxRangedGrabDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxRangedGrabDistanceWhenHeld;
    
    UPROPERTY(EditAnywhere)
    float RangedGrabInterpolationSpeed;
    
    UPROPERTY(EditAnywhere)
    bool bSoftRangedGrabInterpolationConstraint;
    
    UPROPERTY(EditAnywhere)
    float SoftRangedGrabInterpolationConstraintStiffness;
    
    UPROPERTY(EditAnywhere)
    float SoftRangedGrabInterpolationConstraintDamping;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* GripAudioEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* ReleaseAudioEvent;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ASDIPlayerHand>, FSDIRopeInterpolationConstraint> InterpolationConstraints;
    
private:
    UPROPERTY(Transient)
    FSDIPooledObjectData PooledObjectData;
    
public:
    ASDIInteractiveRopeActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateTickEnabled();
    
protected:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool ShouldTickBeEnabled() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCanBeUsedForMovement(bool bMovement);
    
    UFUNCTION(BlueprintPure)
    bool IsStruggleActive(bool& bOutIsHeld, bool& bOutIsTaut, bool& bOutAllowIncrement, float& OutStruggleAmount);
    
    UFUNCTION(BlueprintPure)
    bool IsBeingHeld() const;
    
    UFUNCTION(BlueprintPure)
    bool IsBeingClimbed() const;
    
    UFUNCTION(BlueprintPure)
    APawn* GetHeldBy() const;
    
    UFUNCTION(BlueprintCallable)
    void Drop();
    
    UFUNCTION(BlueprintPure)
    bool CanBeUsedForMovement() const;
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void ReturnToPoolNextFrame() override PURE_VIRTUAL(ReturnToPoolNextFrame,);
    
    UFUNCTION(BlueprintCallable)
    void ReturnToPool() override PURE_VIRTUAL(ReturnToPool,);
    
    UFUNCTION(BlueprintCallable)
    bool IsInsidePool() const override PURE_VIRTUAL(IsInsidePool, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsFromPool() const override PURE_VIRTUAL(IsFromPool, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsBeingReturnedToPoolNextFrame() const override PURE_VIRTUAL(IsBeingReturnedToPoolNextFrame, return false;);
    
    UFUNCTION(BlueprintCallable)
    ASDIObjectPool* GetPool() const override PURE_VIRTUAL(GetPool, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    float GetAcquiredTimestamp() const override PURE_VIRTUAL(GetAcquiredTimestamp, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    void CancelReturnToPoolNextFrame() override PURE_VIRTUAL(CancelReturnToPoolNextFrame,);
    
};

