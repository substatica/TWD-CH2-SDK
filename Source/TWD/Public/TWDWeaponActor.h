#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDICameraShakeSettings.h"
#include "SDIWeaponActor.h"
#include "TWDSeamlessTravelActorInterface.h"
#include "TWDWeaponStabSettings.h"
#include "TWDInventoryActorInterface.h"
#include "TWDTimeDilationActorInterface.h"
#include "ETWDNonVRMeleeAttackType.h"
#include "TWDReplicatedInventoryActorInterfaceData.h"
#include "TWDInventoryActorInterfaceData.h"
#include "TWDInteractiveHighlightInterface.h"
#include "TWDDurabilityInterface.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDInventoryActorBlueprintInterface.h"
#include "TWDDurabilityInterfaceData.h"
#include "TWDReplicatedDurabilityInterfaceData.h"
#include "Engine/EngineTypes.h"
#include "TWDTimeDilationActorData.h"
#include "Curves/CurveFloat.h"
#include "ETWDCharacterHitRegion.h"
#include "RFloatExp.h"
#include "SDIBlendOption.h"
#include "SDICurvedWedgeGeometry.h"
#include "UObject/NoExportTypes.h"
#include "ETWDWeaponStabState.h"
#include "ETWDWeaponDismemberState.h"
#include "UObject/NoExportTypes.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "TWDWeaponStickSettings.h"
#include "ETWDInventoryType.h"
#include "TWDNonVRMeleeAttackDetails.h"
#include "TWDWeaponDismemberSettings.h"
#include "ETWDNonVREquipmentType.h"
#include "ETWDLootType.h"
#include "TWDWeaponActor.generated.h"

class ATWDCharacter;
class UTWDAutoTickAkComponent;
class ASDIInventoryActor;
class UTWDWeaponShoveComponent;
class AActor;
class UHapticFeedbackEffect_Base;
class UPrimitiveComponent;
class UMaterialInstanceDynamic;
class USceneComponent;
class UAkAudioEvent;
class UParticleSystem;
class UPhysicalMaterial;
class UPhysicsConstraintComponent;
class UTWDWeaponHitCapsuleComponent;
class ATWDWeaponActorAttachmentEditor;
class UParticleSystemComponent;
class USDIActiveRagdollComponent;
class ATWDWeaponActor;
class USDIWeaponHitCapsuleComponent;
class ATWDBackpack;
class UDamageType;
class ATWDDismemberDroppedLimb;
class UObject;
class ASDIInventorySlot;

