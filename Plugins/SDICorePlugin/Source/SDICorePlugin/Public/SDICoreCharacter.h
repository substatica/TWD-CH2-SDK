#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Character.h"
#include "SDIPooledObjectInterface.h"
#include "SDIDamageTakenReplicationInterface.h"
#include "Chaos/ChaosEngineInterface.h"
#include "SDIDamageInflictedReplicationInterface.h"
#include "SDIAimAssistTargetInterface.h"
#include "SDIPooledObjectBlueprintInterface.h"
#include "InputCoreTypes.h"
#include "SDIPooledObjectData.h"
#include "SDIReplicatedRagdollBone.h"
#include "SDIInputStick.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDICoreCharacterADSChangedSignatureDelegate.h"
#include "SDIReplicatedDamageData.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "EAIBaseGroundMovementSpeedType.h"
#include "SDICoreCharacter.generated.h"

class ASDIObjectPool;
class USDICollisionChannelIgnoranceComponent;
class USDIRigidBodySleeperComponent;
class UPhysicalAnimationComponent;
class USDICoreUtilityAI;
class APlayerController;

UCLASS()
class SDICOREPLUGIN_API ASDICoreCharacter : public ACharacter, public ISDIDamageTakenReplicationInterface, public ISDIDamageInflictedReplicationInterface, public ISDIPooledObjectInterface, public ISDIPooledObjectBlueprintInterface, public ISDIAimAssistTargetInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDICollisionChannelIgnoranceComponent* CapsuleCollisionIgnoranceComp;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDICollisionChannelIgnoranceComponent* MeshCollisionIgnoranceComp;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIRigidBodySleeperComponent* RigidBodySleeperComponent;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UPhysicalAnimationComponent* RagdollPhysicalAnimationComponent;
    
    UPROPERTY(EditDefaultsOnly)
    float SprintCancelMinVelocityPct;
    
    UPROPERTY(EditDefaultsOnly)
    float SprintCancelTime;
    
    UPROPERTY(EditDefaultsOnly)
    float SprintMinAnalogInput;
    
    UPROPERTY(EditDefaultsOnly, Replicated)
    TArray<FSDIReplicatedRagdollBone> RepRagdollBones;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIInputStick InputMoveStick;
    
    UPROPERTY(EditAnywhere)
    FName RagdollConstraintProfile;
    
    UPROPERTY(EditAnywhere)
    FName RagdollRootBoneName;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<USDICoreUtilityAI> UtilityAIClass;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NetObstructedCullDistanceSquared;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_bRepADS)
    bool bRepADS;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bCtrlSprint;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bCtrlSprintWasToggled;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float SprintCancelTimer;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bCtrlCrouch;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bCtrlCrouchWasToggled;
    
    UPROPERTY(Transient)
    bool bAnyRagdollBonesUpdated;
    
    UPROPERTY(Transient)
    FTimerHandle RecreateRagdollTimerHandle;
    
    UPROPERTY(Transient)
    FTimerHandle OverrideConstraintProfileTimerHandle;
    
    UPROPERTY(Transient)
    FTimerHandle StartPhysicalAnimationTimerHandle;
    
    UPROPERTY(Transient)
    FTimerHandle PhysicalAnimationProfileTimerHandle;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDICoreCharacterADSChangedSignature ADSChangedDelegate;
    
protected:
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepDamageTakenData)
    FSDIReplicatedDamageData RepDamageTakenData;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepDamageInflictedData)
    FSDIReplicatedDamageData RepDamageInflictedData;
    
private:
    UPROPERTY(Transient)
    FSDIPooledObjectData PooledObjectData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName PrimaryAimAssistSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName SecondaryAimAssistSocketName;
    
