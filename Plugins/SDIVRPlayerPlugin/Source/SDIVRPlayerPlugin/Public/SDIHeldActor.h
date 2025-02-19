#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIInteractiveActor.h"
#include "ESDIGripType.h"
#include "ECustomThrowPhysicsMode.h"
#include "SDIGripSwap.h"
#include "SDISyncPoseReceiverInterface.h"
#include "ESDIAxis.h"
#include "EInitialSimulatePhysics.h"
#include "InputCoreTypes.h"
#include "SDIQuatPIDController.h"
#include "SDIMotionHistory.h"
#include "SDIAuxTickFunction.h"
#include "UObject/NoExportTypes.h"
#include "SDIHeldActorGrabbedSignatureDelegate.h"
#include "SDIGripInfo.h"
#include "SDIReplicatedGripInfo.h"
#include "Engine/EngineTypes.h"
#include "SDIAttachmentInfo.h"
#include "SDILoopingHapticEffect.h"
#include "SDIHeldActorDroppedSignatureDelegate.h"
#include "Engine/EngineTypes.h"
#include "ESDIInteractRangeType.h"
#include "SDIHandPoseInfo.h"
#include "SDIHeldActor.generated.h"

class USDIPhysicsMotorComponent;
class USDICollisionChannelIgnoranceComponent;
class UPrimitiveComponent;
class USDIImpactEffectsComponent;
class UObject;
class UAkAudioEvent;
class UObject;
class UActorComponent;
class ASDIPlayerHand;
class AActor;
class USceneComponent;
class APawn;
class ULevel;
class ASDIThrowInputSplineActor;
class USDIWeaponHitCapsuleComponent;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIHeldActor : public ASDIInteractiveActor, public ISDISyncPoseReceiverInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIImpactEffectsComponent* ImpactEffectsComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced)
    UPrimitiveComponent* PrimaryGripCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced)
    UPrimitiveComponent* SecondaryGripCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced)
    UPrimitiveComponent* SimulatePhysicsComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDICollisionChannelIgnoranceComponent* CollisionIgnoranceComp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced)
    USDIPhysicsMotorComponent* PhysicsMotorComp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName PhysicsMotorRigidBodyName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTransform ThirdPersonGripOffset;
    
    UPROPERTY(EditDefaultsOnly)
    bool bDestroyObsoleteRootComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowRangedPickup;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDisablePhysicsCollisionDuringInterpolation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowHoldingWithSecondary;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIgnoreSecondaryGripForIK;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bApplyCosmeticMovementForOneHanded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bMoveToHolderLevelOnPickup;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bMoveToOriginalLevelOnDrop;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabLocationInterpolationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabRotationInterpolationSpeedDeg;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabMaxInterpolationTime;
    
    UPROPERTY(EditDefaultsOnly)
    float ArmLengthReleaseFactor;
    
    UPROPERTY(EditDefaultsOnly)
    float ArmLengthReleaseFactorTime;
    
    UPROPERTY(EditAnywhere)
    UObject* GrabbedFeedback;
    
    UPROPERTY(EditAnywhere)
    UAkAudioEvent* GrabbedSound;
    
    UPROPERTY(EditAnywhere)
    bool bPlayGrabbedEffectsAfterInterpolation;
    
    UPROPERTY(EditAnywhere)
    bool bPlayGrabbedFeedbackAfterInterpolation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bThrowInputSplineUseMinVelocity;
    
    UPROPERTY(EditDefaultsOnly)
    bool bManageNonSDISkelMeshesTick;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAlwaysTickNonSDISkelMeshes;
    
    UPROPERTY(EditDefaultsOnly)
    float NonSDISkelMeshesExtraTickTime;
    
    UPROPERTY(EditAnywhere)
    EInitialSimulatePhysics InitialSimulatePhysics;
    
    UPROPERTY(EditDefaultsOnly)
    bool bCustomThrowPhysics;
    
    UPROPERTY(EditDefaultsOnly)
    ECustomThrowPhysicsMode CustomThrowPhysicsMode;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIQuatPIDController CustomThrowRotationPIDController;
    
    UPROPERTY(EditDefaultsOnly)
    ESDIAxis CustomThrowAxis;
    
    UPROPERTY(EditDefaultsOnly)
    float CustomThrowSpinSpeedDeg;
    
    UPROPERTY(EditDefaultsOnly)
    float CustomThrowPhysicsMinLinearVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDebugReplicationInfo;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PhysicsHandGripInterpolationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandPoseBlendSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bSetHandPoseAfterInterpolation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName NonVRAnimatedAttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIMotionHistory NonVRSimulatedPhysicsComponentMotionHistory;
    
    UPROPERTY()
    FSDIAuxTickFunction NonVRPostPhysicsTick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool HitReactsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDIGripSwap> GripSwaps;
    
    UPROPERTY(Transient)
    uint8 InternalEndPlayReason;
    
    UPROPERTY(Transient)
    FVector PhysicsTimerLinearVelocity;
    
    UPROPERTY(Transient)
    FVector PhysicsTimerAngularVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIPlayerHand* PrimaryHeldHand;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UActorComponent* PrimaryHeldHandGripComp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIGripInfo PrimaryHeldHandGripCompInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand PrimaryHeldHandEnum;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrimaryHeldHandGripLerp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevPrimaryHeldHandGripLerp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIPlayerHand* SecondaryHeldHand;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UActorComponent* SecondaryHeldHandGripComp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIGripInfo SecondaryHeldHandGripCompInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand SecondaryHeldHandEnum;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float SecondaryHeldHandGripLerp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevSecondaryHeldHandGripLerp;
    
    UPROPERTY(Replicated, Transient)
    bool bRepDropIsAttached;
    
    UPROPERTY(BlueprintReadWrite, Replicated, Transient)
    AActor* RepHeldBy;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    AActor* LocalHeldBy;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<AActor> LastHeldBy;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ASDIPlayerHand> LastPrimaryHeldHand;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    TWeakObjectPtr<UActorComponent> LastPrimaryHeldHandGripComp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIGripInfo LastPrimaryHeldHandGripCompInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand LastPrimaryHeldHandEnum;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ASDIPlayerHand> LastSecondaryHeldHand;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    TWeakObjectPtr<UActorComponent> LastSecondaryHeldHandGripComp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIGripInfo LastSecondaryHeldHandGripCompInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand LastSecondaryHeldHandEnum;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepPrimaryHandGripInfo)
    FSDIReplicatedGripInfo RepPrimaryHandGripInfo;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepSecondaryHandGripInfo)
    FSDIReplicatedGripInfo RepSecondaryHandGripInfo;
    
    UPROPERTY(Transient)
    float PrimaryArmLengthReleaseFactorTimer;
    
    UPROPERTY(Transient)
    float SecondaryArmLengthReleaseFactorTimer;
    
    UPROPERTY(Transient)
    float InterpolationDuration;
    
    UPROPERTY(Transient)
    float InterpolationTimer;
    
    UPROPERTY(Transient)
    FTransform InterpolationRelStart;
    
    UPROPERTY(Transient)
    FTransform InterpolationAbsStart;
    
    UPROPERTY(Transient)
    FTransform InterpolationRelEnd;
    
    UPROPERTY(Instanced, Transient)
    USceneComponent* InterpolationEndComp;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIPlayerHand> InterpolationHand;
    
    UPROPERTY(Transient)
    FName InterpolationEndSocket;
    
    UPROPERTY(Instanced, Transient)
    UActorComponent* InterpolationGripComp;
    
    UPROPERTY(Transient)
    FSDIGripInfo InterpolationGripCompInfo;
    
    UPROPERTY(Transient)
    bool bInterpolationUseHandForPivot;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIPlayerHand> GrabbedFeedbackHand;
    
    UPROPERTY(Transient)
    bool bPlayGrabbedEffects;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ULevel> OriginalLevel;
    
    UPROPERTY(Transient)
    FSDIAttachmentInfo DropAttachInfo;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_bRepCustomThrowPhysicsEngaged)
    bool bRepCustomThrowPhysicsEngaged;
    
    UPROPERTY(Transient)
    bool bLocalCustomThrowPhysicsEngaged;
    
    UPROPERTY(Transient)
    float LastDroppedTimestamp;
    
    UPROPERTY(Transient)
    bool bInsideUpdatePhysicsConstraints;
    
    UPROPERTY(Replicated, Transient)
    bool bRepLaunched;
    
    UPROPERTY(Transient)
    bool bSimulatePhysicsComponentGravityEnabledSet;
    
    UPROPERTY(Transient)
    bool bSimulatePhysicsComponentGravityEnabled;
    
    UPROPERTY(Transient)
    TMap<FName, bool> SimulatePhysicsComponentCCDEnabled;
    
    UPROPERTY(Transient)
    FSDILoopingHapticEffect PrimaryGripLoopingHapticEffect;
    
    UPROPERTY(Transient)
    FSDILoopingHapticEffect SecondaryGripLoopingHapticEffect;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIHeldActorGrabbedSignature OnGrabbedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIHeldActorDroppedSignature OnDroppedDelegate;
    
    UPROPERTY(Transient)
    TArray<FOverlapResult> GeoOverlaps;
    
    UPROPERTY(Transient)
    FName OverrideNonVRAnimatedAttachSocket;
    
    UPROPERTY(Transient)
    bool bOverrideNonVRAnimatedAttachSocketSet;
    
    ASDIHeldActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintPure)
    bool WasThrown() const;
    
    UFUNCTION(BlueprintPure)
    bool WasRecentlyDropped(float WithinSeconds) const;
    
    UFUNCTION(BlueprintPure)
    bool WasLaunched() const;
    
    UFUNCTION(BlueprintPure)
    bool WasHeldByPlayerHand() const;
    
    UFUNCTION(BlueprintPure)
    bool WasHeldByPlayer() const;
    
    UFUNCTION(BlueprintPure)
    bool WasHeldByAI() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateTickEnabled();
    
    UFUNCTION(BlueprintNativeEvent)
    bool UpdateThrowInputSpline(ASDIThrowInputSplineActor* Spline, AActor* Destination, float DeltaSeconds);
    
    UFUNCTION()
    void UpdatePhysicsConstraints();
    
    UFUNCTION(BlueprintCallable)
    void UpdateAttachmentInfos(USceneComponent* OldParent, USceneComponent* NewParent, const FName& NewParentSocket);
    
    UFUNCTION(BlueprintNativeEvent)
    bool ThrowInputSplineUseMinVelocity(ASDIThrowInputSplineActor* Spline) const;
    
    UFUNCTION(BlueprintCallable)
    bool TeleportHeldActor(const FTransform& Transform, UActorComponent* GripComp, bool bDropIfHeld, bool bStartPhysics, float PhysicsDelay, FVector ThrowVelocity, FVector AngularVelocityDeg);
    
    UFUNCTION(BlueprintCallable)
    void StopLoopingHapticEffectOnGrip(ESDIGripType GripType);
    