UCLASS()
class ATWDWeaponActor : public ASDIWeaponActor, public ITWDSeamlessTravelActorInterface, public ITWDInventoryActorInterface, public ITWDTimeDilationActorInterface, public ITWDInteractiveHighlightInterface, public ITWDDurabilityInterface, public ITWDInventoryActorBlueprintInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UTWDAutoTickAkComponent* AkAudioComponent;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UTWDWeaponShoveComponent* WeaponShoveComp;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FTWDInventoryActorInterfaceData TWDInventoryData;
    
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RepTWDInventoryData)
    FTWDReplicatedInventoryActorInterfaceData RepTWDInventoryData;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FTWDDurabilityInterfaceData TWDDurabilityData;
    
    UPROPERTY(ReplicatedUsing=OnRep_RepTWDDurabilityData)
    FTWDReplicatedDurabilityInterfaceData RepTWDDurabilityData;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AActor> BrokenReplacementClass;
    
    UPROPERTY(EditDefaultsOnly)
    UHapticFeedbackEffect_Base* BrokenPrimaryHapticEffect;
    
    UPROPERTY(EditDefaultsOnly)
    float BrokenPrimaryHapticScale;
    
    UPROPERTY(EditDefaultsOnly)
    UHapticFeedbackEffect_Base* BrokenSecondaryHapticEffect;
    
    UPROPERTY(EditDefaultsOnly)
    float BrokenSecondaryHapticScale;
    
    UPROPERTY(EditDefaultsOnly)
    bool bUseLowDurabilityMaterialEffect;
    
    UPROPERTY(EditDefaultsOnly)
    float LowDurabilityMaterialThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    FName LowDurabilityMaterialParam;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<UPrimitiveComponent*> LowDurabilityMaterialPrimitives;
    
    UPROPERTY(Transient)
    TArray<UMaterialInstanceDynamic*> LowDurabilityMaterialInstances;
    
    UPROPERTY(EditAnywhere, Replicated)
    FTWDTimeDilationActorData RepTimeDilationData;
    
    UPROPERTY(EditAnywhere, Replicated)
    FTWDTimeDilationActorData RepPlayerTimeDilationData;
    
    UPROPERTY(EditAnywhere)
    float DraggingRagdollMinimumMass;
    
    UPROPERTY(EditAnywhere)
    float DraggingRagdollAngularDamping;
    
    UPROPERTY(EditAnywhere)
    float DraggingRagdollLinearDamping;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bStabSyncMoveTarget;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bStabSyncMoveAttacker;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabSyncMoveCharacterDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabSyncMoveCharacterSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabSyncMoveCharacterMaxDuration;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabStartEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabCompleteEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabPullEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabSawLoopStartEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* StabSawLoopStopEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString StabSawLoopVelocityRTPC;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabStartFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabCompleteFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabPullFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabIncrementalSawInFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabIncrementalSawOutFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabPushLoopFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve StabPushLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* StabPullLoopFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve StabPullLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabDragLocationPIDScalar;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRStabStartCameraShake;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRStabPullCameraShake;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRFloatExp WeaponHitStaminaCost;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRFloatExp WeaponHitDurabilityCost;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDurabilityCanBreakOnWeaponHit;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString DurabilityRTPC;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StabStuckEjectTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bStabStuckEjectDeadOnly;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bThrowAimAssist;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ThrowAimAssistMinEngageThrowSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ThrowAimAssistPathCollisionRadius;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ThrowAimAssistPathCollisionTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRThrowAimAssistPathCollisionTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ThrowAimAssistTargetRadius;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve ThrowAimAssistTargetRadiusCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRThrowAimAssistTargetRadius;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve NonVRThrowAimAssistTargetRadiusCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ThrowAimAssistTargetZOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve ThrowAimAssistTargetZOffsetCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRThrowAimAssistTargetZOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve NonVRThrowAimAssistTargetZOffsetCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ThrowAimAssistMinDesiredThrowSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bCanStick;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TArray<UPhysicalMaterial*> StickPhysicalMaterials;
    
    UPROPERTY(EditAnywhere, Transient)
    UPhysicsConstraintComponent* CurrentStabPhysicsConstraint;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* DismemberFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* DismemberFleshFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* DismemberBoneFeedback;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<ETWDCharacterHitRegion, FSDICameraShakeSettings> NonVRDismemberCameraShake;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString AKCutLevel;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDismemberSyncMoveTarget;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDismemberSyncMoveAttacker;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberSyncMoveCharacterDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberPushSyncMoveCharacterDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberSyncMoveCharacterSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberSyncMoveCharacterMaxDuration;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDismemberFaceTarget;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberFaceTargetMinAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIBlendOption DismemberFaceTargetBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberFaceTargetTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDismemberFaceTargetMinAngleOnly;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDismemberRequiresLOS;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAllowAngleOfStrike;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAllowPrecisionStab;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAllowSplay;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TSet<ETWDCharacterHitRegion> SplayRegions;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TSet<ETWDCharacterHitRegion> PrecisionStabSplayRegions;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bSplayShove;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICurvedWedgeGeometry SplayShoveSearchGeo;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRHitCameraShake;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FVector NonVRDesiredTargetCameraRelOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<ETWDNonVRMeleeAttackType, FVector> NonVRDesiredTargetCameraRelOffsetMap;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<ETWDNonVRMeleeAttackType, FVector> NonVRCrouchDesiredTargetCameraRelOffsetMap;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRAttackStaminaCostChargedMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRAttackStaminaCostMiss;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRAttackStaminaCostHit;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRAttackStaminaCostHitWeakpoint;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRAttackStaminaCostHitDismember;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRAttackDurabilityCostHit;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICurvedWedgeGeometry NonVRShoveAttackSearchGeo;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRShoveAttackStaminaCost;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRShoveAttackDurabilityCost;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRShoveAttackCameraShake;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bPlayNonVRShoveAttackCameraShakeOnStart;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bPlayNonVRShoveAttackCameraShakeHitOnly;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRThreatAttackDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRThreatMaximumThreatAngle;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FName NonVRDismemberTrailSocket;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRDismemberTrailDuration;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UParticleSystem* NonVRDismemberTrailParticleSystemHuman;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UParticleSystem* NonVRDismemberTrailParticleSystemWalker;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float CachedPreStabWeaponMass;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* CurrentStabCapsule;
    
    UPROPERTY(BlueprintReadOnly, Replicated, Transient)
    ETWDWeaponStabState RepStabState;
    
    UPROPERTY(BlueprintReadOnly, Replicated, Transient)
    float RepStabDepth;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float InitialStabDepth;
    
    UPROPERTY(BlueprintReadOnly, Replicated, Transient)
    FHitResult RepStabHit;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bStabThrown;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bStabLaunched;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bStabCharged;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bStabWeakpoint;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bStabWeakpointIsDiseased;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ETWDNonVRMeleeAttackType StabAttack;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform StabTransform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform StabLerpStartTransform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector StabCapsuleOffset;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float StabLerpTimer;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float StabHoldTimer;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float RestabTimestamp;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float StabRangedGrabDelayTimestamp;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    int32 StabSawIncrement;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    int32 PrevStabSawIncrement;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float LastSawFXTimeStamp;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    TArray<int32> StabLoopFeedbackIds;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float SyncMoveCharacterTimer;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float StabLerpDuration;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float CurrentStabPullOutStrengthMax;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float CurrentStabPullOutStrength;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DefaultStabPushMovementMaxOffsetAngleDeg;
    
    UPROPERTY(Transient)
    int32 DragUpdateStabConstraintCounter;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ETWDWeaponDismemberState DismemberState;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ETWDCharacterHitRegion DismemberRegion;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* DismemberCapsule;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* LastDismemberCapsule;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector DismemberCapsuleOffset;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector DismemberPrincipalControlDirection;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector DismemberLateralControlDirection;
    
    UPROPERTY(Transient)
    FTransform DismemberInterpTransform;
    
    UPROPERTY(Transient)
    float DismemberInterpDuration;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector DismemberInitialControlHandDelta;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector InitialPointOnCapsule;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult LocalDismemberHitInfo;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult LastLocalDismemberHitInfo;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bDismemberThrown;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bDismemberLaunched;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform DismemberCapsuleTransform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector DismemberImpactVelocity;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float DismemberStateTimer;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float DismemberStateTimestamp;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector DismemberRelCapsulePoint;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector DismemberControlOrigin;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FPlane DismemberControlPlane;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float DismemberInterpDistance;
    
    UPROPERTY(EditDefaultsOnly)
    bool AllowAdvDismember;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StartDismemberDepth;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberPushStartDepth;
    
    UPROPERTY(Transient)
    float InitialDismemberDepth;
    
    UPROPERTY(Transient)
    float DismemberDepth;
    
    UPROPERTY(Transient)
    bool bIsDismemberPush;
    
    UPROPERTY(Transient)
    float MaxDismemberDist;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bContinuousDismember;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float DismemberResistanceForce;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxDismemberResistanceForce;
    
    UPROPERTY(Transient)
    int32 DismemberWoundID;
    
    UPROPERTY(Transient)
    bool bSlowDismemberWoundAndEffectsStarted;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* InitialDismemberEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop DismemberFleshLoop;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop DismemberBoneLoop;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* DismemberCompleteEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString SlowDismemberSurfaceSwitch;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString SlowDismemberSurface;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberDisengageThreashold;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberGrappleImmunityTime;
    
    UPROPERTY(EditDefaultsOnly)
    bool PermanentGrappleImmunity_PrimaryHand;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bUseOriginalSlowDismemberControls;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDismemberNewPointAlgorithm;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberingLocationPIDScalar;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DismemberingRotationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    UHapticFeedbackEffect_Base* DismemberBoneSnapHapticEvent;
    
    UPROPERTY(EditDefaultsOnly)
    UAkAudioEvent* DismemberBoneSnapAkEvent;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberBoneSnap_ResistanceWindow;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberBoneSnap_ResistanceDelta;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberResistanceHistoryMaxTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bUseStabCooldownsForDismember;
    
    UPROPERTY(EditAnywhere)
    TMap<ETWDCharacterHitRegion, FVector> DismemberCorrectionBounds;
    
    UPROPERTY(Transient)
    float DismemberResistanceHistoryRelTime;
    
    UPROPERTY(Transient)
    bool bDismemberBoneSnapped;
    
    UPROPERTY(Transient)
    float DismemberGrappleImmunityTimer;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ATWDWeaponActorAttachmentEditor* AttachmentEditor;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UParticleSystemComponent* SawFX;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UParticleSystemComponent* DismemberBoneFXComp;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UParticleSystem* DismemberBoneFX;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bPlayedStabSawLoopStartEvent;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USDIActiveRagdollComponent> ActiveRagdollComp;
    
    UPROPERTY(Transient)
    FTimerHandle StabStuckEjectTimerHandle;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* CurrentStickCapsule;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector StickCapsuleOffset;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult StickHitInfo;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bOnWeaponHitCausedDismember;
    
    UPROPERTY(Transient)
    bool bCurrentlyEndingStabWithDismember;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UParticleSystemComponent* NonVRDismemberTrailFX;
    
    UPROPERTY(Transient)
    FTimerHandle NonVRDismemberTrailFXTimerHandle;
    
    UPROPERTY(Transient)
    ETWDWeaponDismemberState NewStateToInit;
    
    UPROPERTY(Transient)
    bool bDeferredCreateDismemberWound;
    
    UPROPERTY(Transient)
    int32 PrimaryDismemberHapticEffectLoopId;
    
    UPROPERTY(Transient)
    int32 SecondaryDismemberHapticEffectLoopId;
    
