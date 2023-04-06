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
class UObject;
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
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDAutoTickAkComponent* AkAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDWeaponShoveComponent* WeaponShoveComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDInventoryActorInterfaceData TWDInventoryData;
    
    UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_RepTWDInventoryData)
    FTWDReplicatedInventoryActorInterfaceData RepTWDInventoryData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDDurabilityInterfaceData TWDDurabilityData;
    
    UPROPERTY(ReplicatedUsing=OnRep_RepTWDDurabilityData)
    FTWDReplicatedDurabilityInterfaceData RepTWDDurabilityData;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AActor> BrokenReplacementClass;
    
    UPROPERTY(EditDefaultsOnly)
    UObject* BrokenPrimaryHapticEffect;
    
    UPROPERTY(EditDefaultsOnly)
    float BrokenPrimaryHapticScale;
    
    UPROPERTY(EditDefaultsOnly)
    UObject* BrokenSecondaryHapticEffect;
    
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
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabSyncMoveTarget;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabSyncMoveAttacker;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabSyncMoveCharacterDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabSyncMoveCharacterSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabSyncMoveCharacterMaxDuration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabStartEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabCompleteEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabPullEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabSawLoopStartEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StabSawLoopStopEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString StabSawLoopVelocityRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabStartFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabCompleteFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabPullFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabIncrementalSawInFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabIncrementalSawOutFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabPushLoopFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StabPushLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* StabPullLoopFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StabPullLoopFeedbackScaleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabDragLocationPIDScalar;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRStabStartCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRStabPullCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp WeaponHitStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp WeaponHitDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnWeaponHit;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString DurabilityRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabStuckEjectTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabStuckEjectDeadOnly;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bThrowAimAssist;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrowAimAssistMinEngageThrowSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrowAimAssistPathCollisionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrowAimAssistPathCollisionTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRThrowAimAssistPathCollisionTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrowAimAssistTargetRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve ThrowAimAssistTargetRadiusCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRThrowAimAssistTargetRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve NonVRThrowAimAssistTargetRadiusCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrowAimAssistTargetZOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve ThrowAimAssistTargetZOffsetCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRThrowAimAssistTargetZOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve NonVRThrowAimAssistTargetZOffsetCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrowAimAssistMinDesiredThrowSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanStick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<UPhysicalMaterial*> StickPhysicalMaterials;
    
    UPROPERTY(EditAnywhere, Transient)
    UPhysicsConstraintComponent* CurrentStabPhysicsConstraint;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* DismemberFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* DismemberFleshFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* DismemberBoneFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<ETWDCharacterHitRegion, FSDICameraShakeSettings> NonVRDismemberCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString AKCutLevel;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDismemberSyncMoveTarget;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDismemberSyncMoveAttacker;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberSyncMoveCharacterDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberPushSyncMoveCharacterDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberSyncMoveCharacterSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberSyncMoveCharacterMaxDuration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDismemberFaceTarget;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberFaceTargetMinAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIBlendOption DismemberFaceTargetBlend;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberFaceTargetTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDismemberFaceTargetMinAngleOnly;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDismemberRequiresLOS;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowAngleOfStrike;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowPrecisionStab;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowSplay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSet<ETWDCharacterHitRegion> SplayRegions;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSet<ETWDCharacterHitRegion> PrecisionStabSplayRegions;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bSplayShove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICurvedWedgeGeometry SplayShoveSearchGeo;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRHitCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector NonVRDesiredTargetCameraRelOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<ETWDNonVRMeleeAttackType, FVector> NonVRDesiredTargetCameraRelOffsetMap;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<ETWDNonVRMeleeAttackType, FVector> NonVRCrouchDesiredTargetCameraRelOffsetMap;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRAttackStaminaCostChargedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRAttackStaminaCostMiss;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRAttackStaminaCostHit;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRAttackStaminaCostHitWeakpoint;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRAttackStaminaCostHitDismember;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRAttackDurabilityCostHit;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICurvedWedgeGeometry NonVRShoveAttackSearchGeo;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRShoveAttackStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRShoveAttackDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICameraShakeSettings NonVRShoveAttackCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bPlayNonVRShoveAttackCameraShakeOnStart;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bPlayNonVRShoveAttackCameraShakeHitOnly;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRThreatAttackDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRThreatMaximumThreatAngle;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName NonVRDismemberTrailSocket;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRDismemberTrailDuration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UParticleSystem* NonVRDismemberTrailParticleSystemHuman;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UParticleSystem* NonVRDismemberTrailParticleSystemWalker;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedPreStabWeaponMass;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* CurrentStabCapsule;
    
    UPROPERTY(BlueprintReadWrite, Replicated, Transient)
    ETWDWeaponStabState RepStabState;
    
    UPROPERTY(BlueprintReadWrite, Replicated, Transient)
    float RepStabDepth;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float InitialStabDepth;
    
    UPROPERTY(BlueprintReadWrite, Replicated, Transient)
    FHitResult RepStabHit;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bStabThrown;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bStabLaunched;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bStabCharged;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bStabWeakpoint;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bStabWeakpointIsDiseased;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDNonVRMeleeAttackType StabAttack;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform StabTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform StabLerpStartTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector StabCapsuleOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float StabLerpTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float StabHoldTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float RestabTimestamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float StabRangedGrabDelayTimestamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 StabSawIncrement;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 PrevStabSawIncrement;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LastSawFXTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<int32> StabLoopFeedbackIds;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float SyncMoveCharacterTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float StabLerpDuration;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CurrentStabPullOutStrengthMax;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CurrentStabPullOutStrength;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DefaultStabPushMovementMaxOffsetAngleDeg;
    
    UPROPERTY(Transient)
    int32 DragUpdateStabConstraintCounter;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDWeaponDismemberState DismemberState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDCharacterHitRegion DismemberRegion;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* DismemberCapsule;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* LastDismemberCapsule;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberCapsuleOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberPrincipalControlDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberLateralControlDirection;
    
    UPROPERTY(Transient)
    FTransform DismemberInterpTransform;
    
    UPROPERTY(Transient)
    float DismemberInterpDuration;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberInitialControlHandDelta;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector InitialPointOnCapsule;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult LocalDismemberHitInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult LastLocalDismemberHitInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDismemberThrown;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDismemberLaunched;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform DismemberCapsuleTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DismemberStateTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DismemberStateTimestamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberRelCapsulePoint;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector DismemberControlOrigin;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FPlane DismemberControlPlane;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DismemberInterpDistance;
    
    UPROPERTY(EditDefaultsOnly)
    bool AllowAdvDismember;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StartDismemberDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberPushStartDepth;
    
    UPROPERTY(Transient)
    float InitialDismemberDepth;
    
    UPROPERTY(Transient)
    float DismemberDepth;
    
    UPROPERTY(Transient)
    bool bIsDismemberPush;
    
    UPROPERTY(Transient)
    float MaxDismemberDist;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bContinuousDismember;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DismemberResistanceForce;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxDismemberResistanceForce;
    
    UPROPERTY(Transient)
    int32 DismemberWoundID;
    
    UPROPERTY(Transient)
    bool bSlowDismemberWoundAndEffectsStarted;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* InitialDismemberEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop DismemberFleshLoop;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop DismemberBoneLoop;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* DismemberCompleteEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString SlowDismemberSurfaceSwitch;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString SlowDismemberSurface;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberDisengageThreashold;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberGrappleImmunityTime;
    
    UPROPERTY(EditDefaultsOnly)
    bool PermanentGrappleImmunity_PrimaryHand;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUseOriginalSlowDismemberControls;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDismemberNewPointAlgorithm;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberingLocationPIDScalar;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DismemberingRotationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    UObject* DismemberBoneSnapHapticEvent;
    
    UPROPERTY(EditDefaultsOnly)
    UAkAudioEvent* DismemberBoneSnapAkEvent;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberBoneSnap_ResistanceWindow;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberBoneSnap_ResistanceDelta;
    
    UPROPERTY(EditDefaultsOnly)
    float DismemberResistanceHistoryMaxTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUseStabCooldownsForDismember;
    
    UPROPERTY(EditAnywhere)
    TMap<ETWDCharacterHitRegion, FVector> DismemberCorrectionBounds;
    
    UPROPERTY(Transient)
    float DismemberResistanceHistoryRelTime;
    
    UPROPERTY(Transient)
    bool bDismemberBoneSnapped;
    
    UPROPERTY(Transient)
    float DismemberGrappleImmunityTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ATWDWeaponActorAttachmentEditor* AttachmentEditor;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UParticleSystemComponent* SawFX;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UParticleSystemComponent* DismemberBoneFXComp;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UParticleSystem* DismemberBoneFX;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bPlayedStabSawLoopStartEvent;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USDIActiveRagdollComponent> ActiveRagdollComp;
    
    UPROPERTY(Transient)
    FTimerHandle StabStuckEjectTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UTWDWeaponHitCapsuleComponent* CurrentStickCapsule;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector StickCapsuleOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult StickHitInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bOnWeaponHitCausedDismember;
    
    UPROPERTY(Transient)
    bool bCurrentlyEndingStabWithDismember;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
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

