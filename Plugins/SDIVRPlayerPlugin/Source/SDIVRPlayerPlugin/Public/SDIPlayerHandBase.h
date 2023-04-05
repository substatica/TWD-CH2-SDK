#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerHandLock.h"
#include "UObject/NoExportTypes.h"
#include "SDIHandPoseInfo.h"
#include "PhysicsEngine/PhysicalAnimationComponent.h"
#include "InputCoreTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerHandShake.h"
#include "ESDIHandPose.h"
#include "SDIPlayerHandMove.h"
#include "SDIGripInfo.h"
#include "SDIPlayerHandBase.generated.h"

class USDILatePhysicalAnimationComponent;
class APlayerController;
class USDIMotionControllerComponent;
class USkeletalMeshComponent;
class USDICollisionChannelIgnoranceComponent;
class UActorComponent;
class UMaterialInstanceDynamic;
class USceneComponent;
class UObject;
class UHapticFeedbackEffect_Base;
class UAnimSequenceBase;
class APawn;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIPlayerHandBase : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIMotionControllerComponent* MotionController;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USkeletalMeshComponent* HandMesh;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USkeletalMeshComponent* TrackedHandMesh;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USkeletalMeshComponent* CosmeticHandMesh;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USDILatePhysicalAnimationComponent* CosmeticHandMeshPhysicalAnimation;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDICollisionChannelIgnoranceComponent* HandMeshCollisionIgnoranceComp;
    
    UPROPERTY(EditDefaultsOnly)
    float VelocitySmoothingFactor;
    
    UPROPERTY(EditDefaultsOnly)
    FVector ShoulderOffset;
    
    UPROPERTY(EditDefaultsOnly)
    float ShoulderHeadRotationDeltaPercent;
    
    UPROPERTY(EditDefaultsOnly)
    float ShoulderHeadRotationPitchThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    FVector ArmDebugOffset;
    
    UPROPERTY(EditDefaultsOnly)
    FVector EditorCameraOffset;
    
    UPROPERTY(EditDefaultsOnly)
    float TrackedHandMeshFadeInStart;
    
    UPROPERTY(EditDefaultsOnly)
    float TrackedHandMeshFadeInDistance;
    
    UPROPERTY(EditDefaultsOnly)
    float TrackedHandMeshFadeInExp;
    
    UPROPERTY(EditDefaultsOnly)
    float TrackedHandMeshFadeInAlpha;
    
    UPROPERTY(Transient)
    float DebugTrackedHandMeshFadeStartDistanceScale;
    
    UPROPERTY(Transient)
    float DebugTrackedHandMeshFadeInDistanceScale;
    
    UPROPERTY(EditDefaultsOnly)
    bool bEnableHandCollisionIgnoranceRestorationPullback;
    
    UPROPERTY(EditDefaultsOnly)
    float HandCollisionIgnoranceRestorationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowTeleport;
    
    UPROPERTY(EditDefaultsOnly)
    float TeleportDistance;
    
    UPROPERTY(EditDefaultsOnly)
    float TeleportMinArmLengthMultiplier;
    
    UPROPERTY(EditDefaultsOnly)
    float MaxSimulatingPhysicsMassToPushAround;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FName WristBone;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FName ElbowBone;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FName ShoulderBone;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float ArmMeshLengthMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FRuntimeFloatCurve ArmMeshWidthMultiplierCurve;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIPlayerHandLock HandLock;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIPlayerHandLock ShoulderLock;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<FString, FRotator> RelativeRotationPerControllerName;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<FString, FVector> RelativeLocationPerControllerName;
    
    UPROPERTY(EditDefaultsOnly)
    float CosmeticHandMeshReturnSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    bool bCosmeticPhysicsFingers;
    
    UPROPERTY(EditDefaultsOnly)
    float CosmeticPhysicsFingersBlendInTime;
    
    UPROPERTY(EditDefaultsOnly)
    float CosmeticPhysicsFingersBlendOutTime;
    
    UPROPERTY(EditDefaultsOnly)
    FName CosmeticPhysicsFingersRootBodyName;
    
    UPROPERTY(EditDefaultsOnly)
    FName CosmeticPhysicsFingersProfile;
    
    UPROPERTY(EditDefaultsOnly)
    FPhysicalAnimationData CosmeticPhysicsFingersSettings;
    
    UPROPERTY(EditDefaultsOnly)
    bool bShouldCorrectPhysicsForCharacterMovement;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    EControllerHand ControllerHand;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    TArray<UMaterialInstanceDynamic*> TrackedHandMaterialInstances;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> HandMeshTarget;
    
    UPROPERTY(Transient)
    FVector HandOffsetDelta;
    
    UPROPERTY(Transient)
    FTransform PreLockHandModifier;
    
    UPROPERTY(Transient)
    FTransform HandModifier;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bHandMeshHidden;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bTrackedHandMeshHidden;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bWristBoneValid;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bElbowBoneValid;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bShoulderBoneValid;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float BaseForeArmLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float BaseUpperArmLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ForeArmLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float UpperArmLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float LastHandTeleportTimestamp;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<UObject> ShoulderLockOwner;
    
    UPROPERTY(Transient)
    float ShoulderLockLimitedTime;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<USDICollisionChannelIgnoranceComponent>> CollisionIgnoranceRestorationPullbackComps;
    
    UPROPERTY(Transient)
    bool bHandCollisionIgnoranceRestorationTargetCamera;
    
    UPROPERTY(Transient)
    float CosmeticHandMeshReturnLerp;
    
    UPROPERTY(Transient)
    FTransform CosmeticHandMeshReturnTransform;
    
    UPROPERTY(Transient)
    FTransform RelativeControllerTransform;
    
    UPROPERTY(Transient)
    FSDIHandPoseInfo CurrentHandPose;
    
    UPROPERTY(Transient)
    bool bCurrentHandPoseForHighlight;
    
    UPROPERTY(Transient)
    float CosmeticPhysicsFingersAlpha;
    
    UPROPERTY(Transient)
    FTransform CosmeticPhysicsFingersTransformToRoot;
    
    UPROPERTY(Transient)
    FTransform CosmeticHandMeshRelTransform;
    
    UPROPERTY(Transient)
    TArray<FSDIPlayerHandShake> HandShakes;
    
