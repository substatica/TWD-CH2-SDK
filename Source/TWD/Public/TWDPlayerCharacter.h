#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ETWDNonVREquipmentSlot.h"
#include "SDITimestampInputButton.h"
#include "Engine/EngineTypes.h"
#include "TWDCharacter.h"
#include "SDITuningInterface.h"
#include "Engine/EngineTypes.h"
#include "SDIDotLerpFloat.h"
#include "UObject/NoExportTypes.h"
#include "SDIBlendOption.h"
#include "TWDNonVREquipmentActionDetails.h"
#include "TWDNonVRMeleeAttackDetails.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "Engine/EngineTypes.h"
#include "QFloatExp.h"
#include "RFloat.h"
#include "RFloatExp.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "SDIPlayerHandInteractComponentEntry.h"
#include "UObject/NoExportTypes.h"
#include "ETWDNonVRMeleeAttackType.h"
#include "SDIAnimNotifyStateData.h"
#include "ETWDNonVRGrappleMinigameState.h"
#include "ETWDGunAction.h"
#include "ETWDNonVRGrappleAnimState.h"
#include "Engine/SpringInterpolator.h"
#include "SDITuningAccumulator.h"
#include "SDIReplicatedTuningModifier.h"
#include "SDITuningAttribute_TWDPlayerCharacter.h"
#include "SDITuningAttribute_TWDCharacterMovementComponent.h"
#include "EGender.h"
#include "ETWDNonVREquipmentType.h"
#include "TWDPlayerCharacter.generated.h"

class UTWDSaveGame;
class USDIPointGripComponent;
class UPhysicsConstraintComponent;
class USceneComponent;
class ASDIHeldActor;
class ASDIInteractiveActor;
class UChildActorComponent;
class ATWDPlayerLootDrop;
class ATWDPlayerInventorySlot;
class ATWDWeaponGun;
class ATWDAmmoPouch;
class ATWDBackpack;
class ATWDNotebook;
class ATWDAIPerceptionModifierVolume;
class ATWDFlashlight;
class UMaterialParameterCollection;
class UAkAudioEvent;
class USDIPlayerVoiceAkComponent;
class ASDIInventoryActor;
class ASDIWeaponFirearm;
class UCurveBase;
class ATWDPlayerCharacter;
class ATWDWeaponActor;
class UTWDAnimNotifyState_EquipmentAction;
class UTWDAnimNotifyState_Grapple;
class UWidgetComponent;
class AActor;
class UPrimitiveComponent;

