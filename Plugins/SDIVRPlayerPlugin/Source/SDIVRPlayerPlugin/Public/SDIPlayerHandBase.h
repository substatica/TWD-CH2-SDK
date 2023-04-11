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
class UObject;
class UAnimSequenceBase;
class APawn;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIPlayerHandBase : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIMotionControllerComponent* MotionController;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* HandMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* TrackedHandMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* CosmeticHandMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDILatePhysicalAnimationComponent* CosmeticHandMeshPhysicalAnimation;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDICollisionChannelIgnoranceComponent* HandMeshCollisionIgnoranceComp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float VelocitySmoothingFactor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector ShoulderOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShoulderHeadRotationDeltaPercent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShoulderHeadRotationPitchThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector ArmDebugOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector EditorCameraOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TrackedHandMeshFadeInStart;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TrackedHandMeshFadeInDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TrackedHandMeshFadeInExp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TrackedHandMeshFadeInAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DebugTrackedHandMeshFadeStartDistanceScale;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DebugTrackedHandMeshFadeInDistanceScale;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bEnableHandCollisionIgnoranceRestorationPullback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandCollisionIgnoranceRestorationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowTeleport;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TeleportDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TeleportMinArmLengthMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxSimulatingPhysicsMassToPushAround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName WristBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName ElbowBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName ShoulderBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ArmMeshLengthMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRuntimeFloatCurve ArmMeshWidthMultiplierCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandLock HandLock;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandLock ShoulderLock;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FString, FRotator> RelativeRotationPerControllerName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FString, FVector> RelativeLocationPerControllerName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float CosmeticHandMeshReturnSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCosmeticPhysicsFingers;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float CosmeticPhysicsFingersBlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float CosmeticPhysicsFingersBlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName CosmeticPhysicsFingersRootBodyName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName CosmeticPhysicsFingersProfile;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FPhysicalAnimationData CosmeticPhysicsFingersSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bShouldCorrectPhysicsForCharacterMovement;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand ControllerHand;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<UMaterialInstanceDynamic*> TrackedHandMaterialInstances;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> HandMeshTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector HandOffsetDelta;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform PreLockHandModifier;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform HandModifier;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHandMeshHidden;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bTrackedHandMeshHidden;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWristBoneValid;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bElbowBoneValid;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bShoulderBoneValid;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float BaseForeArmLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float BaseUpperArmLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ForeArmLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float UpperArmLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LastHandTeleportTimestamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<UObject> ShoulderLockOwner;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ShoulderLockLimitedTime;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<USDICollisionChannelIgnoranceComponent>> CollisionIgnoranceRestorationPullbackComps;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHandCollisionIgnoranceRestorationTargetCamera;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CosmeticHandMeshReturnLerp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform CosmeticHandMeshReturnTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform RelativeControllerTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIHandPoseInfo CurrentHandPose;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bCurrentHandPoseForHighlight;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CosmeticPhysicsFingersAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform CosmeticPhysicsFingersTransformToRoot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform CosmeticHandMeshRelTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
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
    bool StopHapticEffect(UObject* HapticEffect, UObject* EffectOwner) const;
    
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
    int32 PlayHapticEffect(UObject* HapticEffect, float Scale, bool bLoop, int32 Priority, UObject* EffectOwner) const;
    
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
    bool IsPlayingHapticEffect(UObject* HapticEffect, UObject* EffectOwner) const;
    
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
    UObject* GetHapticFeedbackEffect(int32 ID) const;
    
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
    bool AdjustHapticEffectScale(UObject* HapticEffect, float Scale, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintCallable)
    void AdjustHandShakeScale(int32 ID, float Scale);
    
};

