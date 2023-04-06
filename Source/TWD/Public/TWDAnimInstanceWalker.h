#pragma once
#include "CoreMinimal.h"
#include "TWDAnimInstanceCharacter.h"
#include "Curves/CurveFloat.h"
#include "UObject/NoExportTypes.h"
#include "EGender.h"
#include "ETWDCharacterGrappleLocation.h"
#include "TWDAnimInstanceWalker.generated.h"

class ATWDAIController;
class UAnimSequenceBase;
class ATWDWalkerAICharacter;
class UTWDCharacterMovementComponent;

UCLASS(NonTransient)
class TWD_API UTWDAnimInstanceWalker : public UTWDAnimInstanceCharacter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float NearTargetDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LungeDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GrappleAttackMinDistanceHandToClavicle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GrappleAttackMaxDistanceHandToClavicle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRuntimeFloatCurve GrappleLungeHandIkAlphaCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRuntimeFloatCurve GrappleArmDistanceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRuntimeFloatCurve FidgetProbabilityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<UAnimSequenceBase*> FidgetAnimations;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ATWDWalkerAICharacter* TWDWalker;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UTWDCharacterMovementComponent* TWDWalkerMovementComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float SpeedHorizontal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EGender Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsEating;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWasBreakingObsticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsPlayingStumbleMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsMovingAndAggro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float locomotionPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float locomotionAggroPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bTurnInPlace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bTurnInPlaceTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStopTurnInPlace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStopTurnInPlaceTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsAggro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWasAggroLastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsFrustrated;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsBreakingObstacle;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsObstacleBroken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsHeadTracking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsEyeTrackingOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector CurrentLookAtLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ATWDAIController* AICTWDWalker;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bNearTarget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAboutToLunge;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsLunging;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsFailedLunge;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GrappleLungeHandIKAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GrappleArmDistanceAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GrappleAttackClavicleRotationAlphaLeft;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GrappleAttackClavicleRotationAlphaRight;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDCharacterGrappleLocation GrappleArm;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsPlayerDead;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UAnimSequenceBase* CurrentFidgetAnimation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float AdditiveFidgetAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsInAnyCombatRing;
    
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bSurpriseDoorBreaking;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsDead;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsGrapplePushBackTrigger;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsGrapplePushBack;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TimeSinceLastFidget;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsFidgeting;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GrappleMontageBodyAlpha;
    
    UPROPERTY(Transient)
    float TimeInGrappleAttackState;
    
public:
    UTWDAnimInstanceWalker();
protected:
    UFUNCTION(BlueprintCallable)
    void TWDAnimBP_CompleteIdleFidget();
    
    UFUNCTION(BlueprintCallable)
    void TWDAnimBP_CalculateDirection();
    
    UFUNCTION(BlueprintCallable)
    void TurnInPlace_SetFlags();
    
    UFUNCTION(BlueprintCallable)
    void SetCharacterValues();
    
public:
    UFUNCTION(BlueprintPure)
    UAnimSequenceBase* GetRandomAnimation(const TArray<UAnimSequenceBase*>& inArray) const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void CombatAndLookAtValues_SetAggroValues();
    
    UFUNCTION(BlueprintCallable)
    bool CombatAndLookAtValues_HeadTracking();
    
    UFUNCTION(BlueprintCallable)
    float AverageFloatArrayNativized(TArray<float> inArray);
    
    UFUNCTION(BlueprintCallable)
    void AnimGraphValues_Locomotion();
    
};