public:
    ASDIPlayerHandBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintNativeEvent)
    void UpdateHandHidden(bool bHandHidden);
    
    UFUNCTION(BlueprintCallable)
    bool UnlockShoulder(UObject* LockOwner);
    
    UFUNCTION(BlueprintCallable)
    bool UnlockHandRotation(UObject* LockOwner, bool bInterpolate);
    
    UFUNCTION(BlueprintCallable)
    bool UnlockHandLocation(UObject* LockOwner, bool bInterpolate);
    
    UFUNCTION(BlueprintCallable)
    void UnlockHandClench();
    
    UFUNCTION(BlueprintCallable)
    bool UnlockHand(UObject* LockOwner, bool bInterpolate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool StopHapticsByValue(UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool StopHapticEffectId(int32 ID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool StopHapticEffect(UHapticFeedbackEffect_Base* HapticEffect, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintCallable)
    void StopHandShake(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    void StopHandAnimation(float BlendOutTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool StopAllHapticEffects(UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintCallable)
    void SetTrackedHandMeshHidden(bool bNewHidden);
    
    UFUNCTION(BlueprintCallable)
    bool SetLockedHandPoseInfo(UObject* LockOwner, const FSDIHandPoseInfo& NewPoseInfo, float BlendSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool SetHapticsByValue(const float Frequency, const float Amplitude, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintCallable)
    void SetHandPoseInfo(FSDIHandPoseInfo NewPoseInfo, float BlendSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetHandPose(ESDIHandPose NewPose, float BlendSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetHandMeshHidden(bool bNewHidden);
    
    UFUNCTION(BlueprintCallable)
    void SetHandClench(float NewClench);
    
    UFUNCTION(BlueprintCallable)
    void SetDebugTrackedHandMeshFadeStartDistanceScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    void SetDebugTrackedHandMeshFadeInDistanceScale(float Scale);
    
protected:
    UFUNCTION()
    void RecreatePhysicsConstraints();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    int32 PlayHapticEffect(UHapticFeedbackEffect_Base* HapticEffect, float Scale, bool bLoop, int32 Priority, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintCallable)
    int32 PlayHandShake(const FSDIPlayerHandShake& Shake, float Scale);
    
    UFUNCTION(BlueprintCallable)
    bool PlayHandAnimation(UAnimSequenceBase* Anim, FName SlotName, float BlendInTime, float BlendOutTime, float PlayRate);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnPawnChanged(APawn* OldPawn, APawn* NewPawn);
    
    UFUNCTION(BlueprintCallable)
    bool LockShoulder(UObject* LockOwner, float ArmLengthMultiplier, float AdditionalArmLength);
    
    UFUNCTION(BlueprintCallable)
    bool LockHandToComponent(UObject* LockOwner, USceneComponent* Comp, FName SocketName, FRotator Extent, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand);
    
    UFUNCTION(BlueprintCallable)
    bool LockHandRotationToComponent(UObject* LockOwner, USceneComponent* Comp, FName SocketName, FRotator Extent, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation);
    
    UFUNCTION(BlueprintCallable)
    bool LockHandRotation(UObject* LockOwner, FRotator Rotation, FRotator Extent, USceneComponent* Parent, FName ParentSocketName, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation);
    
    UFUNCTION(BlueprintCallable)
    bool LockHandLocationToComponent(UObject* LockOwner, USceneComponent* Comp, FName SocketName, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand);
    
    UFUNCTION(BlueprintCallable)
    void LockHandClench(float NewClench);
    
    UFUNCTION(BlueprintCallable)
    bool K2LockHandLocation(UObject* LockOwner, FVector Extents, FTransform Transform, USceneComponent* Parent, FName ParentSocketName, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand);
    
    UFUNCTION(BlueprintCallable)
    bool K2LockHand(UObject* LockOwner, FVector Extents, FTransform Transform, FRotator Extent, USceneComponent* Parent, FName ParentSocketName, float SpringStiffness, float SpringDamp, USceneComponent* Ref, FName RefSocketName, bool bInterpolate, bool bResetInterpolation, float ArmLengthReleaseFactor, bool bIgnoreCollisionsWithOtherHand);
    
    UFUNCTION(BlueprintPure)
    bool K2IsHandPoseLocked(FSDIHandPoseInfo& OutPose) const;
    
    UFUNCTION(BlueprintPure)
    bool K2IsHandClenchLocked(float& OutLockedClench) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float K2ComputeHandMove(const FSDIPlayerHandMove& Move, FVector DesiredDirection, FVector& OutVector) const;
    
    UFUNCTION(BlueprintPure)
    bool IsTrackedHandMeshHidden() const;
    
    UFUNCTION(BlueprintPure)
    bool IsShoulderLockedBy(const UObject* Obj) const;
    
    UFUNCTION(BlueprintPure)
    bool IsShoulderLocked() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHapticsByValue(UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHapticEffectId(int32 ID) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHapticEffect(UHapticFeedbackEffect_Base* HapticEffect, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHandShake(int32 ID) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHandAnimation() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandMeshHidden() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandLockInterpolating() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandLockExceedingArmLengthReleaseFactor(float& OutTime) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandLockedBy(const UObject* Obj) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandLocked() const;
    
protected:
    UFUNCTION()
    void InitializeHand();
    
public:
    UFUNCTION(BlueprintPure)
    bool HasCosmeticHandMesh() const;
    
    UFUNCTION(BlueprintNativeEvent)
    void HandWasTeleported(const FTransform& OldTransform, const FTransform& NewTransform);
    
    UFUNCTION(BlueprintPure)
    FTransform GetVisualHandMeshTransform() const;
    
    UFUNCTION(BlueprintPure)
    USkeletalMeshComponent* GetVisualHandMesh() const;
    
    UFUNCTION(BlueprintPure)
    float GetUpperArmLength() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetTrackedHandMeshTransform() const;
    
    UFUNCTION(BlueprintPure)
    USkeletalMeshComponent* GetTrackedHandMesh() const;
    
    UFUNCTION(BlueprintPure)
    float GetTimeSinceLastHandTeleport() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetShoulderTransform() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetShoulderOffset() const;
    
    UFUNCTION(BlueprintPure)
    float GetShoulderLockLimitedTime() const;
    
    UFUNCTION(BlueprintPure)
    APlayerController* GetPlayerController() const;
    
    UFUNCTION(BlueprintPure)
    USkeletalMeshComponent* GetPhysicalHandMesh() const;
    
    UFUNCTION(BlueprintPure)
    APawn* GetPawn() const;
    
    UFUNCTION(BlueprintPure)
    USDIMotionControllerComponent* GetMotionController() const;
    
    UFUNCTION(BlueprintPure)
    bool GetIsIndicatingDirection() const;
    
    UFUNCTION(BlueprintPure)
    UHapticFeedbackEffect_Base* GetHapticFeedbackEffect(int32 ID) const;
    
    UFUNCTION(BlueprintPure)
    FSDIHandPoseInfo GetHandPoseInfo(bool& bOutForHighlight) const;
    
    UFUNCTION(BlueprintPure)
    ESDIHandPose GetHandPose() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetHandOffsetDelta() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetHandMeshWristTransform() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetHandMeshTransform() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetHandMeshShoulderTransform() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetHandMeshElbowTransform() const;
    
    UFUNCTION(BlueprintPure)
    UActorComponent* GetHandLockGripComponent(FSDIGripInfo& OutGripInfo) const;
    
    UFUNCTION(BlueprintPure)
    float GetForeArmLength() const;
    
    UFUNCTION(BlueprintCallable)
    FTransform GetDesiredHandMeshTransform(float DeltaSeconds);
    
    UFUNCTION(BlueprintPure)
    EControllerHand GetControllerHand() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetCameraTransform() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetCameraRight2D() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetCameraForward2D() const;
    
    UFUNCTION(BlueprintPure)
    FRuntimeFloatCurve GetArmMeshWidthMultiplierCurve() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetArmMeshScale() const;
    
    UFUNCTION(BlueprintPure)
    float GetArmMeshLengthMultiplier() const;
    
    UFUNCTION(BlueprintPure)
    float GetArmLength() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetArmDebugOffset() const;
    
    UFUNCTION(BlueprintPure)
    FVector ComputeTheoreticalElbowLocation(const FVector& DesiredWristLocation) const;
    
    UFUNCTION(BlueprintCallable)
    bool ClearLockedHandPoseInfo(UObject* LockOwner, float BlendSpeed);
    
    UFUNCTION(BlueprintCallable)
    void ClearHandPoseInfo(float BlendSpeed);
    
    UFUNCTION(BlueprintPure)
    bool AreCosmeticPhysicsFingersActive(float& OutAlpha) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool AdjustHapticEffectScaleId(int32 ID, float Scale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool AdjustHapticEffectScale(UHapticFeedbackEffect_Base* HapticEffect, float Scale, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintCallable)
    void AdjustHandShakeScale(int32 ID, float Scale);
    
};