public:
    ASDICoreCharacter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintPure)
    bool UtilityAIConsumingInput() const;
    
    UFUNCTION(BlueprintCallable)
    void StopRagdollAnimation();
    
    UFUNCTION(BlueprintCallable)
    bool StopRagdoll(const bool bAttachToMeshRoot);
    
    UFUNCTION(BlueprintCallable)
    bool StartRagdollAnimation(float PhysicalAnimationStrength, FName PhysicalAnimationProfileName, float PhysicalAnimationDuration);
    
    UFUNCTION(BlueprintCallable)
    bool StartRagdoll(const bool bStartImmediately, FName OverrideConstraintProfileName, float OverrideConstraintProfileDuration, float PhysicalAnimationStrength, FName PhysicalAnimationProfileName, float PhysicalAnimationDuration, const bool bWasQueued);
    
    UFUNCTION(BlueprintCallable)
    bool SetHandIKTransform(EControllerHand hand, const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable)
    bool SetHandIKOnSurface(EControllerHand hand, const FHitResult& Hit, const FVector& HandHintDirection, bool bHintDirectionIsHandForward);
    
    UFUNCTION(BlueprintCallable)
    bool SetHandIKDirections(EControllerHand hand, const FVector& Location, const FVector& HandForward, const FVector& HandHintDirection, bool bHintDirectionIsPalmDirection);
    
    UFUNCTION(BlueprintCallable)
    bool SetHandIKActive(EControllerHand hand, bool bActive, float BlendTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetBaseGroundMovementSpeedType(EAIBaseGroundMovementSpeedType NewBaseGroundMovementSpeedType);
    
    UFUNCTION(BlueprintCallable)
    void SetADS(bool bADS);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetADS(bool bADS);
    
    UFUNCTION(BlueprintCallable)
    void ResetInputs();
    
    UFUNCTION(BlueprintCallable)
    void RemoveRagdollImpulses(bool bCancelVelocity, bool bQueuedDirect, bool bQueuedRadial);
    
protected:
    UFUNCTION()
    void RecreateRagdoll(const FName& OverrideConstraintProfileName);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void PlayerControllerDetached(APlayerController* PC);
    
    UFUNCTION(BlueprintNativeEvent)
    void PlayerControllerAttached(APlayerController* PC);
    
protected:
    UFUNCTION()
    void OnRep_RepDamageTakenData(const FSDIReplicatedDamageData& OldRepDamageTakenData);
    
    UFUNCTION()
    void OnRep_RepDamageInflictedData(const FSDIReplicatedDamageData& OldRepDamageInflictedData);
    
    UFUNCTION()
    void OnRep_bRepADS(bool bOldRepADS);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnADSChanged(bool bADS);
    
    UFUNCTION()
    void MeshOnPhysicsStateChange();
    
    UFUNCTION(BlueprintPure)
    bool IsThirdPerson() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRagdollQueued() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRagdollAnimationQueued() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRagdollAnimationActiveOrQueued() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRagdollAnimationActive() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRagdollActiveOrQueued() const;
    
    UFUNCTION(BlueprintPure)
    bool IsRagdollActive() const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool IsInImmobileState() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHandIKActive(EControllerHand hand) const;
    
    UFUNCTION(BlueprintPure)
    bool IsFirstPerson() const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool IsADSAllowed() const;
    
    UFUNCTION(BlueprintPure)
    bool IsADS() const;
    
    UFUNCTION(BlueprintCallable)
    void InputToggleSprintReleased();
    
    UFUNCTION(BlueprintCallable)
    void InputToggleSprintPressed();
    
    UFUNCTION(BlueprintCallable)
    void InputToggleCrouchReleased();
    
    UFUNCTION(BlueprintCallable)
    void InputToggleCrouchPressed();
    
    UFUNCTION(BlueprintCallable)
    void InputSprintReleased();
    
    UFUNCTION(BlueprintCallable)
    void InputSprintPressed();
    
    UFUNCTION(BlueprintCallable)
    void InputMoveRightAxis(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputMoveRight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputMoveLeft(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputMoveForwardAxis(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputMoveForward(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputMoveBackward(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputCrouchReleased();
    
    UFUNCTION(BlueprintCallable)
    void InputCrouchPressed();
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<USDICoreUtilityAI> GetUtilityAIClass() const;
    
    UFUNCTION(BlueprintPure)
    FSDIReplicatedDamageData GetLastDamageTaken() const;
    
    UFUNCTION(BlueprintPure)
    FSDIReplicatedDamageData GetLastDamageInflicted() const;
    
    UFUNCTION(BlueprintCallable)
    bool EnableHandIKEffectorSpring(EControllerHand hand, bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    bool AddRagdollRadialImpulse(FVector Origin, float Radius, float Strength, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange);
    
    UFUNCTION(BlueprintCallable)
    bool AddRagdollImpulseAtLocation(FVector Impulse, FVector Location, FName BoneName);
    
    UFUNCTION(BlueprintCallable)
    bool AddRagdollImpulse(FVector Impulse, FName BoneName, bool bVelChange);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void ReturnToPoolNextFrame() override PURE_VIRTUAL(ReturnToPoolNextFrame,);
    
    UFUNCTION(BlueprintCallable)
    void ReturnToPool() override PURE_VIRTUAL(ReturnToPool,);
    
    UFUNCTION(BlueprintCallable)
    bool IsInsidePool() const override PURE_VIRTUAL(IsInsidePool, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsFromPool() const override PURE_VIRTUAL(IsFromPool, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsBeingReturnedToPoolNextFrame() const override PURE_VIRTUAL(IsBeingReturnedToPoolNextFrame, return false;);
    
    UFUNCTION(BlueprintCallable)
    ASDIObjectPool* GetPool() const override PURE_VIRTUAL(GetPool, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    float GetAcquiredTimestamp() const override PURE_VIRTUAL(GetAcquiredTimestamp, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    void CancelReturnToPoolNextFrame() override PURE_VIRTUAL(CancelReturnToPoolNextFrame,);
    
};

