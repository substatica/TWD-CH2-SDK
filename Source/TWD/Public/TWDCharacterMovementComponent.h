#pragma once
#include "CoreMinimal.h"
#include "RFloatExp.h"
#include "SDICharacterAdvancedMovementComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerHandMove.h"
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
    UPROPERTY(Transient)
    float NoiseVelocity;
    
    UPROPERTY(Transient)
    float NoiseDistance;
    
    UPROPERTY(Transient)
    float NoiseTime;
    
    UPROPERTY(Transient)
    float MaxNoiseLevel;
    
    UPROPERTY(Transient)
    float ClimbingGruntTimer;
    
    UPROPERTY(Transient)
    FVector AttackMoveTargetLoc;
    
    UPROPERTY(Transient)
    FVector AttackMoveTargetRelLoc;
    
    UPROPERTY(Transient)
    FName AttackMoveTargetSocket;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> AttackMoveTarget;
    
    UPROPERTY(Transient)
    float AttackMoveTargetOffset;
    
    UPROPERTY(Transient)
    float AttackMoveTargetMaxSpeed;
    
    UPROPERTY(Transient)
    float AttackMoveTargetDuration;
    
    UPROPERTY(Transient)
    bool bAttackMoveTargetFaceTargetYaw;
    
    UPROPERTY(Transient)
    bool bAttackMoveTargetFaceTargetPitch;
    
    UPROPERTY(Transient)
    FRotator AttackMoveTargetFaceTargetMaxRotVel;
    
    UPROPERTY(Transient)
    float AttackMoveTargetHoldTime;
    
    UPROPERTY(Transient)
    bool bAttackMoveCancelVelocityOnExit;
    
    UPROPERTY(Transient)
    bool bAttackMovePredictTargetVelocity;
    
    UPROPERTY(Transient)
    bool bAttackMoveTargetOffsetIgnoreCollisions;
    
    UPROPERTY(Transient)
    float HandLockPhysicsForceSpringTarget;
    
    UPROPERTY(Transient)
    FVector LastHandLockPhysicsForceDirection;
    
    UPROPERTY(Transient)
    bool bCrouchedInsideLowSpace;
    
    UPROPERTY(Transient)
    float DodgeDuration;
    
    UPROPERTY(Transient)
    float CachedDodgeTimeMultiplier;
    
    UPROPERTY(Transient)
    float CachedDodgeDistanceMultiplier;
    
    UPROPERTY(Transient)
    FVector DodgeDirection;
    
    UPROPERTY(Transient)
    UCurveBase* DodgeCurve;
    
    UPROPERTY(Transient)
    float DodgeTimestamp;
    
    UPROPERTY(Transient)
    bool bDodgeDeceleration;
    
    UPROPERTY(Transient)
    FHitResult DodgeTarget;
    
    UPROPERTY(Transient)
    bool bDodgeFaceYaw;
    
    UPROPERTY(Transient)
    float DodgeMaxYawVelDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bTeleportCameraLerpInsteadOfFade;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float TeleportCameraFadeOutTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float TeleportCameraFadeInTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float TeleportCameraLerpTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxTeleportSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxTeleportSpeedCrouched;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxTeleportSpeedCrawl;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxWalkSpeedDrag;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxWalkSpeedWinded;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxWalkSpeedWindedCrouched;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxWalkSpeedWindedCrawl;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAllowGrippingClimbableSurfacesWhileWinded;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIPlayerHandMove ClimbingGruntMove;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRFloatExp ClimbingGruntTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UObject* ClimbingGruntSound;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UObject* ClimbingMantleSound;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* WalkingNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* CrouchedNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* CrawlNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* TeleportWalkingNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* TeleportCrouchedNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* TeleportCrawlNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* GrabAndPullNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* GrabAndPullCrouchNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* GrabAndPullCrawlNoiseCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NoiseDistanceThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NoiseTimeThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NoiseVelocityInterpolationFactor;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bHandLocksLimitMovement;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float HandLockMinDistance2D;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float HandLockArmLengthMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float HandLockPhysicsForceMinAnalogInput;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* HandLockPhysicsForceCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FFloatRK4SpringInterpolator HandLockPhysicsForceSpring;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float HandLockPhysicsForceOneHandMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float HandLockPhysicsForceTwoHandMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float CrouchedInsideLowSpaceRadiusMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanDodge;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveBase* DefaultDodgeCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DodgeCooldown;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DodgeStaminaCost;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float DodgeTimeMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float DodgeDistanceMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
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

