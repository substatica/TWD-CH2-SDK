#pragma once
#include "CoreMinimal.h"
#include "SDIMeleeWeaponStabInterface.h"
#include "SDISkinnedPlayerHandBase.h"
#include "SDIPlayerHandInteractComponentEntry.h"
#include "GameplayTagAssetInterface.h"
#include "ESDIPlayerHandGripInputMode.h"
#include "SDIReplicatedStimAndResponseInterfaceDataContainer.h"
#include "SDIDynamicGameplayTagAssetInterface.h"
#include "SDIPlayerHandLock.h"
#include "SDIStimAndResponseInterface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerHandGrabbedActorSignatureDelegate.h"
#include "SDIHandPoseInfo.h"
#include "ESDIInteractiveInteractType.h"
#include "GameplayTagContainer.h"
#include "SDIStimAndResponseInterfaceDataContainer.h"
#include "SDIGripInfo.h"
#include "SDIPlayerHandStimulusChangedSignatureDelegate.h"
#include "SDIPlayerHandDroppedActorSignatureDelegate.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIMeleeWeaponStabStartedSignatureDelegate.h"
#include "UObject/NoExportTypes.h"
#include "SDIMeleeWeaponStabCompletedSignatureDelegate.h"
#include "SDIMeleeWeaponStabInterfaceData.h"
#include "SDIMeleeWeaponStabEndedSignatureDelegate.h"
#include "ESDIInteractRangeType.h"
#include "Engine/SpringInterpolator.h"
#include "ESDIHandGripState.h"
#include "ESDIGripType.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "SDIPlayerHand.generated.h"

