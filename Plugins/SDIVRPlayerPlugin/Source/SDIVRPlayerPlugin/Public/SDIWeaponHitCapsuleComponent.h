#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIMotionHistory.h"
#include "SDICachedCollisionInfoShapeScaleOverride.h"
#include "SDIComponentReplacement.h"
#include "SDIWeaponHitComponentDamage.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIWeaponHitComponentHitSignatureDelegate.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "SDIWeaponHitCapsuleComponent.generated.h"

class USDIWeaponHitHistoryComponent;
class UAkAudioEvent;
class UAkComponent;
class USceneComponent;
class UPrimitiveComponent;
class AActor;
class ASDIHeldActor;
class ASDIPlayerHand;
class USDIWeaponHitCapsuleComponent;
class AController;
class APawn;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIWeaponHitCapsuleComponent : public UCapsuleComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float DamageHistoryDuration;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float CollisionHistoryDuration;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIMotionHistory TopMotionHistory;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIMotionHistory BottomMotionHistory;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIMotionHistory RelativeTopMotionHistory;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIMotionHistory RelativeBottomMotionHistory;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FSDIWeaponHitComponentDamage> Damages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float VelocityAvgTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ImpactDamageVelocityAvgTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageIndexVelocityAvgTime;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUseActorHitCallback;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUseOverlapHitDetection;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUseOverlapHitDetectionNonVR;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUseActorForDamageHistory;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bDamageOnImpactOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bDamageOnlyWhenHeld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bCanDamageInstigator;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bBroadcastToAllOnWeaponHit;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAlwaysTickWhenActive;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bDetachFromHierarchy;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAllowActiveInVR;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAllowActiveInNonVR;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float HitReactImpulseMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float HitReactMinSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FSDICachedCollisionInfoShapeScaleOverride> OverlapScaleOverrides;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUseMaxHitCapsuleDistance;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float MaxHitCapsuleDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* MovementLoopEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* MovementLoopStopEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString MovementLoopRTPC;
    
