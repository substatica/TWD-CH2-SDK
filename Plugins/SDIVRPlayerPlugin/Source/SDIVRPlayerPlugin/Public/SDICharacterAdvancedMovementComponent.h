#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDICoreCharacterMovementComponent.h"
#include "SDIAuxTickFunction.h"
#include "SavedMove_SDICharacterAdvanced_MoveData.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "QFloatExp.h"
#include "RFloat.h"
#include "SDICharacterAdvancedMovementMantleUpSettings.h"
#include "SDICharacterAdvancedMovementMantleOverSettings.h"
#include "SDIPlayerHandMove.h"
#include "RFloatExp.h"
#include "SDIBlendOption.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "ESDIMovementHandGripState.h"
#include "NetworkPredictionData_Server_SDICharacterAdvanced_Adjustment.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/RootMotionSource.h"
#include "SDICharacterAdvancedMovementComponent.generated.h"

class UCurveFloat;
class UPrimitiveComponent;
class UAkAudioEvent;
class UHapticFeedbackEffect_Base;
class UObject;
class ASDIInteractiveMovableActor;

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDICharacterAdvancedMovementComponent : public USDICoreCharacterMovementComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Replicated, Transient)
    FSavedMove_SDICharacterAdvanced_MoveData MoveData;
    
    UPROPERTY(Transient)
    bool bLastClimbingFacingValid;
    
    UPROPERTY(Transient)
    bool bLastClimbingFacingWasHint;
    
    UPROPERTY(Transient)
    FVector LastClimbingFacing;
    
    UPROPERTY(Transient)
    FVector LastBaseClimbingFacing;
    
    UPROPERTY(Transient)
    FVector LastClimbingFacingRightHand;
    
    UPROPERTY(Transient)
    FVector LastRelativeClimbingFacingRightHand;
    
    UPROPERTY(Transient)
    float ClimbingRightHandInterpolation;
    
    UPROPERTY(Transient)
    FVector LastClimbingFacingLeftHand;
    
    UPROPERTY(Transient)
    FVector LastRelativeClimbingFacingLeftHand;
    
    UPROPERTY(Transient)
    float ClimbingLeftHandInterpolation;
    
    UPROPERTY(Transient)
    FVectorRK4SpringInterpolator MovementSpring;
    
    UPROPERTY(Transient)
    FFloatRK4SpringInterpolator YawSpring;
    
    UPROPERTY(Transient)
    bool bWantsToCrawl;
    
    UPROPERTY(Transient)
    bool bForceCrawl;
    
    UPROPERTY(Transient)
    bool bCrawlMaintainsBaseLocation;
    
    UPROPERTY(Transient)
    FHitResult TeleportHitResult;
    
    UPROPERTY(Transient)
    bool bDesiredTeleportTransformValid;
    
    UPROPERTY(Transient)
    bool bTeleportCrouching;
    
    UPROPERTY(Transient)
    FTransform DesiredTeleportTransform;
    
    UPROPERTY(Transient)
    FTransform DesiredRelativeTeleportTransform;
    
    UPROPERTY(Transient)
    bool bTeleporting;
    
    UPROPERTY(Transient)
    bool bTeleportingCancelled;
    
    UPROPERTY(Transient)
    bool bRopeMovementLimitingDisabled;
    
    UPROPERTY(Transient)
    bool bUpdatingBaseMovement;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<UPrimitiveComponent> MantleIgnoredCollisionComponent;
    
    UPROPERTY(Transient)
    FVector SwimmingCameraRelativeLocation;
    
    UPROPERTY(Transient)
    FVector SwimMovementHandVelocity;
    
    UPROPERTY(Transient)
    bool bSwimMovementLimitedToSurface;
    
    UPROPERTY(Transient)
    bool bSwimMovementTouchingGround;
    
    UPROPERTY(Transient)
    bool bSwimMovementTouchingCeiling;
    
    UPROPERTY(Transient)
    int32 SwimMovementCameraTransition;
    
    UPROPERTY(Transient)
    TMap<EControllerHand, bool> SwimHandMovementAKPlayed;
    
    UPROPERTY(Transient)
    float SwimStickMovementAKTimestamp;
    
    UPROPERTY(Transient)
    bool bCameraWasUnderWater;
    
    UPROPERTY(Transient)
    FVector LastBasedMovementDelta;
    
    UPROPERTY()
    FSDIAuxTickFunction PostPhysicsTick;
    
    UPROPERTY(Transient)
    bool bModifiedCapsuleHeight;
    
    UPROPERTY(Transient)
    int32 FallingHMDHapticFeedbackLoopId;
    
    UPROPERTY(Transient)
    FHitResult LastMantleTargetInfo;
    
    UPROPERTY(Transient)
    bool bStartMovingOnGround;
    
    UPROPERTY(Transient)
    TArray<FVector> RopeLimitedDirs;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxWalkSpeedCrawl;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float CrawlHalfHeight;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanWalkOffLedgesWhenCrawling;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanCrawl;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanClimb;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanGrabAndPull;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanUseRope;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float RopeMovementSpringStiffness;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float RopeMovementSpringDamp;
    
    UPROPERTY(EditDefaultsOnly)
    float SurfaceGripMaxPhysicsLinearVel;
    
    UPROPERTY(EditDefaultsOnly)
    float SurfaceGripMaxPhysicsAngularVelDeg;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float HandAverageVelocityTime;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabAndPullSpringStiffness;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabAndPullSpringDamp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRFloat GrabAndPullEyeHeightOffsetRange;
    
    UPROPERTY(EditDefaultsOnly)
    float ClimbingHalfHeight;
    
    UPROPERTY(EditDefaultsOnly)
    float ClimbingSpringStiffness;
    
    UPROPERTY(EditDefaultsOnly)
    float ClimbingSpringDamp;
    
    UPROPERTY(EditDefaultsOnly)
    float ClimbingYawSpringStiffness;
    
    UPROPERTY(EditDefaultsOnly)
    float ClimbingYawSpringDamp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bClimbingUseFixedFacing;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bClimbingFaceGripWithoutHint;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingScanDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingGripInterpolationTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanMantleOver;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanMantleUp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleOverSettings ClimbingMantleOver;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleUpSettings ClimbingMantleUp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleOverSettings WalkingMantleOver;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleUpSettings WalkingMantleUp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleOverSettings NonVRMantleOver;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleUpSettings NonVRMantleUp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bMantleVerticalTestAllowHMD;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingMantleMaxDistanceToFloor;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingMantleCheckStep;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingAutoMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingMantleCheckSideStep;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ClimbingMantleCheckSideStepCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float WalkingMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float WalkingMantleMaxDistanceToFloor;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float WalkingMantleCheckStep;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float WalkingAutoMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float WalkingMantleCheckSideStep;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float WalkingMantleCheckSideStepCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRMantleMaxDistanceToFloor;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRMantleCheckStep;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRMantleCheckSideStep;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRMantleCheckSideStepCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRMantleMinAnalogInput;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRMantleInputAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIPlayerHandMove MantleHandMove;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float RopeClimbingHalfHeight;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRFloatExp TautRopeVelocitySoftenTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* SinglePivotRopeDampingCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float SinglePivotRopeDamping;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DualPivotRopeDamping;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float RopeDampingApproachingPivotFactor;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float RopeDampingLeavingPivotFactor;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonMovementRopeArmLengthScale;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNonMovementRopeAvoidShoulderDislocation;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonMovementRopeMaxShoulderDislocationDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonMovementRopeShoulderDislocationCorrectionSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MinZDeltaForRopeClimbing;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingHalfHeight;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float BrakingDecelerationSwimmingImmersedZ;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UCurveFloat* SwimmingHMDPitchRemapCurve;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingHandGrippedMotionVelocityMul;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingHandOpenMotionVelocityMul;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIBlendOption SwimmingHandMotionVelocityPalmBlend;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIBlendOption SwimmingHandMotionVelocityVerticalBlend;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FVectorRK4SpringInterpolator SwimmingHandMotionVelocityAccelSpring;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FVectorRK4SpringInterpolator SwimmingHandMotionVelocityDecelSpring;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingSingleHandMotionVelocityBoost;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingHandMotionMinVelocity;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float MaxSprintSwimSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float MaxHandMotionSwimSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingDesiredHeightAboveSurface;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingDesiredHeightBelowSurface;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FFloatRK4SpringInterpolator SwimmingDesiredHeightSpring;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingCameraWaterPlaneRadius;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingCameraAboveSurfaceMovementAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimmingCameraBelowSurfaceMovementAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* SwimStartAKEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FString SwimStartZVelocityRTPC;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* SwimEndAKEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* SwimSufraceAKEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* SwimSubmergeAKEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* SwimHandMovementAKEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FRFloat SwimHandMovementAKVelocity;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAkAudioEvent* SwimStickMovementAKEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SwimStickMovementAKMinAnalogInput;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FQFloatExp SwimStickMovementAKInterval;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* FallingHMDHapticFeedbackLoop;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* FallingHMDHapticFeedbackVelocityScaleCurve;
    
