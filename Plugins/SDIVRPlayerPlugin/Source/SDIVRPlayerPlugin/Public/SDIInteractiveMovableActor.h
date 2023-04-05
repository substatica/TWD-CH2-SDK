#pragma once
#include "CoreMinimal.h"
#include "SDIInteractiveActorStaticMesh.h"
#include "RFloatExp.h"
#include "SDIQuatPIDController.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIInteractiveMovableActor.generated.h"

class ASDIPlayerHand;
class UPhysicsConstraintComponent;
class USDICollisionChannelIgnoranceComponent;
class APhysicsVolume;
class UPrimitiveComponent;
class AActor;
class APawn;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIInteractiveMovableActor : public ASDIInteractiveActorStaticMesh {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UPhysicsConstraintComponent* PhysicsConstraint;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDICollisionChannelIgnoranceComponent* CollisionIgnoranceComp;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bCanBeMoved;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAxialMovementOnly;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bSlopeTransitionAssistance;
    
    UPROPERTY(EditAnywhere)
    FSDIQuatPIDController SlopeRotationPIDController;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SlopeTransitionForce;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAllowMantle;
    
    UPROPERTY(EditAnywhere)
    FSDIQuatPIDController MantleRotationPIDController;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator HandOffsetSpring;
    
    UPROPERTY(EditAnywhere)
    FRFloatExp HandOffsetRange;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float MaxMovementVelocity;
    
    UPROPERTY(EditAnywhere)
    float MovementAcceleration;
    
    UPROPERTY(EditAnywhere)
    float MovementDeceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Buoyancy;
    
    UPROPERTY(EditAnywhere)
    FSDIQuatPIDController WaterRotationPIDController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FluidFrictionMultiplier;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ASDIPlayerHand>, FHitResult> GrippingHands;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<APhysicsVolume>> OverlappedPhysicsVolumes;
    
    UPROPERTY(Transient)
    bool bCustomPhysicsBeingMantled;
    
    UPROPERTY(Transient)
    bool bCustomPhysicsInWater;
    
    UPROPERTY(Transient)
    float CustomPhysicsFluidFriction;
    
    UPROPERTY(Transient)
    float CustomPhysicsImmersionDepth;
    
    UPROPERTY(Transient)
    float CustomPhysicsGravityZ;
    
    UPROPERTY(Transient)
    uint32 CurrentFloorNormalFrame;
    
    UPROPERTY(Transient)
    FVector CurrentFloorNormal;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult SlopeTransitionImpact;
    
    UPROPERTY(Transient)
    FVector HandMovementVelocity;
    
    UPROPERTY(Transient)
    FVector StickMovementVelocity;
    
public:
    ASDIInteractiveMovableActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateTickEnabled();
    
protected:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool ShouldTickBeEnabled() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void SetProjectedLinearVelocity(FVector DesiredVelocity);
    
    UFUNCTION(BlueprintCallable)
    void SetCanBeMoved(bool bMovable);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowMantle(bool bMantle);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseGrips();
    
protected:
    UFUNCTION(BlueprintPure)
    FVector ProjectVectorIntoMovementPlane(const FVector& Vector) const;
    
    UFUNCTION()
    void OnPhysicsComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName);
    
    UFUNCTION()
    void OnPhysicsComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);
    
    UFUNCTION()
    void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsStandingOn(const APawn* Pawn) const;
    
    UFUNCTION(BlueprintPure)
    bool IsMantlingOn(const APawn* Pawn) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInWater() const;
    
    UFUNCTION(BlueprintPure)
    bool IsBeingGripped() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetGrippedBy() const;
    
protected:
    UFUNCTION(BlueprintPure)
    FVector GetCurrentFloorNormal() const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool CanBeGrabbed(ASDIPlayerHand* hand) const;
    
public:
    UFUNCTION(BlueprintNativeEvent)
    bool AllowHandMove(ASDIPlayerHand* hand) const;
    
};