UCLASS()
class TWD_API ATWDPlayerCharacter : public ATWDCharacter, public ISDITuningInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bInTutorial;
    
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UPhysicsConstraintComponent* NonVRLeftHandPhysicsConstraint;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UPhysicsConstraintComponent* NonVRRightHandPhysicsConstraint;
    
    UPROPERTY(EditAnywhere)
    FSDITimestampInputButton VirtualControlMoveButton;
    
    UPROPERTY(EditAnywhere)
    FSDITimestampInputButton VirtualControlMoveReverseButton;
    
    UPROPERTY(EditAnywhere)
    float HybridMaxPitchAngleDeg;
    
    UPROPERTY(EditAnywhere)
    float HybridMaxUprightAngleDeg;
    
    UPROPERTY(EditAnywhere)
    float HybridMaxForwardAngleDeg;
    
    UPROPERTY(EditAnywhere)
    bool bHybridEngageHMDDelta;
    
    UPROPERTY(EditAnywhere)
    float HybridEngageHMDDeltaZ;
    
    UPROPERTY(EditAnywhere)
    float HybridDisengageHMDRange;
    
    UPROPERTY(EditAnywhere)
    bool bHybridEngageWhenHoldingItem;
    
    UPROPERTY(EditAnywhere)
    TMap<TSubclassOf<ASDIHeldActor>, bool> bHybridEngageClassMap;
    
    UPROPERTY(EditDefaultsOnly)
    float BeltInventoryRootOffset;
    
    UPROPERTY(EditDefaultsOnly)
    float ChestInventoryRootOffset;
    
    UPROPERTY(EditDefaultsOnly)
    float HeadInventoryRootOffset;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<FString, FVector> InventoryRootsOffsetForHMD;
    
    UPROPERTY(Transient)
    FVector InventoryRootsOffsetForHMDActive;
    
    UPROPERTY(EditDefaultsOnly)
    FVector ShoulderSlotOffset;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAttachBackInventorySlotsToShoulders;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USceneComponent* BeltInventoryRoot;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USceneComponent* ChestInventoryRoot;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USceneComponent* HeadInventoryRoot;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USDIPointGripComponent* BeltInventoryGripComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USDIPointGripComponent* ChestInventoryGripComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USDIPointGripComponent* HeadInventoryGripComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* BackInventoryComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* BackpackInventoryComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* LeftHipInventoryComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* RightHipInventoryComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* NotebookInventoryComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* FlashlightInventoryComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* FlashlightHeadInventoryComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UChildActorComponent* AmmoPouchComponent;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ATWDPlayerLootDrop> PlayerLootDropClass;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* LeftHipInventorySlot;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* RightHipInventorySlot;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* BackInventorySlot;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* BackpackInventorySlot;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* NotebookInventorySlot;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* FlashlightInventorySlot;
    
    UPROPERTY()
    ATWDPlayerInventorySlot* FlashlightHeadInventorySlot;
    
    UPROPERTY()
    ATWDAmmoPouch* AmmoPouch;
    
    UPROPERTY()
    ATWDBackpack* Backpack;
    
    UPROPERTY()
    ATWDNotebook* Notebook;
    
    UPROPERTY()
    ATWDFlashlight* Flashlight;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIHeldActor> DeathLeftHandHeldActor;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIHeldActor> DeathRightHandHeldActor;
    
    UPROPERTY(EditDefaultsOnly)
    UMaterialParameterCollection* PPMatCollection;
    
    UPROPERTY(EditDefaultsOnly)
    UAkAudioEvent* AkePlayTinnitus;
    
    UPROPERTY(EditDefaultsOnly)
    UAkAudioEvent* AkeStopTinnitus;
    
    UPROPERTY(EditDefaultsOnly)
    FName NonVRCameraSocket;
    
    UPROPERTY(EditDefaultsOnly)
    bool bNonVRCameraClampToCapsule;
    
    UPROPERTY(EditDefaultsOnly)
    float NonVRCameraClampOffset;
    
    UPROPERTY(EditDefaultsOnly)
    bool bNonVRCameraCollideWithWorld;
    
    UPROPERTY(EditDefaultsOnly)
    TEnumAsByte<ECollisionChannel> NonVRCameraCollisionChannel;
    
    UPROPERTY(EditDefaultsOnly)
    FCollisionResponseContainer NonVRCameraCollisionResponse;
    
    UPROPERTY(EditDefaultsOnly)
    float NonVRCameraCollisionRadius;
    
    UPROPERTY(EditDefaultsOnly)
    float NonVRMaxYawOffsetDeg;
    
    UPROPERTY(EditDefaultsOnly)
    FFloatRK4SpringInterpolator NonVRYawOffsetSpring;
    
    UPROPERTY(EditDefaultsOnly)
    float HipFireDelay;
    
    UPROPERTY(EditDefaultsOnly)
    float HipFireHoldTime;
    
    UPROPERTY(EditDefaultsOnly)
    float ADSMovementSpeedFactor;
    
    UPROPERTY(EditDefaultsOnly)
    float NonVRDryFireAutoHelperDelay;
    
    UPROPERTY(EditDefaultsOnly)
    float AngleOfStrikeMovementSpeedFactor;
    
    UPROPERTY(EditDefaultsOnly)
    float PrecisionStabMovementSpeedFactor;
    
    UPROPERTY(EditDefaultsOnly)
    FFloatRK4SpringInterpolator AngleOfStrikeSpring;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAngleOfStrikeForceReEngage;
    
    UPROPERTY(EditDefaultsOnly)
    float AngleOfStrikeChargeEngageLevel;
    
    UPROPERTY(EditDefaultsOnly)
    float AngleOfStrikeChargeDisengageLevel;
    
    UPROPERTY(EditDefaultsOnly)
    FFloatRK4SpringInterpolator BasicMeleeAngleSpring;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIDotLerpFloat BasicMeleeAngles;
    
    UPROPERTY(EditDefaultsOnly)
    bool bBasicMeleeAnglesUseBothMoveAndLookInput;
    
    UPROPERTY(EditDefaultsOnly)
    bool bBasicMeleeAnglesUseLookInput;
    
    UPROPERTY(EditDefaultsOnly)
    bool bInvertBasicMeleeAngles;
    
    UPROPERTY(EditDefaultsOnly)
    float MeleeFaceTargetPitchAngleMax;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickSplayDuration;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickSplaySpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickSplayRecoverySpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickSplayDelay;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickEjectDuration;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickWeakpointEjectDuration;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickRemovalSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickWeakpointRemovalSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickRemovalRecoverySpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float WeaponStickRemovalDelay;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloat WeaponStickMaxInputAngle;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloat WeaponStickForceYawVelocityRange;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloat WeaponStickForcePitchVelocityRange;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloat WeaponStickForceDistanceRange;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloatExp WeaponStickYawForce;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloatExp WeaponStickPitchForce;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloatExp WeaponStickDistanceForce;
    
    UPROPERTY(EditDefaultsOnly)
    UAkAudioEvent* AkePlayStabWeakpoint;
    
    UPROPERTY(EditDefaultsOnly)
    FQFloatExp NonVRGrappleMinigameDelay;
    
    UPROPERTY(EditDefaultsOnly)
    FQFloatExp NonVRGrappleMinigameTime;
    
    UPROPERTY(EditDefaultsOnly)
    float NonVRGrappleMinigamePressWindow;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<FName, float> NonVRGrappleMinigameSuccessKillImpulses;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop NonVRAttackChargeSoundLoop;
    
    UPROPERTY(EditDefaultsOnly)
    FString NonVRAttackChargeSoundLoopRTPC;
    
    UPROPERTY(EditDefaultsOnly)
    UAkAudioEvent* AkeSpecialMeleeEngageFailure;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowVariableDodgeDamageReduction;
    
    UPROPERTY(EditDefaultsOnly)
    float DodgeDamageReductionMultiplier;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPlayerVoiceAkComponent* PlayerVoiceLocalComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TinnitusDecayRate;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TinnitusLevel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsPlayingTinnitus;
    
    UPROPERTY(Transient)
    float LastSetGutsAmount;
    
    UPROPERTY(Transient)
    bool bHybridMovementEngaged;
    
    UPROPERTY(Transient)
    uint32 CachedNonVRCameraFrame;
    
    UPROPERTY(Transient)
    FVector CachedNonVRCameraLocation;
    
    UPROPERTY(Transient)
    FVector CachedNonVRPawnViewLocation;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIInteractiveActor> CachedInteractionActor;
    
    UPROPERTY(Transient)
    FSDIPlayerHandInteractComponentEntry CachedInteractionHighlight;
    
    UPROPERTY(Transient)
    bool bCachedInteractionActorLongHeld;
    
    UPROPERTY(Transient)
    TMap<ETWDNonVREquipmentSlot, TWeakObjectPtr<ASDIInventoryActor>> NonVREquipment;
    
    UPROPERTY(Transient)
    ETWDNonVREquipmentSlot DesiredNonVRSlotEquipped;
    
    UPROPERTY(Transient)
    ETWDNonVREquipmentSlot CurrentNonVRSlotEquipped;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIInventoryActor> NonVRPendingPickup;
    
    UPROPERTY(Transient)
    ETWDNonVREquipmentSlot NonVRPendingPickupSlot;
    
    UPROPERTY(Transient)
    bool bNonVRPendingPickupEquip;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIWeaponFirearm> HipFireGun;
    
    UPROPERTY(Transient)
    float HipFireRequestedTimestamp;
    
    UPROPERTY(Transient)
    bool bHipFiring;
    
    UPROPERTY(Transient)
    bool bNeedsRetune;
    
    UPROPERTY(Transient)
    ETWDNonVRMeleeAttackType SpecialMeleeActive;
    
    UPROPERTY(Transient)
    ETWDNonVRMeleeAttackType LastSpecialMeleeTargetMode;
    
    UPROPERTY(Transient)
    bool bAngleOfStrikeWasSet;
    
    UPROPERTY(Transient)
    float AngleOfStrike;
    
    UPROPERTY(Transient)
    float AngleOfStrikeCharge;
    
    UPROPERTY(Transient)
    bool bAngleOfStrikeIsCharged;
    
    UPROPERTY(Transient)
    bool bBasicMeleeAngleWasSet;
    
    UPROPERTY(Transient)
    float BasicMeleeAngle;
    
    UPROPERTY(Transient)
    float WeaponStickAngle;
    
    UPROPERTY(Transient)
    float WeaponStickInputAngle;
    
    UPROPERTY(Transient)
    float WeaponStickRemoval;
    
    UPROPERTY(Transient)
    float WeaponStickRemovalDelayTimer;
    
    UPROPERTY(Transient)
    float WeaponStickEjectTimer;
    
    UPROPERTY(Transient)
    ASDIInteractiveActor* ConsumingItem;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDWeaponActor> ChargingWeapon;
    
    UPROPERTY(Transient)
    float WeaponCharge;
    
    UPROPERTY(Transient)
    bool bWeaponIsCharged;
    
    UPROPERTY(Transient)
    float WeaponChargeHoldStartTime;
    
    UPROPERTY(Transient)
    ETWDNonVRGrappleMinigameState NonVRGrappleMinigameState;
    
    UPROPERTY(Transient)
    float NonVRGrappleMinigameTimer;
    
    UPROPERTY(Transient)
    ETWDNonVRGrappleAnimState NonVRGrappleAnimState;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDCharacter> NonVRGrappleAttacker;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<UTWDAnimNotifyState_EquipmentAction>, FSDIAnimNotifyStateData> EquipmentActionNotifies;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<UTWDAnimNotifyState_Grapple>, FSDIAnimNotifyStateData> GrappleNotifies;
    
