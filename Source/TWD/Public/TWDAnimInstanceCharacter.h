#pragma once
#include "CoreMinimal.h"
#include "RVector.h"
#include "SDIEnumTypeHandle.h"
#include "SDIAnimInstanceCharacter.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "RRotator.h"
#include "UObject/NoExportTypes.h"
#include "SDIDoubleRubberBandVector.h"
#include "ETWDNonVRGrappleAnimState.h"
#include "ECharacterBehavior.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ETWDCharacterHitDirection.h"
#include "PlayAnimationResultCallbackDelegate.h"
#include "ETWDCharacterHitRegion.h"
#include "SDIReplicatedDamageData.h"
#include "ECharacterEmotion.h"
#include "ECharacterPose.h"
#include "ECharacterGesture.h"
#include "TWDAnimInstanceCharacter.generated.h"

class USceneComponent;
class AActor;

UCLASS(NonTransient)
class TWD_API UTWDAnimInstanceCharacter : public USDIAnimInstanceCharacter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    bool bIsInAir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    bool bIsCrawlingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    FVector LookAtLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float LookAtAlpha;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    USceneComponent* LookAtTargetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    bool bForwardMeleeAttack;
/*
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator GrappleOffsetSpring;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator GrappleOffsetRotSpring;
*/        
    UPROPERTY(EditAnywhere)
    FSDIDoubleRubberBandVector GrappleOffsetRubberBand;
    
    UPROPERTY(EditAnywhere)
    FRVector GrappleBlendSpaceExtent;
    
    UPROPERTY(EditAnywhere)
    float GrappleBlendSpaceSphericalWeight;
    
    UPROPERTY(EditAnywhere)
    FVector GrappleHandOffset;
    
    UPROPERTY(EditAnywhere)
    FRRotator GrappleHandRotationExtent;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderGrappleBounds;
/*
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator GrappleAttackOffsetSpring;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator GrappleAttackPushBackOffsetSpring;
*/  
    UPROPERTY(EditAnywhere)
    FRVector GrappleAttackBlendSpaceExtent;
    
    UPROPERTY(EditAnywhere)
    float GrappleAttackBlendSpaceSphericalWeight;
    
    UPROPERTY(EditAnywhere)
    bool bGrappleAttackHandHMDIKOffsetInCharacterSpace;
    
    UPROPERTY(EditAnywhere)
    FVector GrappleAttackLeftHandHMDIKOffset;
    
    UPROPERTY(EditAnywhere)
    FVector GrappleAttackRightHandHMDIKOffset;
    
    UPROPERTY(EditAnywhere)
    FVector GrappleAttackHandArmWristIKOffset;
    
    UPROPERTY(EditAnywhere)
    FVector GrappleAttackHandArmElbowIKOffset;
    
    UPROPERTY(EditAnywhere)
    FName LeftHandGrappleSocket;
    
    UPROPERTY(EditAnywhere)
    FName RightHandGrappleSocket;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderGrappleAttackBounds;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderDismemberBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDNonVRGrappleAnimState NonVRGrappleAttackAnimState;