public:
    ATWDWeaponActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void WeldChildToMainPhysicsComponent(UPrimitiveComponent* ToWeld);
    
public:
    UFUNCTION()
    void UpdateLowDurabilityMaterial();
    
    UFUNCTION(BlueprintCallable)
    static TArray<ATWDWeaponActor*> UnstickAllWeaponsFromComponent(const USceneComponent* Comp, bool bSimulatePhysics, bool bRecurse, bool bRecurseIntoAttachedActors);
    
    UFUNCTION(BlueprintCallable)
    static TArray<ATWDWeaponActor*> UnstickAllWeaponsFromActor(const AActor* Actor, bool bSimulatePhysics, bool bRecurseIntoAttachedActors);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SuspendDismember();
    
public:
    UFUNCTION(BlueprintCallable)
    void StopAkAudioComponent();
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    bool StartStick(UTWDWeaponHitCapsuleComponent* InStickCapsule, bool bUsePrevTransform, const FTWDWeaponStickSettings& StickSettings, const FHitResult& HitInfo, float ImpactSpeed, bool bIsHeldByPlayerHand, bool bThrown, bool bLaunched);
    
    UFUNCTION(BlueprintNativeEvent)
    bool StartStab(UTWDWeaponHitCapsuleComponent* InStabCapsule, const FHitResult& HitInfo, float InitialDepth, const FVector& CapsuleOffset, const FTransform& HitTransform, bool bIsHeldByPlayerHand, bool bThrown, bool bLaunched, bool bForceEmbedded);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void StartSlowDismemberWoundAndEffects(const FHitResult& WorldDismemberHitInfo);
    