public:
    UPROPERTY(EditAnywhere)
    bool bDebugShowTraceCollisionsOnScreen;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bRankAllAxisTypesEvenly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUsePlaneForOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bPlaneCanUseOverlapScaleOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TEnumAsByte<EAxis::Type> PlaneNormalAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PlaneHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector PlaneScale;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<USDIWeaponHitHistoryComponent> HistoryComponent;
    
    UPROPERTY(Transient)
    FTransform PrevTransform;
    
    UPROPERTY(Transient)
    float LastTickTimeStamp;
    
    UPROPERTY(Transient)
    bool bRegisteredOnActorHit;
    
    UPROPERTY(Instanced, Transient)
    UAkComponent* MovementLoopComponent;
    
    UPROPERTY(Transient)
    bool bPlayingMovementLoop;
    
    UPROPERTY(Transient)
    FTransform LastRelativeActorTransform;
    
    UPROPERTY(Transient)
    FSDIComponentReplacement ComponentAttachment;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIWeaponHitComponentHitSignature OnWeaponHit;
    
    USDIWeaponHitCapsuleComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateAttachmentInfo(USceneComponent* OldParent, USceneComponent* NewParent, const FName& NewParentSocketName);
    
    UFUNCTION(BlueprintCallable)
    void SetMovementLoopComponent(UAkComponent* Comp);
    
    UFUNCTION(BlueprintCallable)
    void ResetMotionHistory(bool bReserveAbs, bool bReserveRel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool PredictMotionCurves(FInterpCurveVector& OutBottom, FInterpCurveVector& OutTop, FVector& OutPlanePivot, FVector& OutPlaneExtensionLocation, FVector& OutPlaneNormal, FVector& OutPlaneTangent, float Time, float Resolution, float History) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool PredictMotion(TArray<FTransform>& OutTransforms, FVector& OutPlanePivot, FVector& OutPlaneNormal, float Time, float Resolution, float History) const;
    
    UFUNCTION()
    void OnProjectileMovementStop(const FHitResult& ImpactResult);
    
    UFUNCTION()
    void OnPhysicsComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName);
    
    UFUNCTION()
    void OnPhysicsComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);
    
    UFUNCTION()
    void OnOwnerActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void OnHeldActorGrabbed(ASDIHeldActor* HeldActor, AActor* GrabbedBy, EControllerHand hand, ASDIPlayerHand* HandPtr);
    
    UFUNCTION()
    void OnHeldActorDropped(ASDIHeldActor* HeldActor, AActor* DroppedBy);
    
    UFUNCTION(BlueprintCallable)
    static bool MeleeWeaponCouldCauseDamageToHitResult(AActor* Weapon, USDIWeaponHitCapsuleComponent*& OutComp, const FHitResult& HitResult, bool bCheckVelocity, bool bCheckHistory, bool bCheckValidDamageValues);
    
    UFUNCTION(BlueprintCallable)
    static bool MeleeWeaponCouldCauseDamage(AActor* Weapon, USDIWeaponHitCapsuleComponent*& OutComp, AActor* Target, bool bCheckVelocity, bool bCheckHistory, bool bCheckValidDamageValues);
    
    UFUNCTION(BlueprintPure)
    bool IsTwoHanded() const;
    
    UFUNCTION(BlueprintCallable)
    static bool HandleExternalHitFromActor(AActor* Actor, const FHitResult& HitInfo, bool bCheckHistory, bool bAddToHistory, bool bOnlyActorHitCallback);
    
    UFUNCTION(BlueprintCallable)
    bool HandleExternalHit(const FHitResult& HitInfo, bool bCheckHistory, bool bAddToHistory);
    
    UFUNCTION(BlueprintPure)
    FTransform GetWeaponHitCapsuleTransform() const;
    
    UFUNCTION(BlueprintCallable)
    static USDIWeaponHitCapsuleComponent* GetWeaponHit(AActor* Actor, const FHitResult& HitInfo, bool bUseFindBestFallback, bool bOnlyActorHitCallback, bool bOnlyCanDamage);
    
    UFUNCTION(BlueprintPure)
    UAkComponent* GetMovementLoopComponent() const;
    
    UFUNCTION(BlueprintPure)
    bool GetInstigatorInfo(AController*& OutController, APawn*& OutPawn) const;
    
    UFUNCTION(BlueprintCallable)
    static USDIWeaponHitCapsuleComponent* FindBestExternalWeaponHit(AActor* Actor, const FHitResult& HitInfo, bool bOnlyActorHitCallback, bool bOnlyCanDamage, bool bCheckVelocity, bool bCheckValidDamageValues);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DrawDebugMotionPrediction(float Time, float Resolution, float History, float LifeTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DrawDebugMotionHistory(float Timespan, FLinearColor Color, int32 Subdivisions, bool bRotation, bool bPersistent, float LifeTime, float Thickness) const;
    
    UFUNCTION(BlueprintPure)
    bool CouldCauseDamage(bool bCheckVelocity, bool bCheckValidDamageValues) const;
    
    UFUNCTION(BlueprintPure)
    float ComputeVelocityDamagePercent(bool bUseRelativeHistory) const;
    
    UFUNCTION(BlueprintPure)
    FVector ComputeImpactVelocity(const FHitResult& ImpactResult, float& OutScalarVel, bool bUseRelativeHistory) const;
    
    UFUNCTION(BlueprintPure)
    FVector ComputeAvgTopVelocity(float AvgTime, float& ScalarVel, bool bUseRelativeHistory) const;
    
    UFUNCTION(BlueprintPure)
    FVector ComputeAvgBottomVelocity(float AvgTime, float& ScalarVel, bool bUseRelativeHistory) const;
    
    UFUNCTION(BlueprintPure)
    bool CanApplyDamage() const;
    
};