protected:
    UFUNCTION()
    void StartPhysicsFromTimer();
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool ShouldTickBeEnabled() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void SetOverrideNonVRAnimatedAttachSocket(FName Socket);
    
    UFUNCTION(BlueprintCallable)
    void SetHeldActorTransform(const FTransform& Transform, bool bMoveHands);
    
    UFUNCTION(BlueprintCallable)
    void SetForcedCCD(bool bForced);
    
    UFUNCTION(BlueprintCallable)
    bool SetDropAttachInfo(USceneComponent* Parent, FName SocketName, const FTransform& RelTransform);
    
    UFUNCTION(BlueprintCallable)
    void RecreatePhysicsConstraints();
    
    UFUNCTION(BlueprintCallable)
    void PlayHapticEffectOnGrip(ESDIGripType GripType, UObject* HapticEffect, bool bLooping, float Scale, int32 Priority, bool bSynchronized);
    
    UFUNCTION(BlueprintNativeEvent)
    void PlayGrabbedEffects();
    
    UFUNCTION()
    void OnRep_RepSecondaryHandGripInfo(const FSDIReplicatedGripInfo& OldRepSecondaryHandGripInfo);
    
    UFUNCTION()
    void OnRep_RepPrimaryHandGripInfo(const FSDIReplicatedGripInfo& OldRepPrimaryHandGripInfo);
    
    UFUNCTION()
    void OnRep_bRepCustomThrowPhysicsEngaged(bool OldbRepCustomThrowPhysicsEngaged);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnImpactEffectsComponentImpact(USDIImpactEffectsComponent* Comp, const FVector& Velocity, const FVector& NormalImpulse, const FHitResult& Hit);
    
