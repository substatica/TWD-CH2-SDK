#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SDIDotLerpFloatAdvanced.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDIBlendOption.h"
#include "EAIBaseGroundMovementSpeedType.h"
#include "UObject/NoExportTypes.h"
#include "SDICoreCharacterMovementComponent.generated.h"

class UPrimitiveComponent;
class UCurveFloat;
class AActor;

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDICoreCharacterMovementComponent : public UCharacterMovementComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxJogSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxRunSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxDashSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxStrollSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxSprintSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxFallSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanSprint;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanSprintWithoutStickDeflection;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bSprintToggleDoesNotCancelSprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinAnalogWalkSpeedCrouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinAnalogWalkSpeedSprint;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIDotLerpFloatAdvanced MovementSpeedMultiplierDirectionLerp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIDotLerpFloatAdvanced SprintSpeedDirectionLerp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FFloatRK4SpringInterpolator MaxWalkSpeedSpring;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FFloatRK4SpringInterpolator MaxWalkSpeedCrouchedSpring;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FFloatRK4SpringInterpolator MaxSprintSpeedSpring;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* CollisionMaxSpeedMultiplierCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIBlendOption CollisionMaxSpeedMultiplierNormalDotBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float CollisionMaxSpeedMultiplierCapsuleHeightScale;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* FallingCollisionMaxSpeedMultiplierCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIBlendOption FallingCollisionMaxSpeedMultiplierNormalDotBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float FallingCollisionMaxSpeedMultiplierCapsuleHeightScale;
    
    UPROPERTY(EditDefaultsOnly)
    FName RagdollRootBoneName;
    
    UPROPERTY(EditDefaultsOnly)
    float RagdollLowVelocityThreshold;
    
    UPROPERTY(EditAnywhere)
    EAIBaseGroundMovementSpeedType BaseGroundMovementSpeedType;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float MovementModeTime;
    
    UPROPERTY(Replicated, Transient)
    bool bRepWantsToSprint;
    
    UPROPERTY(Transient)
    float RagdollLowVelocityTime;
    
    UPROPERTY(Transient)
    float CollisionMaxSpeedMultiplierCurveRange;
    
    UPROPERTY(Transient)
    float FallingCollisionMaxSpeedMultiplierCurveRange;
    
    UPROPERTY(Transient)
    TArray<FHitResult> CollisionMaxSpeedSweepResults;
    
    UPROPERTY(Transient)
    float CollisionMaxSpeedMultiplier;
    
    UPROPERTY(Instanced, Transient)
    TArray<TWeakObjectPtr<UPrimitiveComponent>> MovementOverrideOverlaps;
    
    UPROPERTY(Transient)
    bool bComponentOverlapForceCrouch;
    
    UPROPERTY(Transient)
    FVector TotalMovementVelocity;
    
    UPROPERTY(Transient)
    FVector TotalMovementAngularVelocity;
    
    UPROPERTY(Transient)
    FVector StartTotalMovementVelocity;
    
    UPROPERTY(Transient)
    FVector StartTotalMovementAngularVelocity;
    
    UPROPERTY(Transient)
    FVector StartAngularVelocityLinearVelLeft;
    
    UPROPERTY(Transient)
    FVector StartAngularVelocityLinearVelRight;
    
    UPROPERTY(Transient)
    float StartBaseEyeHeight;
    
    UPROPERTY(Transient)
    FVector StartUpdatedComponentLocation;
    
public:
    USDICoreCharacterMovementComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetBaseGroundMovementSpeedType(EAIBaseGroundMovementSpeedType NewBaseGroundMovementSpeedType);
    
    UFUNCTION()
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintPure)
    bool IsSprinting(bool bCheckVelocity) const;
    
    UFUNCTION(BlueprintPure)
    bool IsRagdoll(bool& bOutOnFloor, float& OutLowVelocityTime) const;
    
    UFUNCTION()
    bool IsForceCrouch() const;
    
    UFUNCTION(BlueprintPure)
    float GetMaxSprintSpeed() const;
    
    UFUNCTION(BlueprintPure)
    float GetMaxSpeedWithoutSprinting() const;
    
    UFUNCTION(BlueprintPure)
    EAIBaseGroundMovementSpeedType GetBaseGroundMovementSpeedType() const;
    
};