protected:
    UFUNCTION()
    void StabStuckEject();
    
public:
    UFUNCTION(BlueprintCallable)
    bool StabEmbedWeapon(UTWDWeaponHitCapsuleComponent* InStabCapsule, AActor* Target, FName BoneName, float DepthPercent);
    
protected:
    UFUNCTION(BlueprintPure)
    bool ShouldAbortDismember() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void SetAkAudioComponentSwitch(const FString& SwitchGroup, const FString& SwitchState);
    
    UFUNCTION(BlueprintCallable)
    void SetAkAudioComponentRTPCValue(const FString& RTPC, float Value, int32 InterpolationTimeMs);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerUpdateStabState(ETWDWeaponStabState NewStabState);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerStartStab(const FHitResult& HitInfo, float InitialDepth);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetInventorySlotIdx_IFC(uint8 InventorySlotIdx);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerEndStab(bool bRemoveWeapon, float StabDepth);
    
    UFUNCTION(BlueprintCallable)
    void ResumeDismember();
    
public:
    UFUNCTION(BlueprintCallable)
    int32 PostEventToAkAudioComponent(UAkAudioEvent* Event, const FString& EventName);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnWeaponRemovedFromStab(AActor* RemovedFrom);
    
public:
    UFUNCTION()
    void OnWeaponHit(USDIWeaponHitCapsuleComponent* SelfComponent, USDIWeaponHitCapsuleComponent* WeaponHitComponent, AActor* HitActor, UPrimitiveComponent* HitComp, const FVector& HitVelocity, const FTransform& HitTransform, const FHitResult& HitInfo, const UDamageType* DamageType);
    
    UFUNCTION()
    void OnWeaponActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& HitInfo);
    