/*
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator BrainedOffsetSpring;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator StabOffsetRotSpring;
*/    
    UPROPERTY(EditAnywhere)
    float StabOffsetRotVelocityDeg;
    
    UPROPERTY(EditAnywhere)
    FRVector BrainedBlendSpaceExtent;
    
    UPROPERTY(EditAnywhere)
    float BrainedBlendSpaceSphericalWeight;
    
    UPROPERTY(EditAnywhere)
    FVector BrainedBlendSpaceOffset;
    
    UPROPERTY(EditAnywhere)
    float BrainedPullDirectionTargetDecel;
    
    UPROPERTY(EditAnywhere)
    float BrainedPullDirectionVelocityDecel;
    
    UPROPERTY(EditAnywhere)
    FRRotator BrainedHandRotationExtent;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderBrainedBounds;
    
    UPROPERTY(EditAnywhere)
    bool bAllowHeadHeldStateWhenStabbed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsInGrappleState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GrappleHandMultiplier;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector GrappleOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator GrappleOffsetRot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GrapplePercent;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGrappleAttacking;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGrappleIsHoldingArm;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector GrappleAttackLeftHandIKTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGrappleAttackLeftHandIKRotationValid;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator GrappleAttackLeftHandIKRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector GrappleAttackRightHandIKTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGrappleAttackRightHandIKRotationValid;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator GrappleAttackRightHandIKRotation;
    
    UPROPERTY(Transient)
    FRotator CurrentGrappleOffsetRot;
    
    UPROPERTY(Transient)
    FTransform LastGrappleHandTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsInGrappleAttackState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsInGrappleAttackPushBackState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector GrappleAttackOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector GrappleAttackBreakDirection;
    
    UPROPERTY(Transient)
    FTransform LastGrappleAttackTargetTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsInBrainedState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsInHeadHeldState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsBeingDismembered;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector BrainedOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator StabOffsetRot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector BrainedStabDirection;
    
    UPROPERTY(Transient)
    FRotator CurrentStabOffsetRot;
    
    UPROPERTY(Transient)
    FQuat CurrentStabOffsetQuat;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHasHeldStabWeapon;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName CachedSnapshot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName CachedDeadSnapshot;
    
    UPROPERTY(Transient)
    float TimeWhenPhysicsOffBlendStops;
    
    UPROPERTY(EditAnywhere)
    float PhysicsOffBlendTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedDeadAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsInStabState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bRequestDeath;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bCanSeeTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bTargetIsPlayer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bSeesNonhostilePlayer;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    bool bRecoil;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    bool bReadyToFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    FVector TargetLocation;
    
    UPROPERTY(EditDefaultsOnly)
    float IkHandGunTolerance;
    
    UPROPERTY(Transient)
    float AngularVelocity;
    
    UPROPERTY(EditAnywhere)
    float AngularVelocityScale;
    
    UPROPERTY(EditAnywhere)
    float AimOffsetInterpSpeed;
    
    UPROPERTY(EditAnywhere)
    FName AimOffsetPivotName;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator AimOffset;
    
    UPROPERTY(Transient)
    FQuat AimOffsetRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator IkHandGunRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ECharacterBehavior CharacterBehavior;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsAggravate;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsFlee;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsThreaten;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float BlendInWeight;
    
    UPROPERTY(Transient)
    float BlendInTarget;
    
    UPROPERTY(EditAnywhere)
    float BlendInSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float BlendOutWeight;
    
    UPROPERTY(Transient)
    float BlendOutTarget;
    
    UPROPERTY(EditAnywhere)
    float BlendOutSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float BlendInOutWeightMax;
    
    UPROPERTY(EditAnywhere)
    FName StateMachineName[2];
    
    UPROPERTY(EditAnywhere)
    float StateElaspedTime;
    
    UPROPERTY(Transient)
    int32 StateMachineIndex[2];
    
    UTWDAnimInstanceCharacter();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StopAnimationAction();
    
    UFUNCTION(BlueprintImplementableEvent)
    void StartInventoryExchange(bool bTake);
    
    UFUNCTION(BlueprintCallable)
    void SetLocomotionSpeed(float newSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetInAir(bool inAir);
    
    UFUNCTION(BlueprintCallable)
    void SetHeadLookAtTargetComponent(USceneComponent* TargetComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetHeadLookAtLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    void SetHeadLookAtAlpha(float Alpha);
    
    UFUNCTION(BlueprintCallable)
    void SetGrappleAttackBreakDirection(FVector Direction);
    
    UFUNCTION(BlueprintCallable)
    void SetForwardMeleeAttack(bool IsAttacking);
    
    UFUNCTION(BlueprintCallable)
    void SetBlendOutWeight(float BlendWeight, float InterpolationSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetBlendInWeight(float BlendWeight, float InterpolationSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PlayAnimationAction(FSDIEnumTypeHandle EnumTypeHandle, const FPlayAnimationResultCallback& PlayAnimationResultCallback, bool& RequestResult, float& AnimLength);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnWeaponClassChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnPersonalSpacePushback();
    
    UFUNCTION(BlueprintCallable)
    void OnKnockBack();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnInventoryReceive(bool bLoop);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnInventoryGive(bool bLoop);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnHitReaction(ETWDCharacterHitRegion Region, FVector DirectionVector, ETWDCharacterHitDirection Direction, const FSDIReplicatedDamageData& DamageTakenData, bool bHeadshot, bool bHeadshotPenetration);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnHitByPhysicsActor(ETWDCharacterHitRegion Region, FVector DirectionVector, ETWDCharacterHitDirection Direction, AActor* Instigator, float WithSpeed, float WithMass);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnGrapplePushBack(const FVector& Direction, float PushBackDistance, float PushBackTime);
    
    UFUNCTION(BlueprintImplementableEvent)
    bool IsInInventoryExchange() const;
    
    UFUNCTION(BlueprintPure)
    bool IsInCombat() const;
    
    UFUNCTION(BlueprintPure)
    TArray<float> GetVisemeWeights() const;
    
    UFUNCTION(BlueprintPure)
    FRotator GetIkHandGunTargetRotation() const;
    
    UFUNCTION(BlueprintPure)
    ECharacterPose GetCharacterPose() const;
    
    UFUNCTION(BlueprintPure)
    ECharacterGesture GetCharacterGesture() const;
    
    UFUNCTION(BlueprintPure)
    ECharacterEmotion GetCharacterEmotion() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    void AbortInventoryExchange();
    
};