public:
    UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly)
    ATWDAIPerceptionModifierVolume* ActivePerceptionModifierVolume;
    
    UPROPERTY(BlueprintReadOnly)
    float PerceptionModifierSecondsRemaining;
    
    UPROPERTY(BlueprintReadOnly)
    float LastUnobscuredTimeSeconds;
    
    UPROPERTY(BlueprintReadOnly)
    float LastObscuredTimeSeconds;
    
    UPROPERTY(BlueprintReadWrite)
    float RecentlyUnobscuredTimeIntervalSeconds;
    
    UPROPERTY(BlueprintReadWrite)
    float UnobscuredLongTimeIntervalSeconds;
    
    UPROPERTY(BlueprintReadOnly)
    bool bIsObscured;
    
    UPROPERTY(BlueprintReadOnly)
    bool bIsInDarkness;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    FString FemaleVoiceId;
    
    UPROPERTY(EditDefaultsOnly)
    FString GenderSwitchGroup;
    
    UPROPERTY(Transient)
    bool bIsOnTopOfBox;
    
    UPROPERTY(Transient)
    FVector BoxMin;
    
    UPROPERTY(Transient)
    FVector BoxMax;
    
    UPROPERTY(Transient)
    FTransform BoxXForm;
    
    UPROPERTY(Transient)
    float ClosestSignificantWalkerDistance;
    
    UPROPERTY(Transient)
    float LastPhysicalCrouchZDelta;
    
