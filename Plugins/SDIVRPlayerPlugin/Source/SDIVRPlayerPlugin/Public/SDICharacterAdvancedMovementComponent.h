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
#include "Engine/SpringInterpolator.h"
#include "GameFramework/RootMotionSource.h"
#include "SDICharacterAdvancedMovementComponent.generated.h"

class UCurveFloat;
class UPrimitiveComponent;
class UAkAudioEvent;
class UObject;
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
    
    UPROPERTY(EditAnywhere, Transient)
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
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxWalkSpeedCrawl;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float CrawlHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanWalkOffLedgesWhenCrawling;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanCrawl;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanClimb;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanGrabAndPull;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanUseRope;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float RopeMovementSpringStiffness;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float RopeMovementSpringDamp;
    
    UPROPERTY(EditDefaultsOnly)
    float SurfaceGripMaxPhysicsLinearVel;
    
    UPROPERTY(EditDefaultsOnly)
    float SurfaceGripMaxPhysicsAngularVelDeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HandAverageVelocityTime;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabAndPullSpringStiffness;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabAndPullSpringDamp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
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
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bClimbingUseFixedFacing;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bClimbingFaceGripWithoutHint;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingScanDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingGripInterpolationTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanMantleOver;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanMantleUp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleOverSettings ClimbingMantleOver;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleUpSettings ClimbingMantleUp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleOverSettings WalkingMantleOver;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleUpSettings WalkingMantleUp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleOverSettings NonVRMantleOver;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICharacterAdvancedMovementMantleUpSettings NonVRMantleUp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bMantleVerticalTestAllowHMD;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingMantleMaxDistanceToFloor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingMantleCheckStep;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingAutoMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingMantleCheckSideStep;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ClimbingMantleCheckSideStepCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float WalkingMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float WalkingMantleMaxDistanceToFloor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float WalkingMantleCheckStep;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float WalkingAutoMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float WalkingMantleCheckSideStep;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float WalkingMantleCheckSideStepCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRMantleVerticalTestDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRMantleMaxDistanceToFloor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRMantleCheckStep;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRMantleCheckSideStep;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRMantleCheckSideStepCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRMantleMinAnalogInput;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRMantleInputAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandMove MantleHandMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RopeClimbingHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp TautRopeVelocitySoftenTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* SinglePivotRopeDampingCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float SinglePivotRopeDamping;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DualPivotRopeDamping;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float RopeDampingApproachingPivotFactor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float RopeDampingLeavingPivotFactor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonMovementRopeArmLengthScale;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNonMovementRopeAvoidShoulderDislocation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonMovementRopeMaxShoulderDislocationDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonMovementRopeShoulderDislocationCorrectionSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MinZDeltaForRopeClimbing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float BrakingDecelerationSwimmingImmersedZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UCurveFloat* SwimmingHMDPitchRemapCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingHandGrippedMotionVelocityMul;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingHandOpenMotionVelocityMul;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption SwimmingHandMotionVelocityPalmBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption SwimmingHandMotionVelocityVerticalBlend;
/*
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVectorRK4SpringInterpolator SwimmingHandMotionVelocityAccelSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVectorRK4SpringInterpolator SwimmingHandMotionVelocityDecelSpring;
*/    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingSingleHandMotionVelocityBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingHandMotionMinVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxSprintSwimSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxHandMotionSwimSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingDesiredHeightAboveSurface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingDesiredHeightBelowSurface;
/*
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRK4SpringInterpolator SwimmingDesiredHeightSpring;
*/      
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingCameraWaterPlaneRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingCameraAboveSurfaceMovementAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimmingCameraBelowSurfaceMovementAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* SwimStartAKEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString SwimStartZVelocityRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* SwimEndAKEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* SwimSufraceAKEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* SwimSubmergeAKEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* SwimHandMovementAKEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat SwimHandMovementAKVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* SwimStickMovementAKEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SwimStickMovementAKMinAnalogInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FQFloatExp SwimStickMovementAKInterval;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* FallingHMDHapticFeedbackLoop;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
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