protected:
    UFUNCTION()
    void OnRep_RepTWDInventoryData_Timer();
    
    UFUNCTION()
    void OnRep_RepTWDInventoryData(const FTWDReplicatedInventoryActorInterfaceData& OldRepTWDInventoryData);
    
    UFUNCTION()
    void OnRep_RepTWDDurabilityData(const FTWDReplicatedDurabilityInterfaceData& OldRepTWDDurabilityData);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnNonVRAttackAction(const FTWDNonVRMeleeAttackDetails& Details);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnEndNonVRAttackDamageWindow(const FTWDNonVRMeleeAttackDetails& Details);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnEndNonVRAttack(const FTWDNonVRMeleeAttackDetails& Details);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnDurabilityBreak();
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnDismemberSuspended(ATWDCharacter* Victim);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnDismemberResumed(ATWDCharacter* Victim);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnDismemberedLimb(const FTWDWeaponDismemberSettings& Settings, const FHitResult& HitInfo, bool bThrown, const FTransform& CapsuleTransform, const FVector& DismemberAxis, const FVector& DismemberFlatAxis, bool bWeakpoint, bool bWasTargetDead, ATWDCharacter* Target, ETWDCharacterHitRegion Region, ATWDDismemberDroppedLimb* DroppedLimb, float Delay);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnDismemberComplete(ATWDCharacter* Victim);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnDismemberBegin(const FVector& ImpactPoint, const FVector& ImpactDir, ETWDCharacterHitRegion Region, ATWDCharacter* Victim);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnDismemberAborted(ATWDCharacter* Victim);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnBeginNonVRAttackDamageWindow(const FTWDNonVRMeleeAttackDetails& Details, float TotalDuration);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnBeginNonVRAttack(const FTWDNonVRMeleeAttackDetails& Details, float TotalDuration);
    
    UFUNCTION()
    void NonVRShoveAttackFilter(const AActor* Actor, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge, bool& bRetVal);
    
    UFUNCTION(BlueprintPure)
    bool K2IsStuck(FHitResult& OutStickHitInfo) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsThreat(ATWDCharacter* Character);
    
    UFUNCTION(BlueprintPure)
    bool IsStuckOrStabbed(FHitResult& OutHitInfo, bool& bOutCharged, bool& bOutWeakpoint, bool& bOutWeakpointIsDiseased, bool& bOutPlayerExtraction) const;
    
    UFUNCTION(BlueprintPure)
    bool IsStabbingAllowed() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsHighThreat(ATWDCharacter* Character);
    
    UFUNCTION()
    bool IsDismemberGrappleImmunityActive(bool bPrimaryHand) const;
    
    UFUNCTION(BlueprintPure)
    bool IsDismemberAllowed() const;
    
    UFUNCTION()
    bool GetUseStabCooldownsForDismember();
    
    UFUNCTION(BlueprintPure)
    bool GetStabWeakpointIsDiseased() const;
    
    UFUNCTION(BlueprintPure)
    bool GetStabWeakpoint() const;
    
    UFUNCTION(BlueprintPure)
    ETWDWeaponStabState GetStabState() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetStabNormal() const;
    
protected:
    UFUNCTION(BlueprintPure)
    float GetStabLoopFeedbackHapticEffectScale(float& OutCurveTime) const;
    
public:
    UFUNCTION(BlueprintPure)
    FVector GetStabImpactPoint() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetStabImpactNormal() const;
    
    UFUNCTION(BlueprintPure)
    float GetStabDepth() const;
    
    UFUNCTION(BlueprintPure)
    float GetStabCurveInput() const;
    
    UFUNCTION(BlueprintPure)
    UPrimitiveComponent* GetStabComponent() const;
    
    UFUNCTION(BlueprintPure)
    bool GetStabCharged() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetStabBoneTransform() const;
    
    UFUNCTION(BlueprintPure)
    FName GetStabBoneName() const;
    
    UFUNCTION(BlueprintPure)
    ETWDNonVRMeleeAttackType GetStabAttack() const;
    
    UFUNCTION()
    float GetLowDurabilityMaterialValue() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetExplosionOriginPoint() const;
    
    UFUNCTION(BlueprintPure)
    ETWDWeaponDismemberState GetDismemberState() const;
    
    UFUNCTION(BlueprintNativeEvent)
    float GetDeathBlowImpulse(TSubclassOf<UDamageType> DamageType);
    
    UFUNCTION(BlueprintNativeEvent)
    void EndStick();
    
    UFUNCTION(BlueprintNativeEvent)
    void EndStab(bool bRemoveWeapon);
    