protected:
    UFUNCTION()
    void OnComponentHitCustomThrowPhysics(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void OnActorHitCustomThrowPhysics(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
public:
    UFUNCTION()
    void NonVRTickPostPhysics(UObject* TickOwner, float DeltaTime);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool LaunchHeldActor(const FVector& LinearVelocity, const FVector& AngularVelocityDeg);
    
    UFUNCTION(BlueprintPure)
    bool IsPhysicsMotorActive() const;
    
    UFUNCTION(BlueprintPure)
    bool IsInterpolating() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHeldByPlayerHand() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHeldByPlayer() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHeldByAI() const;
    
    UFUNCTION(BlueprintPure)
    bool IsBeingHeld() const;
    
    UFUNCTION(BlueprintPure)
    bool IgnoreSecondaryGripForIK() const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool HandleGripSwap(ASDIPlayerHand* hand, const FSDIGripSwap& GripSwap);
    
    UFUNCTION(BlueprintCallable)
    bool GrabWithHand(ASDIPlayerHand* hand, bool bPrimary, ESDIInteractRangeType RangeType, bool bInterpolate, bool bUseDesiredGripInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Grab(AActor* Grabber, EControllerHand hand, bool bPrimary, ESDIInteractRangeType RangeType, ASDIPlayerHand* HandPtr, bool bInterpolate, bool bUseDesiredGripInfo);
    
    UFUNCTION(BlueprintNativeEvent)
    void GetThrowInfo(ASDIPlayerHand* OldPrimaryHeldHand, EControllerHand OldPrimaryHeldHandEnum, ASDIPlayerHand* OldSecondaryHeldHand, EControllerHand OldSecondaryHeldHandEnum, FTransform& OutTransform, FVector& OutLinearVelocity, FVector& OutAngularVelocity, bool& bOutCustomThrowPhysicsEngaged);
    
    UFUNCTION(BlueprintPure)
    UPrimitiveComponent* GetSimulatePhysicsComponent() const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* GetSecondaryHeldHandGripComp(FSDIGripInfo& OutGripInfo) const;
    
    UFUNCTION(BlueprintPure)
    EControllerHand GetSecondaryHeldHandEnum() const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetSecondaryHeldHand() const;
    
    UFUNCTION(BlueprintPure)
    UPrimitiveComponent* GetSecondaryGripCollision() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetRepHeldBy() const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* GetPrimaryHeldHandGripComp(FSDIGripInfo& OutGripInfo) const;
    
    UFUNCTION(BlueprintPure)
    EControllerHand GetPrimaryHeldHandEnum() const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetPrimaryHeldHand() const;
    
    UFUNCTION(BlueprintPure)
    UPrimitiveComponent* GetPrimaryGripCollision() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetLocalHeldBy() const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* GetLastSecondaryHeldHandGripComp(FSDIGripInfo& OutGripInfo) const;
    
    UFUNCTION(BlueprintPure)
    EControllerHand GetLastSecondaryHeldHandEnum() const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetLastSecondaryHeldHand() const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* GetLastPrimaryHeldHandGripComp(FSDIGripInfo& OutGripInfo) const;
    
    UFUNCTION(BlueprintPure)
    EControllerHand GetLastPrimaryHeldHandEnum() const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetLastPrimaryHeldHand() const;
    
    UFUNCTION(BlueprintPure)
    APawn* GetLastHeldByPawn() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetLastHeldBy() const;
    
    UFUNCTION(BlueprintPure)
    float GetLastDroppedTimestamp() const;
    
    UFUNCTION(BlueprintPure)
    bool GetHeldState(bool& bOutIsHeldByPlayerHand, bool& bOutWasThrown, bool& bOutWasLaunched) const;
    
    UFUNCTION(BlueprintPure)
    APawn* GetHeldByPawn() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetHeldBy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure=false)
    UActorComponent* GetGripPoint(const FTransform& HandTransform, EControllerHand hand, const ASDIPlayerHand* HandPtr, ESDIGripType GripType, ESDIInteractRangeType RangeType, FSDIHandPoseInfo& OutHandPose, FSDIGripInfo& OutGripInfo, bool bUseDesiredGripInfo, bool bDistanceOnly) const;
    
    UFUNCTION(BlueprintNativeEvent)
    UObject* GetGrabbedFeedback(ASDIPlayerHand* hand, float InterpolationTime) const;
    
    UFUNCTION(BlueprintPure)
    FVector GetAvgGripLocation(ESDIGripType GripType) const;
    
    UFUNCTION(BlueprintCallable)
    void DroppedFromSpawn(AActor* SimulateLastHeldBy);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void Dropped();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Drop();
    
    UFUNCTION(BlueprintPure)
    bool DisablePhysicsCollisionDuringInterpolation() const;
    
    UFUNCTION()
    void DisableNonSDISkelMeshTickFromTimer();
    
    UFUNCTION(BlueprintCallable)
    void ClearOverrideNonVRAnimatedAttachSocket();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ClearLaunched();
    
    UFUNCTION(BlueprintCallable)
    void ClearDropAttachInfo();
    
    UFUNCTION(BlueprintCallable)
    bool ChangeHandGrip(ASDIPlayerHand* hand, UActorComponent* NewGripComp, FSDIGripInfo NewGripInfo, bool bInterpolate, bool bUseHandForPivot);
    
    UFUNCTION(BlueprintCallable)
    bool ChangeGrip(EControllerHand hand, UActorComponent* NewGripComp, FSDIGripInfo NewGripInfo, bool bInterpolate, bool bUseHandForPivot);
    
    UFUNCTION(BlueprintNativeEvent)
    bool CanSwapGrips(ASDIPlayerHand* hand) const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool CanHitComponentApplyDamage(const USDIWeaponHitCapsuleComponent* HitComponent) const;
    
    UFUNCTION(BlueprintCallable)
    void AttachToWithGripTransform(USceneComponent* Parent, FName SocketName, FTransform GripTransform, bool bInterpolate, UActorComponent* GripComp, FSDIGripInfo GripInfo, ASDIPlayerHand* hand, bool bUseHandForPivot);
    
    UFUNCTION(BlueprintCallable)
    void AttachToWithGripComp(USceneComponent* Parent, FName SocketName, UActorComponent* GripComp, FSDIGripInfo GripInfo, bool bInterpolate, ASDIPlayerHand* hand);
    
    UFUNCTION(BlueprintCallable)
    void AttachToHandWithGripTransform(ASDIPlayerHand* hand, FTransform GripTransform, bool bInterpolate, UActorComponent* GripComp, FSDIGripInfo GripInfo, bool bUseHandForPivot);
    
    UFUNCTION(BlueprintCallable)
    void AttachToHandWithGripComp(ASDIPlayerHand* hand, UActorComponent* GripComp, FSDIGripInfo GripInfo, bool bInterpolate, bool bUseHandForPivot);
    
    UFUNCTION(BlueprintPure)
    bool AllowRangedPickup() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddImpulse(FVector Impulse, FName BoneName, bool bVelChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddAngularImpulseInRadians(FVector Impulse, FName BoneName, bool bVelChange);
    
    
    // Fix for true pure virtual functions not being implemented
};