public:
    USDICharacterAdvancedMovementComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION()
    void UpdateMovementHandCorrectionValues(float DeltaTime);
    
protected:
    UFUNCTION()
    void TickPostPhysics(UObject* TickOwner, float DeltaTime);
    
public:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMoveSDI(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, const FSavedMove_SDICharacterAdvanced_MoveData& ServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMoveOldSDI(float OldTimeStamp, FVector_NetQuantize10 OldAccel, uint8 OldMoveFlags, const FSavedMove_SDICharacterAdvanced_MoveData& OldServerMoveData);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMoveDualSDI(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, const FSavedMove_SDICharacterAdvanced_MoveData& PendingServerMoveData, uint32 View0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 NewFlags, const FSavedMove_SDICharacterAdvanced_MoveData& NewServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMoveDualHybridRootMotionSDI(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, const FSavedMove_SDICharacterAdvanced_MoveData& PendingServerMoveData, uint32 View0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 NewFlags, const FSavedMove_SDICharacterAdvanced_MoveData& NewServerMoveData, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode);
    
    UFUNCTION(BlueprintPure)
    bool IsTeleporting() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRopeWalking() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRopeMovement() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRopeClimbing() const;
    
    UFUNCTION(BlueprintPure)
    bool IsMovingActor(ASDIInteractiveMovableActor*& OutActor) const;
    
    UFUNCTION(BlueprintPure)
    bool IsMantlingUp() const;
    
    UFUNCTION(BlueprintPure)
    bool IsMantlingOver() const;
    
    UFUNCTION(BlueprintPure)
    bool IsMantling() const;
    
    UFUNCTION(BlueprintPure)
    bool IsGrabbingAndPulling() const;
    
    UFUNCTION(BlueprintPure)
    bool IsCrawling() const;
    
    UFUNCTION(BlueprintPure)
    bool IsClimbing() const;
    
    UFUNCTION(BlueprintPure)
    void GetMovementGripState(ESDIMovementHandGripState& OutLeftHand, ESDIMovementHandGripState& OutRightHand) const;
    
    UFUNCTION(Client, Unreliable)
    void ClientVeryShortAdjustPositionSDI(float Timestamp, FVector NewLoc, UPrimitiveComponent* NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI);
    
    UFUNCTION(Client, Unreliable)
    void ClientAdjustRootMotionSourcePositionSDI(float Timestamp, FRootMotionSourceGroup ServerRootMotion, bool bHasAnimRootMotion, float ServerMontageTrackPosition, FVector ServerLoc, FVector_NetQuantizeNormal ServerRotation, float ServerVelZ, UPrimitiveComponent* ServerBase, FName ServerBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI);
    
    UFUNCTION(Client, Unreliable)
    void ClientAdjustRootMotionPositionSDI(float Timestamp, float ServerMontageTrackPosition, FVector ServerLoc, FVector_NetQuantizeNormal ServerRotation, float ServerVelZ, UPrimitiveComponent* ServerBase, FName ServerBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI);
    
    UFUNCTION(Client, Unreliable)
    void ClientAdjustPositionSDI(float Timestamp, FVector NewLoc, FVector NewVel, UPrimitiveComponent* NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FNetworkPredictionData_Server_SDICharacterAdvanced_Adjustment PendingAdjustmentSDI);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool CheckForMantle(float VerticalTestDistance, FHitResult& OutMantleTargetInfo, bool& bMantleOver, bool& bMantleRequireCrouch, bool bCheckMantleUp, bool bCheckMantleOver, FVector MotionDirection) const;
    
    UFUNCTION(BlueprintCallable)
    void CancelTeleport();
    
    UFUNCTION(BlueprintCallable)
    bool CancelClimbNonVR();
    
    UFUNCTION(BlueprintCallable)
    bool AttemptTeleport(const FTransform& DesiredTransform, const FHitResult& HitResult);
    
};