protected:
    UFUNCTION(BlueprintCallable)
    void DeactivateNonVRDismemberTrailFX();
    
    UFUNCTION(BlueprintNativeEvent)
    void CompleteStab(const FTransform& CompTransform, const FTWDWeaponStabSettings& Settings);
    
    UFUNCTION(BlueprintImplementableEvent)
    bool CanResumeDismember();
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void AppliedDamage(UTWDWeaponHitCapsuleComponent* WeaponHitComponent, const FHitResult& HitInfo);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    bool AllowStickAfterStab() const;
    
public:
    UFUNCTION(BlueprintPure)
    bool AkAudioComponentHasActiveEvents() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void AbortDismember(const FString& DebugReason);
    
    
    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION(BlueprintCallable)
    bool ShouldApplyPrimaryGripPitchOffsetUserSetting() const override PURE_VIRTUAL(ShouldApplyPrimaryGripPitchOffsetUserSetting, return false;);
    
    UFUNCTION(BlueprintCallable)
    void SetSerializationString(const FString& NewString) override PURE_VIRTUAL(SetSerializationString,);
    
    UFUNCTION(BlueprintCallable)
    void SetNearbyHighlightShown(bool bShown) override PURE_VIRTUAL(SetNearbyHighlightShown,);
    
    UFUNCTION()
    void OnRep_RepTWDInventoryData_Internal() override PURE_VIRTUAL(OnRep_RepTWDInventoryData_Internal,);
    
    UFUNCTION(BlueprintCallable)
    FTWDInventoryActorInterfaceData K2GetTWDInventoryData() const override PURE_VIRTUAL(K2GetTWDInventoryData, return FTWDInventoryActorInterfaceData{};);
    
    UFUNCTION(BlueprintCallable)
    bool IsNearbyHighlightShown() const override PURE_VIRTUAL(IsNearbyHighlightShown, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsInsideBackpack(ATWDBackpack*& Backpack) const override PURE_VIRTUAL(IsInsideBackpack, return false;);
    
    UFUNCTION(BlueprintCallable)
    FTransform GetTWDSlotTransform(ASDIInventorySlot* InvSlot, const ASDIInventoryActor* InterfaceImpl) const override PURE_VIRTUAL(GetTWDSlotTransform, return FTransform{};);
    
    UFUNCTION(BlueprintCallable)
    float GetThrowRating() const override PURE_VIRTUAL(GetThrowRating, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    float GetSharpnessRating() const override PURE_VIRTUAL(GetSharpnessRating, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    FString GetSerializationString() const override PURE_VIRTUAL(GetSerializationString, return TEXT(""););
    
    UFUNCTION(BlueprintCallable)
    ETWDNonVREquipmentType GetNonVREquipmentType() const override PURE_VIRTUAL(GetNonVREquipmentType, return ETWDNonVREquipmentType::None;);
    
    UFUNCTION(BlueprintCallable)
    FText GetLootTypeText() const override PURE_VIRTUAL(GetLootTypeText, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    ETWDLootType GetLootType() const override PURE_VIRTUAL(GetLootType, return ETWDLootType::Default;);
    
    UFUNCTION(BlueprintCallable)
    FText GetInventoryTypeText() const override PURE_VIRTUAL(GetInventoryTypeText, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    ETWDInventoryType GetInventoryType() const override PURE_VIRTUAL(GetInventoryType, return ETWDInventoryType::Default;);
    
    UFUNCTION(BlueprintCallable)
    uint8 GetInventorySlotIdx() const override PURE_VIRTUAL(GetInventorySlotIdx, return 0;);
    
    UFUNCTION(BlueprintCallable)
    void GetInventoryDisplayInfo(FText& Name, int32& Count, FText& Type, FText& NewDescription, FText& NewFlavorText, float& SharpnessRating, float& DurabilityRating, float& ThrowRating, bool& bStabbingAllowed, bool& bDismemberAllowed) const override PURE_VIRTUAL(GetInventoryDisplayInfo,);
    
    UFUNCTION(BlueprintCallable)
    float GetDurabilityRating() const override PURE_VIRTUAL(GetDurabilityRating, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    bool DropOnArmGrapple() const override PURE_VIRTUAL(DropOnArmGrapple, return false;);
    
    UFUNCTION()
    void OnRep_RepTWDDurabilityData_Internal(const FTWDReplicatedDurabilityInterfaceData& OldRepTWDInventoryData) override PURE_VIRTUAL(OnRep_RepTWDDurabilityData_Internal,);
    
};

