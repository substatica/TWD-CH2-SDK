#pragma once
#include "CoreMinimal.h"
#include "RFloatExp.h"
#include "SDICharacterAdvancedMovementComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerHandMove.h"
#include "Engine/SpringInterpolator.h"
#include "UObject/NoExportTypes.h"
#include "TWDCharacterMovementComponent.generated.h"

class UCurveBase;
class AActor;
class UObject;
class UCurveFloat;
class UPhysicalMaterial;

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDCharacterMovementComponent : public USDICharacterAdvancedMovementComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    float NoiseVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float NoiseDistance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float NoiseTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float MaxNoiseLevel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ClimbingGruntTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector AttackMoveTargetLoc;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector AttackMoveTargetRelLoc;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName AttackMoveTargetSocket;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<AActor> AttackMoveTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float AttackMoveTargetOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float AttackMoveTargetMaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float AttackMoveTargetDuration;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAttackMoveTargetFaceTargetYaw;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAttackMoveTargetFaceTargetPitch;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator AttackMoveTargetFaceTargetMaxRotVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float AttackMoveTargetHoldTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAttackMoveCancelVelocityOnExit;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAttackMovePredictTargetVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAttackMoveTargetOffsetIgnoreCollisions;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float HandLockPhysicsForceSpringTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector LastHandLockPhysicsForceDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bCrouchedInsideLowSpace;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DodgeDuration;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedDodgeTimeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedDodgeDistanceMultiplier;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DodgeDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UCurveBase* DodgeCurve;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DodgeTimestamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDodgeDeceleration;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult DodgeTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDodgeFaceYaw;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DodgeMaxYawVelDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bTeleportCameraLerpInsteadOfFade;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TeleportCameraFadeOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TeleportCameraFadeInTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TeleportCameraLerpTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxTeleportSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxTeleportSpeedCrouched;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxTeleportSpeedCrawl;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxWalkSpeedDrag;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxWalkSpeedWinded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxWalkSpeedWindedCrouched;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxWalkSpeedWindedCrawl;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowGrippingClimbableSurfacesWhileWinded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandMove ClimbingGruntMove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp ClimbingGruntTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* ClimbingGruntSound;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* ClimbingMantleSound;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* WalkingNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* CrouchedNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* CrawlNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* TeleportWalkingNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* TeleportCrouchedNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* TeleportCrawlNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* GrabAndPullNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* GrabAndPullCrouchNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* GrabAndPullCrawlNoiseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NoiseDistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NoiseTimeThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NoiseVelocityInterpolationFactor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bHandLocksLimitMovement;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandLockMinDistance2D;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandLockArmLengthMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandLockPhysicsForceMinAnalogInput;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* HandLockPhysicsForceCurve;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FFloatRK4SpringInterpolator HandLockPhysicsForceSpring;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandLockPhysicsForceOneHandMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HandLockPhysicsForceTwoHandMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float CrouchedInsideLowSpaceRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanDodge;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveBase* DefaultDodgeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DodgeCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DodgeStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DodgeTimeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DodgeDistanceMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DodgeBrakingDeceleration;
    
public:
    UTWDCharacterMovementComponent();
    UFUNCTION(BlueprintCallable)
    bool UpdateAttackMoveTargetOffset(float Offset);
    
    UFUNCTION(BlueprintPure)
    bool IsExecutingAttackMove(FVector& OutMoveLocation, AActor*& OutMoveTarget, FName& OutMoveTargetSocket, bool& bOutFaceTargetYaw, bool& bOutFaceTargetPitch) const;
    
    UFUNCTION(BlueprintPure)
    bool IsDodging(FVector& OutDirection, float& OutDuration, float& OutTimeRemaining, float& OutDamageReduction) const;
    
    UFUNCTION(BlueprintPure)
    float GetPerceptionNoiseLevel() const;
    
    UFUNCTION(BlueprintPure)
    FRotator GetOffsetFacingFromMovement() const;
    
    UFUNCTION(BlueprintPure)
    float GetNoiseLevel(TEnumAsByte<EMovementMode> NoiseMovementMode, uint8 NoiseCustomMode) const;
    
    UFUNCTION(BlueprintPure)
    float GetMaxTeleportSpeedCrouched() const;
    
    UFUNCTION(BlueprintPure)
    float GetMaxTeleportSpeed() const;
    
    UFUNCTION(BlueprintPure)
    float GetMaxNoiseLevel(bool bForceRefresh) const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetFootstepSound(UPhysicalMaterial* PhysMat, UObject* CurrentSound) const;
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteTargetDodge(const FHitResult& Target, UCurveBase* InDodgeCurve, bool bCanInterrupt, bool bFaceTargetYaw, float MaxYawVelDeg);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteDodge(const FVector& Direction, UCurveBase* InDodgeCurve, bool bCanInterrupt, bool bFaceDirectionYaw, float MaxYawVelDeg);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteAttackMoveLocation(const FVector& TargetLocation, float Time, float MaxSpeed, float Offset, bool bFaceTargetYaw, bool bFaceTargetPitch, FRotator MaxRotVel, float HoldTime, bool bCancelVelocityOnExit);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteAttackMoveActor(AActor* MoveTarget, FName MoveTargetSocket, float Time, float MaxSpeed, float Offset, bool bFaceTargetYaw, bool bFaceTargetPitch, FRotator MaxRotVel, float HoldTime, bool bCancelVelocityOnExit, bool bPredictTargetVelocity, bool bOffsetIgnoreCollisions);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteAttackMove(const FVector& TargetLocation, AActor* Target, FName TargetSocket, float Time, float MaxSpeed, float Offset, bool bFaceTargetYaw, bool bFaceTargetPitch, FRotator MaxRotVel, float HoldTime, bool bCancelVelocityOnExit, bool bPredictTargetVelocity, bool bOffsetIgnoreCollisions);
    
    UFUNCTION(BlueprintCallable)
    void CancelDodge(bool bCancelVelocity);
    
    UFUNCTION(BlueprintCallable)
    void CancelAttackMove(bool bCancelVelocity);
    
};