private:
    UPROPERTY(Instanced, Transient, VisibleAnywhere)
    UWidgetComponent* SpectatorWidgetComponent;
    
protected:
    UPROPERTY(Transient)
    FSDITuningAccumulator TuningAccumulator;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepTuningModifiers)
    TArray<FSDIReplicatedTuningModifier> RepTuningModifiers;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<AActor>, float> TuningOverlaps;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<AActor>> ActiveTuningOverlaps;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAllowTuningOverlaps;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputADSButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputPrimaryActionButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputSecondaryActionButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputReloadButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputInventoryBackpackButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputEquipLargeButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputEquipSmallButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputEquipConsumable1Button;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputEquipConsumable2Button;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputInventoryNotebookButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputInventoryFlashlightButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputInventoryFlashlightModeButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputInteractButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputGrabWorldButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputSprintButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MeleeButtonChargeTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIBlendOption MeleeButtonChargeBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDodgeOnSprintButton;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDITimestampInputButton InputVRWithoutHMDActionButton;
    
public:
    UPROPERTY(Transient)
    TArray<ASDIInventoryActor*> CurrentHeldActors;
    
    UPROPERTY(VisibleAnywhere)
    uint32 PlayerDeathCount;
    
    ATWDPlayerCharacter(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintPure)
    bool WasRecentlyUnobscured() const;
    
    UFUNCTION(BlueprintPure)
    bool UseNonVRMeleeButtonCharge() const;
    
    UFUNCTION(BlueprintCallable)
    void UpdateVoiceAndAppearance();
    
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateQuickInventory(ETWDNonVREquipmentSlot EquipType);
    
    UFUNCTION(BlueprintPure)
    bool UnobscuredForLongTime() const;
    
    UFUNCTION(BlueprintCallable)
    ATWDPlayerCharacter* TuneTWDPlayerCharacter(FSDITuningAttribute_TWDPlayerCharacter Attr, float PreModifier, float Add, float PostModifier);
    
    UFUNCTION(BlueprintCallable)
    ATWDPlayerCharacter* TuneTWDCharacterMovementComponent(FSDITuningAttribute_TWDCharacterMovementComponent Attr, float PreModifier, float Add, float PostModifier);
    
    UFUNCTION(BlueprintCallable)
    void StopSpecialMelee();
    
    UFUNCTION(BlueprintNativeEvent)
    void StabStarted(ATWDWeaponActor* Weapon);
    
    UFUNCTION(BlueprintNativeEvent)
    void StabEnding(ATWDWeaponActor* Weapon, bool bRemoveWeapon);
    
    UFUNCTION(BlueprintCallable)
    void SetOnTopOfBox(bool bTopOfBox, FVector Min, FVector Max, FTransform XForm);
    
    UFUNCTION(BlueprintCallable)
    ASDIInventoryActor* SetNonVREquipment(ETWDNonVREquipmentSlot Slot, ASDIInventoryActor* NewItem);
    
    UFUNCTION(BlueprintCallable)
    void SetGenderAndAppearanceVariant(EGender NewGender, int32 NewAppearanceVariant);
    
    UFUNCTION(BlueprintCallable)
    void SetGender(EGender NewGender);
    
    UFUNCTION(BlueprintCallable)
    void SetAppearanceVariant(int32 NewAppearance);
    
    UFUNCTION(BlueprintCallable)
    void SaveHeldInventory(bool bDestroySavedItems);
    
    UFUNCTION(BlueprintCallable)
    void SaveDataToGameProgression(UTWDSaveGame* SaveGame);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RestartPlayer(const FTransform& LootDropTransform, const FTransform& PlayerStartTransform);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveNonVREquipment(ASDIInventoryActor* NewItem);
    
    UFUNCTION(BlueprintCallable)
    void RefreshActivePerceptionModifier();
    
    UFUNCTION(BlueprintCallable)
    void PutAwayHeldInventory(bool bLimitToKeyItems);
    
    UFUNCTION()
    void OnTuningEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnTuningBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