class UObject;
class USDIPlayerHandPhysicalInteractComponent;
class UPhysicsHandleComponent;
class USDIPlayerHandInteractComponent;
class UPhysicsConstraintComponent;
class UObject;
class UCurveFloat;
class ASDIThrowInputSplineActor;
class USDIWeaponHitCapsuleComponent;
class USDITriggerResistanceFeedbackEffect_Curve;
class USceneComponent;
class USDIMeleeWeaponHitCapsuleComponent;
class AActor;
class UActorComponent;
class UPrimitiveComponent;
class ASDIInventoryActor;
class UDamageType;
class ASDIPlayerHand;
class AController;
class ASDIInventorySlot;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIPlayerHand : public ASDISkinnedPlayerHandBase, public IGameplayTagAssetInterface, public ISDIDynamicGameplayTagAssetInterface, public ISDIStimAndResponseInterface, public ISDIMeleeWeaponStabInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPlayerHandInteractComponent* InteractComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPlayerHandInteractComponent* RangedInteractComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced)
    USDIPlayerHandPhysicalInteractComponent* PhysicalInteractComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UPhysicsHandleComponent* PhysicsHandle;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UPhysicsConstraintComponent* GripPhysicsConstraint;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UPhysicsConstraintComponent* NonVRPhysicsConstraint;
    
    UPROPERTY(EditDefaultsOnly)
    bool bCollideHeldActor;
    
    UPROPERTY(EditDefaultsOnly)
    bool bCollidePhysicalInteractComponent;
    
    UPROPERTY(EditDefaultsOnly)
    float CollidePhysicalInteractComponentShapeInflation;
    
    UPROPERTY(EditDefaultsOnly)
    FName HeldActorAttachPointSocket;
    
    UPROPERTY(EditDefaultsOnly)
    float GripPressThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    float GripReleaseThreshold;
    
    UPROPERTY(Config, VisibleAnywhere)
    float GripCapacitiveTouchPressThreshold;
    
    UPROPERTY(Config, VisibleAnywhere)
    float GripCapacitiveTouchReleaseThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    float KnucklesGripPressThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    float KnucklesGripReleaseThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    bool bGripValidInteractionHighlightsOnly;
    
    UPROPERTY(EditDefaultsOnly)
    bool bGripAllowOffscreenRanged;
    
    UPROPERTY(EditDefaultsOnly)
    bool bGripAllowOffscreenClose;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowRangedGrip;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowRangedInteract;
    
    UPROPERTY(EditDefaultsOnly)
    float GripOffScreenAngleDeg;
    
    UPROPERTY(EditDefaultsOnly)
    float InteractPressThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    float InteractReleaseThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    bool bInteractValidInteractionHighlightsOnly;
    
    UPROPERTY(EditDefaultsOnly)
    bool bUseVisualHandsForDesiredHandRotation;
    
    UPROPERTY(EditDefaultsOnly)
    float MaxSimulatingPhysicsMassToPickup;
    
    UPROPERTY(EditDefaultsOnly)
    UObject* GrabPhysicsFeedback;
    
    UPROPERTY(EditDefaultsOnly)
    float ThrowAvgVelocityBlend;
    
    UPROPERTY(EditDefaultsOnly)
    float ThrowAvgVelocityTime;
    
    UPROPERTY(EditDefaultsOnly)
    float ThrowVelocityMultiplier;
    
    UPROPERTY(EditDefaultsOnly)
    UCurveFloat* ThrowVelocityMultiplierMassCurve;
    
    UPROPERTY(EditDefaultsOnly)
    UCurveFloat* ThrowMaxVelocityMassCurve;
    
    UPROPERTY(EditDefaultsOnly)
    float ThrowVelocityPhysicsOverrideBlend;
    
    UPROPERTY(EditDefaultsOnly)
    float ThrowinginReleaseTimeOffset;
    
    UPROPERTY(EditDefaultsOnly)
    float ThrowinginReleaseTimeOffsetQuestLink;
    
    UPROPERTY(EditDefaultsOnly)
    TSoftClassPtr<ASDIThrowInputSplineActor> ThrowInputSplineClass;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowTeleportWhileGrippingWorld;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowTeleportWhileGrippingPhysics;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowTeleportWhileGrippingInteractive;
    
    UPROPERTY(EditDefaultsOnly)
    float TeleportMaxSimulatingPhysicsMass;
    
    UPROPERTY(EditDefaultsOnly)
    bool bSimulateHeldActorWeight;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedHeldActorWeightMinMass;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedGravityTorqueAngularAcc;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedGravityLinearAcc;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedInertiaTorqueAcc;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedInertiaLinearAcc;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedAngularVelocityMax;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedAngularVelocityDecay;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedLinearVelocityMax;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedLinearVelocityDecay;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedHandTorqueAngularAcc;
    
    UPROPERTY(EditDefaultsOnly)
    float SimulatedHandLinearAcc;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIWeaponHitCapsuleComponent* FistWeaponCapsule;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIWeaponHitCapsuleComponent* OpenHandWeaponCapsule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FistWeaponGripInputThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandActivityLevelActiveSpeedThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandActivityLevelActiveAccelThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandActivityIdleTimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float BodySlotMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float BodySlotOnscreenAngleDegrees;

    UPROPERTY(EditDefaultsOnly)
    FFloatRK4SpringInterpolator CosmeticGripLocationSpring;
    
    UPROPERTY(EditDefaultsOnly)
    FFloatRK4SpringInterpolator CosmeticGripTwistSpring;
    
    UPROPERTY(EditDefaultsOnly)
    FFloatRK4SpringInterpolator CosmeticGripSwing1Spring;
    
    UPROPERTY(EditDefaultsOnly)
    FFloatRK4SpringInterpolator CosmeticGripSwing2Spring;

    UPROPERTY(EditDefaultsOnly)
    FVectorRK4SpringInterpolator UnderWaterLocationSpring;

    UPROPERTY(EditDefaultsOnly)
    float ExitUnderWaterInterpolationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIHandPoseInfo DefaultHighlightHandPoseInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIHandPoseInfo SwimmingHandPoseInfo;
    
    UPROPERTY(EditDefaultsOnly)
    float GripInteractiveSafetyTimeBeforePress;
    
    UPROPERTY(EditDefaultsOnly)
    float GripInteractiveSafetyTimeAfterPress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    USDITriggerResistanceFeedbackEffect_Curve* DefaultTriggerResistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIInteractiveInteractType GripSwapInteractType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FGameplayTagContainer GameplayTagContainer;
    
    UPROPERTY(EditAnywhere)
    FSDIReplicatedStimAndResponseInterfaceDataContainer RepStimulusData;
    
    UPROPERTY(EditAnywhere)
    FSDIStimAndResponseInterfaceDataContainer StimulusData;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIPlayerHandStimulusChangedSignature OnStimulusChangedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIPlayerHandGrabbedActorSignature OnHeldActorGrabbedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIPlayerHandDroppedActorSignature OnHeldActorDroppedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult GripResult;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<FHitResult> InteractResults;
    
    UPROPERTY(Transient)
    bool bGripCapacitiveTouchPressed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGripPressed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bInputModalGripPressed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripInputValue;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripPressedTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGripLocked;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGripDisabled;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bInsideGripRelease;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<bool> bInteractPressed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<float> InteractInputValue;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<float> InteractPressedTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<bool> bInteractLocked;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<bool> bInteractDisabled;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bInsideInteractRelease;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIThrowInputSplineActor* ThrowInputSpline;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> CachedHolderActor;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> CachedInventoryOwner;
    
    UPROPERTY(Transient)
    FSDIPlayerHandLock TwoHandIKLock;
    
    UPROPERTY(Transient)
    FSDIPlayerHandLock GripAttachPhysicsLock;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector SimulatedAngularVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector SimulatedLinearVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHandPhysicsAllowed;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    TWeakObjectPtr<UPrimitiveComponent> GrippingPhysicsComponent;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName GrippingPhysicsComponentBoneName;
    
    UPROPERTY(Transient)
    float GrippingPhysicsComponentArmLengthReleaseTime;
    
    UPROPERTY(Transient)
    float HandActivityLevel;
    
    UPROPERTY(Transient)
    float HandTargetActivityLevel;
    
    UPROPERTY(Transient)
    float HandTargetActivityLevelFadeScale;
    
    UPROPERTY(Transient)
    float HandActivityLevelIdleTime;
    
    UPROPERTY(Transient)
    FTransform HandActivityLevelLastActorRelTransform;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<UActorComponent> CosmeticGripComp;
    
    UPROPERTY(Transient)
    FSDIGripInfo CosmeticGripInfo;
    
    UPROPERTY(Transient)
    FSDIGripInfo AdjustedCosmeticGripInfo;
    
    UPROPERTY(Transient)
    TArray<FSDIPlayerHandInteractComponentEntry> GripInteractiveSafetyEntries;
    
    UPROPERTY(Transient)
    float ExitUnderWaterInterpolationTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    USDITriggerResistanceFeedbackEffect_Curve* CurrentTriggerResistance;
    
    UPROPERTY(Transient)
    int32 TriggerResistanceId;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ThrowingReleaseDelayOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIMeleeWeaponStabInterfaceData StabInterfaceData;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabStartedSignature StabStartedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabCompletedSignature StabCompletedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabEndedSignature StabEndedDelegate;
    
    ASDIPlayerHand(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdatePhysicsHandle();
    
    UFUNCTION(BlueprintCallable)
    bool SwapGripActor(AActor* NewGripActor, UPrimitiveComponent* NewGripComp);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void StimulusTick(const FGameplayTagContainer& Stimuli, float DeltaTime);
    
public:
    UFUNCTION(BlueprintCallable)
    bool SetPreciseThrowControlEngaged(bool bEngaged);
    
    UFUNCTION(BlueprintCallable)
    bool SetInteractLocked(ESDIInteractiveInteractType Type, bool bLocked);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractDisabled(ESDIInteractiveInteractType Type, bool bDisabled, bool bLocked);
    
    UFUNCTION(BlueprintCallable)
    void SetHandPhysicsAllowed(bool bAllowed);
    
    UFUNCTION(BlueprintCallable)
    bool SetGripLocked(bool bLocked);
    
    UFUNCTION(BlueprintCallable)
    void SetGripDisabled(bool bDisabled, bool bLocked);
    
    UFUNCTION(BlueprintCallable)
    void SetAllInteractLocked(bool bLocked);
    
    UFUNCTION(BlueprintCallable)
    void SetAllInteractDisabled(bool bDisabled, bool bLocked);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnWeaponHit(bool bPrimaryHand, USDIWeaponHitCapsuleComponent* WeaponHitComponent, AActor* HitActor, UPrimitiveComponent* HitComp, const FVector& HitVelocity, const FTransform& HitTransform, const UDamageType* DamageTypeObject);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnMeleeWeaponHit(bool bPrimaryHand, USDIMeleeWeaponHitCapsuleComponent* WeaponHitComponent, AActor* HitActor, UPrimitiveComponent* HitComp, const FVector& HitVelocity, const FTransform& HitTransform, const UDamageType* DamageTypeObject);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnHandEndOverlap(USDIPlayerHandInteractComponent* InteractComp, ESDIInteractRangeType RangeType, AActor* Other, UPrimitiveComponent* OtherComp);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnHandBeginOverlap(USDIPlayerHandInteractComponent* InteractComp, ESDIInteractRangeType RangeType, AActor* Other, UPrimitiveComponent* OtherComp);
    
    UFUNCTION(BlueprintCallable)
    bool LockHandToGripComponent(UObject* LockOwner, UActorComponent* GripComp, FSDIGripInfo GripInfo, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand);
    
    UFUNCTION(BlueprintPure)
    FHitResult K2GetInteractResult(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    FHitResult K2GetGripResult() const;
    
    UFUNCTION(BlueprintPure)
    bool IsSwimmingHandPose() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPreciseThrowControlEngaged() const;
    
    UFUNCTION(BlueprintPure)
    bool IsOverlappingInteractionActorWithWidgetComponent(ESDIInteractRangeType RangeType) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInteractPressed(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInteractLocked(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInteractingWithWorld(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInteractingWithPhysics(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInteractingWithInteractive(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInteracting(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInteractDisabled(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandUsingPhysics() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandUnderWater() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGripPressed() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGrippingWorld() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGrippingPhysics() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGrippingModal() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGrippingInteractive() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGrippingAttachPhysics() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGripping() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGripPhysicsConstraintAttachedTo(const UPrimitiveComponent* Other, FName BoneName) const;
    
    UFUNCTION(BlueprintPure)
    bool IsGripLocked() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGripDisabled() const;
    
    UFUNCTION(BlueprintPure)
    bool IsAnyInteractingWithWorld() const;
    
    UFUNCTION(BlueprintPure)
    bool IsAnyInteractingWithPhysics() const;
    
    UFUNCTION(BlueprintPure)
    bool IsAnyInteractingWithInteractive() const;
    
    UFUNCTION(BlueprintPure)
    bool IsAnyInteracting() const;
    
    UFUNCTION(BlueprintPure)
    bool IsAnyInteractDisabled() const;
    
    UFUNCTION(BlueprintCallable)
    void InteractReleaseAll();
    
    UFUNCTION()
    void InteractRelease(ESDIInteractiveInteractType Type);
    
    UFUNCTION()
    void InteractPress(ESDIInteractiveInteractType Type);
    
    UFUNCTION(BlueprintCallable)
    void InputPreciseThrowReleased();
    
    UFUNCTION(BlueprintCallable)
    void InputPreciseThrowPressed();
    
    UFUNCTION(BlueprintCallable)
    void InputPreciseThrowFacingLR(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputPreciseThrowFacingFB(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputPreciseThrowAxis(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputInteractType(ESDIInteractiveInteractType Type, float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputInteractTertiary(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputInteractSecondary(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputInteractPrimary(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputInteract(float Value);
    
    UFUNCTION()
    void InputGripCapacitiveTouch(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputGrip(float Value);
    
    UFUNCTION(BlueprintPure)
    bool HighlightHandPoseAllowsGrip(const FSDIHandPoseInfo& HighlightHandPose) const;
    
    UFUNCTION(BlueprintCallable)
    void GripRelease();
    
    UFUNCTION()
    void GripPress(float MaxInteractiveSafetyAge);
    
    UFUNCTION(BlueprintCallable)
    bool GripPhysicsComponent(UPrimitiveComponent* GripComp, FName BoneName, const FVector& GripPoint, bool bLockRotation);
    
    UFUNCTION(BlueprintCallable)
    void GripDetachPhysics(bool bInterpolate);
    
    UFUNCTION(BlueprintCallable)
    bool GripAttachPhysics(UPrimitiveComponent* PhysicsComp, FName BoneName, UActorComponent* GripComp, FSDIGripInfo GripInfo, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, float ArmLengthReleaseTime, bool bIgnoreCollisionsWithOtherHand);
    
    UFUNCTION(BlueprintPure)
    FTransform GetVisualHeldActorAttachPointTransform() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetTrackedHeldActorAttachPointTransform(bool bUseVisualHandRotation) const;
    
    UFUNCTION(BlueprintPure)
    float GetTargetActivityLevelFadeScale() const;
    
    UFUNCTION(BlueprintPure)
    float GetTargetActivityLevel() const;
    
    UFUNCTION(BlueprintPure)
    FSDIHandPoseInfo GetSwimmingHandPoseInfo() const;
    
    UFUNCTION(BlueprintPure)
    USDIPlayerHandInteractComponent* GetRangedInteractComponent() const;
    
    UFUNCTION(BlueprintPure)
    bool GetPreciseThrowVelocity(FVector& OutVelocity) const;
    
    UFUNCTION(BlueprintPure)
    UPhysicsHandleComponent* GetPhysicsHandle() const;
    
    UFUNCTION(BlueprintPure)
    USDIPlayerHandPhysicalInteractComponent* GetPhysicalInteractComponent() const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetOtherPlayerHand() const;
    
    UFUNCTION(BlueprintPure)
    ASDIInventorySlot* GetInventorySlot(ASDIInventoryActor* Inv, bool bIgnoreInventoryAllowed) const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetInventoryOwner(bool bReset) const;
    
    UFUNCTION(BlueprintPure)
    float GetInteractPressedTime(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    float GetInteractInputValue(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    USDIPlayerHandInteractComponent* GetInteractComponentByType(ESDIInteractRangeType RangeType) const;
    
    UFUNCTION(BlueprintPure)
    USDIPlayerHandInteractComponent* GetInteractComponent() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetInteractActor(ESDIInteractiveInteractType Type) const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetHolderActor(bool bReset) const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetHeldActorAttachPointTransform() const;
    
    UFUNCTION(BlueprintPure)
    USceneComponent* GetHeldActorAttachPoint(FName& SocketName) const;
    
    UFUNCTION(BlueprintPure)
    ESDIHandGripState GetGripState() const;
    
    UFUNCTION(BlueprintPure)
    float GetGripPressedTime() const;
    
    UFUNCTION(BlueprintPure)
    FName GetGrippingPhysicsComponentBoneName() const;
    
    UFUNCTION(BlueprintPure)
    UPrimitiveComponent* GetGrippingPhysicsComponent() const;
    
    UFUNCTION(BlueprintPure)
    UPhysicsConstraintComponent* GetGripPhysicsConstraint() const;
    
    UFUNCTION(BlueprintPure)
    float GetGripInputValue() const;
    
    UFUNCTION(BlueprintPure)
    ESDIPlayerHandGripInputMode GetGripInputMode() const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* GetGripComponent(FSDIGripInfo& OutGripInfo) const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetGripActor() const;
    
    UFUNCTION(BlueprintPure)
    FSDIHandPoseInfo GetDefaultHighlightHandPoseInfo() const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* GetCosmeticGripComp(FSDIGripInfo& OutGripInfo) const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* FindBestGrip(const USceneComponent* ParentComp, FTransform& RelTransform, FSDIHandPoseInfo& HandPose, FSDIGripInfo& OutGripInfo, ESDIGripType GripType, ESDIInteractRangeType RangeType, bool bUseTracked, bool bRecurse, bool bActiveOnly, bool bApplyRotationConstraints, bool bUseDesiredGripInfo, bool bDistanceOnly) const;
    
    UFUNCTION(BlueprintPure)
    bool DoesGripIncludeCapacitiveTouch() const;
    
    UFUNCTION(BlueprintCallable)
    void DestroyThrowInputSpline();
    
    UFUNCTION(BlueprintCallable)
    void CreateThrowInputSpline();
    
    UFUNCTION(BlueprintPure)
    bool CanHandUsePhysics() const;
    
    UFUNCTION(BlueprintCallable)
    bool BreakGripPhysicsConstraintWith(UPrimitiveComponent* Other, FName BoneName);
    
    UFUNCTION(BlueprintPure)
    bool AreGripPhysicsConstraintsAttachedToSameComponent(const ASDIPlayerHand* OtherHand, bool bSameBone) const;
    
    UFUNCTION(BlueprintPure)
    bool AreAllInteractDisabled() const;
    
    UFUNCTION(BlueprintPure)
    void AdjustThrowInfo(UPrimitiveComponent* ThrownComponent, FTransform& InOutTransform, FVector& InOutLinearVelocity, FVector& InOutAngularVelocity) const;
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(GetOwnedGameplayTags,);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveGameplayTag(FGameplayTag Tag, bool bUpdateStimuli) override PURE_VIRTUAL(RemoveGameplayTag, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool ClearGameplayTags(bool bUpdateStimuli) override PURE_VIRTUAL(ClearGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    void AppendGameplayTags(const FGameplayTagContainer& Other, bool bUpdateStimuli) override PURE_VIRTUAL(AppendGameplayTags,);
    
    UFUNCTION(BlueprintCallable)
    bool AddGameplayTag(FGameplayTag Tag, bool bLeaf, bool bUpdateStimuli) override PURE_VIRTUAL(AddGameplayTag, return false;);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopStimulusTick() override PURE_VIRTUAL(StopStimulusTick,);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartStimulusTick() override PURE_VIRTUAL(StartStimulusTick,);
    
private:
    UFUNCTION()
    void SaR_UpdateStimuli() override PURE_VIRTUAL(SaR_UpdateStimuli,);
    
    UFUNCTION()
    void SaR_OnTick() override PURE_VIRTUAL(SaR_OnTick,);
    
    UFUNCTION()
    void SaR_OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) override PURE_VIRTUAL(SaR_OnTakeAnyDamage,);
    
    UFUNCTION()
    void SaR_OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override PURE_VIRTUAL(SaR_OnComponentHit,);
    
    UFUNCTION()
    void SaR_OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override PURE_VIRTUAL(SaR_OnComponentEndOverlap,);
    
    UFUNCTION()
    void SaR_OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override PURE_VIRTUAL(SaR_OnComponentBeginOverlap,);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterMultipleComponentCallbacks(TArray<UPrimitiveComponent*> Comps, bool bOverlap, bool bHit) override PURE_VIRTUAL(RegisterMultipleComponentCallbacks,);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterComponentCallbacks(UPrimitiveComponent* Comp, bool bOverlap, bool bHit) override PURE_VIRTUAL(RegisterComponentCallbacks,);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterAllComponentCallbacks(bool bOverlap, bool bHit) override PURE_VIRTUAL(RegisterAllComponentCallbacks,);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterAllCallbacks(bool bDamage, bool bOverlap, bool bHit) override PURE_VIRTUAL(RegisterAllCallbacks,);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterActorCallbacks(bool bDamage) override PURE_VIRTUAL(RegisterActorCallbacks,);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void K2UpdateStimuli(const FGameplayTagContainer& IncomingStimuli, bool bNonLatent) override PURE_VIRTUAL(K2UpdateStimuli,);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool IsComponentOverlapRegistered(UPrimitiveComponent* Comp) const override PURE_VIRTUAL(IsComponentOverlapRegistered, return false;);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    int32 GetNumOverlappingStimuli(const FGameplayTagQuery& Query) const override PURE_VIRTUAL(GetNumOverlappingStimuli, return 0;);
    
};

