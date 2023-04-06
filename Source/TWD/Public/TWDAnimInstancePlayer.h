#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIAnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "TWDHandItemState.h"
#include "TWDNonVRMeleeAttackDetails.h"
#include "UObject/NoExportTypes.h"
#include "ETWDNonVREquipmentActionType.h"
#include "ETWDNonVRMeleeAttackType.h"
#include "ETWDNonVRGrappleAnimState.h"
#include "Engine/SpringInterpolator.h"
#include "InputCoreTypes.h"
#include "TWDAnimInstancePlayer.generated.h"

class ASDIHeldActor;
class UTWDAnimInstancePlayerHeldActor;

UCLASS(NonTransient)
class TWD_API UTWDAnimInstancePlayer : public USDIAnimInstance {
    GENERATED_BODY()
public:
protected:

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRK4SpringInterpolator AimRotationLagPitchSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRK4SpringInterpolator AimRotationLagYawSpring;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator AimRotationLagLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AimRotationLagMoveForwardPitchVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AimRotationLagMoveRightYawVel;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRK4SpringInterpolator SpineDragSpring;
     
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SpineDragLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName SpineDragSpringMaskCurveName;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevCharacterRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator CharacterRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevCharacterRotationVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator CharacterRotationVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TEnumAsByte<EMovementMode> PrevMovementMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TEnumAsByte<EMovementMode> MovementMode;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector PrevVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector Velocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsMoving;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevVelocityDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float VelocityDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevLateralSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LateralSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float VerticalSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ForwardSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RightSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LateralSpeedPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ForwardSpeedPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RightSpeedPercent;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasCrouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsCrouched;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWantsToSprint;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasSprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsSprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxWalkSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxSpeedWithoutSprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxSprintSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevStaminaPct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StaminaPct;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasWinded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsWinded;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevAimRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator AimRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevAimRotationVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator AimRotationVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevAimRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator AimRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevAimRotationLag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator AimRotationLag;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevSpineDrag;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float SpineDrag;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevSpineDragVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float SpineDragVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevSpineDragAccel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float SpineDragAccel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevPureAimRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator PureAimRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevPureAimRotationVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator PureAimRotationVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevPureAimRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator PureAimRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevRecoilAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator RecoilAimOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevFlinchAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator FlinchAimOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevSwayAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator SwayAimOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevLockonAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator LockonAimOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevAnimatedAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator AnimatedAimOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasADS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsADS;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasADSDesired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsADSDesired;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasHipFiring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsHipFiring;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevAngleOfStrike;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AngleOfStrike;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FFloatRK4SpringInterpolator AngleOfStrikeSpring;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevAngleOfStrikeCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AngleOfStrikeCharge;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasSpecialMeleeActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsSpecialMeleeActive;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDNonVRMeleeAttackType LastSpecialMelee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDNonVRMeleeAttackType SpecialMelee;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDNonVRMeleeAttackType LastSpecialMeleeDesired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDNonVRMeleeAttackType SpecialMeleeDesired;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasSpecialMeleeDesired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsSpecialMeleeDesired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsWeaponStuckOrStabbed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasWeaponStuckOrStabbed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWeaponStickCharged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWeaponStickWeakpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWeaponStickWeakpointIsDiseased;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWeaponStickRemoved;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWeaponStickRemovedSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float WeaponStickProgress;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevWeaponStickProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float WeaponStickAngle;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevWeaponStickAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float WeaponStickRemoval;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevWeaponStickRemoval;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasPreparingMeleeAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsPreparingMeleeAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsPlayingMeleeAttackAnim;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasPlayingMeleeAttackAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDNonVRMeleeAttackDetails MeleeAttackDetails;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDNonVRMeleeAttackDetails PrevMeleeAttackDetails;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDHandItemState LeftHandItem;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDHandItemState RightHandItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsPlayingGunActionAnim;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasPlayingGunActionAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsPlayingEquipmentActionAnim;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasPlayingEquipmentActionAnim;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsNonVRObjectInteracting;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWasNonVRObjectInteracting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName HeldActorLinkedGraphTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<TSubclassOf<ASDIHeldActor>, TSubclassOf<UTWDAnimInstancePlayerHeldActor>> HeldActorToAnimInstanceMap;
    
    UPROPERTY(BlueprintReadWrite)
    TSubclassOf<ASDIHeldActor> HeldActorClassWithActiveLinkedGraph;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDNonVRGrappleAnimState NonVRGrappleAnimState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDNonVRGrappleAnimState PrevNonVRGrappleAnimState;
    
public:
    UTWDAnimInstancePlayer();
    UFUNCTION(BlueprintCallable)
    void SetSpineDragSpringConstants(float SpringStiffness, float DampeningRatio);
    
    UFUNCTION(BlueprintCallable)
    void SetAngleOfStrikeSpringConstants(float SpringStiffness, float DampeningRatio);
    
    UFUNCTION(BlueprintCallable)
    void SetAimRotationLagYawSpringConstants(float SpringStiffness, float DampeningRatio);
    
    UFUNCTION(BlueprintCallable)
    void SetAimRotationLagPitchSpringConstants(float SpringStiffness, float DampeningRatio);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void OnMovementModeChanged();
    
    UFUNCTION(BlueprintNativeEvent)
    void OnCrouchChanged();
    
    UFUNCTION(BlueprintCallable)
    void LinkHeldActorAnimInstance(TSubclassOf<ASDIHeldActor> HeldActorClass);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsHeldOrHasEquipmentActionArr(EControllerHand hand, const TArray<TSubclassOf<ASDIHeldActor>>& Classes, TSubclassOf<ASDIHeldActor>& OutClass) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHeldOrHasEquipmentAction(EControllerHand hand, TSubclassOf<ASDIHeldActor> Class) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHeldArr(EControllerHand hand, const TArray<TSubclassOf<ASDIHeldActor>>& Classes, TSubclassOf<ASDIHeldActor>& OutClass) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHeld(EControllerHand hand, TSubclassOf<ASDIHeldActor> Class) const;
    
    UFUNCTION(BlueprintPure)
    bool GetInterruptEquipmentActionArr(EControllerHand hand, const TArray<TSubclassOf<ASDIHeldActor>>& Classes, TSubclassOf<ASDIHeldActor>& OutClass, ETWDNonVREquipmentActionType& OutActionType) const;
    
    UFUNCTION(BlueprintPure)
    bool GetInterruptEquipmentAction(EControllerHand hand, TSubclassOf<ASDIHeldActor> Class, TSubclassOf<ASDIHeldActor>& OutClass, ETWDNonVREquipmentActionType& OutActionType) const;
    
    UFUNCTION(BlueprintPure)
    bool GetEquipmentActionArr(EControllerHand hand, const TArray<TSubclassOf<ASDIHeldActor>>& Classes, TSubclassOf<ASDIHeldActor>& OutClass, ETWDNonVREquipmentActionType& OutActionType) const;
    
    UFUNCTION(BlueprintPure)
    bool GetEquipmentAction(EControllerHand hand, TSubclassOf<ASDIHeldActor> Class, ETWDNonVREquipmentActionType& OutActionType) const;
    
};