protected:
    UFUNCTION()
    void OnRep_RepTuningModifiers();
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnDodge(UCurveBase* DodgeCurve, const FVector& Direction, float Distance, float Duration, float StaminaCost);
    
    UFUNCTION(BlueprintCallable)
    void NonVRUnEquip(bool bImmediate);
    
    UFUNCTION(BlueprintCallable)
    void NonVREquip(ETWDNonVREquipmentSlot Slot, bool bImmediate);
    
    UFUNCTION()
    void NonVRConsumeEnd(ASDIInteractiveActor* ConsumableActor);
    
    UFUNCTION()
    void NonVRConsumeBegin(ASDIInteractiveActor* ConsumableActor, bool bEquip);
    
    UFUNCTION(BlueprintCallable)
    void LoadDataFromGameProgression();
    
    UFUNCTION(BlueprintPure)
    bool IsWeaponStuckOrStabbed(ATWDWeaponActor*& OutWeapon, FHitResult& OutHitInfo, float& OutProgress, float& OutAngle, float& OutRemoval, float& OutInputAngle, float& OutDelay, bool& bOutCharged, bool& bOutWeakpoint, bool& bOutWeakpointIsDiseased, bool& bOutPlayerExtraction) const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool IsSpecialMeleeAllowed(ETWDNonVRMeleeAttackType Type) const;
    
    UFUNCTION(BlueprintPure)
    bool IsSpecialMeleeActiveDetailed(FTWDNonVRMeleeAttackDetails& OutDetails) const;
    
    UFUNCTION(BlueprintPure)
    bool IsSpecialMeleeActive(ETWDNonVRMeleeAttackType& OutType) const;
    
    UFUNCTION(BlueprintPure)
    bool IsSpecialInventory(AActor* Actor) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPreparingMeleeAttackDetailed(FTWDNonVRMeleeAttackDetails& OutDetails, bool bFindTarget) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPreparingMeleeAttack() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPreciseThrowControlEngaged(EControllerHand hand) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingMeleeAttackAnimDetailed(FTWDNonVRMeleeAttackDetails& OutDetails) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingGunActionAnimWithInfo(ETWDGunAction Action, ATWDWeaponGun*& OutGun) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingGrappleAnim() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingEquipmentActionAnimDetailed(FTWDNonVREquipmentActionDetails& OutDetails) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingEquipmentActionAnim() const;
    
    UFUNCTION(BlueprintPure)
    bool IsOnTopOfBox(FVector& Min, FVector& Max, FTransform& XForm) const;
    
    UFUNCTION(BlueprintPure)
    bool IsObscured() const;
    
    UFUNCTION()
    bool IsNonVRConsuming() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHoldingSpecialInventory(EControllerHand hand) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHoldingNotebook() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHoldingInventory(EControllerHand hand) const;
    
    UFUNCTION(BlueprintPure)
    bool IsHoldingFlashlight() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHoldingBackpack() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHipFiring(ATWDWeaponGun*& OutGun) const;
    
    UFUNCTION()
    void InputVRWithoutHMDActionReleased();
    
    UFUNCTION()
    void InputVRWithoutHMDActionPressed();
    
    UFUNCTION()
    void InputVirtualMoveControl(float Value);
    
    UFUNCTION()
    void InputSecondaryActionReleased();
    
    UFUNCTION()
    void InputSecondaryActionPressed();
    
    UFUNCTION()
    void InputReverseVirtualMoveControl(float Value);
    
    UFUNCTION()
    void InputReloadReleased();
    
    UFUNCTION()
    void InputReloadPressed();
    
    UFUNCTION()
    void InputPrimaryActionReleased();
    
    UFUNCTION()
    void InputPrimaryActionPressed();
    
    UFUNCTION()
    void InputInventoryNotebookReleased();
    
    UFUNCTION()
    void InputInventoryNotebookPressed();
    
    UFUNCTION()
    void InputInventoryFlashlightReleased();
    
    UFUNCTION()
    void InputInventoryFlashlightPressed();
    
    UFUNCTION()
    void InputInventoryFlashlightModeReleased();
    
    UFUNCTION()
    void InputInventoryFlashlightModePressed();
    
    UFUNCTION()
    void InputInventoryBackpackReleased();
    
    UFUNCTION()
    void InputInventoryBackpackPressed();
    
    UFUNCTION()
    void InputInteractReleased();
    
    UFUNCTION()
    void InputInteractPressed();
    
    UFUNCTION()
    void InputGrabWorldReleased();
    
    UFUNCTION()
    void InputGrabWorldPressed();
    
    UFUNCTION()
    void InputEquipSmallReleased();
    
    UFUNCTION()
    void InputEquipSmallPressed();
    
    UFUNCTION()
    void InputEquipLargeReleased();
    
    UFUNCTION()
    void InputEquipLargePressed();
    
    UFUNCTION()
    void InputEquipConsumable2Released();
    
    UFUNCTION()
    void InputEquipConsumable2Pressed();
    
    UFUNCTION()
    void InputEquipConsumable1Released();
    
    UFUNCTION()
    void InputEquipConsumable1Pressed();
    
    UFUNCTION()
    void InputDodgeReleased();
    
    UFUNCTION()
    void InputDodgePressed();
    
    UFUNCTION()
    void InputADSReleased();
    
    UFUNCTION()
    void InputADSPressed();
    
    UFUNCTION()
    bool HasPendingNonVRLongHeldInteraction() const;
    
    UFUNCTION(BlueprintPure)
    float GetPerceptionModifierStickinessPct() const;
    
    UFUNCTION(BlueprintPure)
    ASDIInventoryActor* GetNonVRPendingPickup(ETWDNonVREquipmentSlot& OutSlot) const;
    
    UFUNCTION(BlueprintPure)
    ETWDNonVRGrappleMinigameState GetNonVRGrappleMinigameState(float& OutTimeRemaining, float& OutDuration, float& OutNextDuration) const;
    
    UFUNCTION(BlueprintPure)
    ETWDNonVRGrappleAnimState GetNonVRGrappleAnimState() const;
    
    UFUNCTION(BlueprintPure)
    ETWDNonVREquipmentType GetNonVREquipmentType(ASDIInventoryActor* Item) const;
    
    UFUNCTION(BlueprintPure)
    ETWDNonVREquipmentSlot GetNonVREquipmentSlot(ASDIInventoryActor* Item) const;
    
    UFUNCTION(BlueprintPure)
    ASDIInventoryActor* GetNonVREquipment(ETWDNonVREquipmentSlot Slot) const;
    
    UFUNCTION(BlueprintPure)
    bool GetDodgeDamageReduction(float& OutDamageReduction) const;
    
    UFUNCTION(BlueprintPure)
    ETWDNonVREquipmentSlot GetDesiredNonVREquipmentSlot(ETWDNonVREquipmentType EquipmentType) const;
    
    UFUNCTION(BlueprintPure)
    ASDIInventoryActor* GetCurrentNonVREquipment(ETWDNonVREquipmentSlot& OutSlot) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetClosestWalkerDistance(float& Distance);
    
    UFUNCTION(BlueprintCallable)
    void ExitAllNonVRInteractionStates();
    
    UFUNCTION()
    void CompleteNonVRPendingPickup();
    
    UFUNCTION(BlueprintCallable)
    void CancelGunAction();
    
    UFUNCTION(BlueprintCallable)
    void CancelEquipmentAction();
    
    
    // Fix for true pure virtual functions not being implemented
};

