#pragma once
#include "CoreMinimal.h"
#include "SDIAuxTickFunction.h"
#include "Components/CapsuleComponent.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIMeleeWeaponHitCapsuleComponentDamage.h"
#include "SDIMotionHistory.h"
#include "SDIMeleeWeaponStabSettings.h"
#include "SDICachedCollisionInfoShapeScaleOverride.h"
#include "UObject/NoExportTypes.h"
#include "SDIComponentReplacement.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIMeleeWeaponHitCapsuleComponent.generated.h"

class USDIWeaponHitHistoryComponent;
class USDIMeleeWeaponHitCapsuleComponent;
class USceneComponent;
class UObject;
class ASDIHeldActor;
class AActor;
class ASDIPlayerHand;
class UPrimitiveComponent;
class AController;
class APawn;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIMeleeWeaponHitCapsuleComponent : public UCapsuleComponent {
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
    TArray<FSDIMeleeWeaponHitCapsuleComponentDamage> Damages;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FSDIMeleeWeaponHitCapsuleComponentDamage> TwoHandedDamages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float VelocityAvgTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ImpactDamageVelocityAvgTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageIndexVelocityAvgTime;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUseOverlapHitDetection;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUseActorForDamageHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bDamageOnlyWhenHeld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bCanDamageInstigator;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAlwaysTickWhenActive;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bDetachFromHierarchy;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float HitReactImpulseMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float HitReactMinSpeed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FSDICachedCollisionInfoShapeScaleOverride> OverlapScaleOverrides;
    
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIMeleeWeaponStabSettings> StabSettings;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bUsedForDefense;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 CheckForBlockSubdivisions;
    
    UPROPERTY()
    FSDIAuxTickFunction OverlapTick;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<USDIWeaponHitHistoryComponent> HistoryComponent;
    
    UPROPERTY(Transient)
    FTransform PrevTransform;
    
    UPROPERTY(Transient)
    float LastTickTimeStamp;
    
    UPROPERTY(Transient)
    FTransform LastRelativeActorTransform;
    
    UPROPERTY(Transient)
    FSDIComponentReplacement ComponentAttachment;
    
public:
    USDIMeleeWeaponHitCapsuleComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateAttachmentInfo(USceneComponent* OldParent, USceneComponent* NewParent, const FName& NewParentSocketName);
    
protected:
    UFUNCTION()
    void TickOverlaps(UObject* ObjectOwner, float DeltaTime);
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetMotionHistory(bool bReserveAbs, bool bReserveRel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool PredictMotionCurves(FInterpCurveVector& OutBottom, FInterpCurveVector& OutTop, FVector& OutPlanePivot, FVector& OutPlaneExtensionLocation, FVector& OutPlaneNormal, FVector& OutPlaneTangent, float Time, float Resolution, float History) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool PredictMotion(TArray<FTransform>& OutTransforms, FVector& OutPlanePivot, FVector& OutPlaneNormal, float Time, float Resolution, float History) const;
    
    UFUNCTION()
    void OnWeaponActorGrabbed(ASDIHeldActor* HeldActor, AActor* GrabbedBy, EControllerHand hand, ASDIPlayerHand* HandPtr);
    
    UFUNCTION()
    void OnWeaponActorDropped(ASDIHeldActor* HeldActor, AActor* DroppedBy);
    
    UFUNCTION()
    void OnProjectileMovementStop(const FHitResult& ImpactResult);
    
    UFUNCTION()
    void OnPhysicsComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName);
    
    UFUNCTION()
    void OnPhysicsComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);
    
    UFUNCTION(BlueprintCallable)
    static bool MeleeWeaponCouldCauseDamageToHitResult(AActor* Weapon, USDIMeleeWeaponHitCapsuleComponent*& OutComp, const FHitResult& HitResult, bool bCheckVelocity, bool bCheckHistory, bool bCheckValidDamageValues);
    
    UFUNCTION(BlueprintCallable)
    static bool MeleeWeaponCouldCauseDamage(AActor* Weapon, USDIMeleeWeaponHitCapsuleComponent*& OutComp, AActor* Target, bool bCheckVelocity, bool bCheckHistory, bool bCheckValidDamageValues);
    
    UFUNCTION(BlueprintPure)
    bool IsTwoHanded() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetWeaponHitCapsuleTransform() const;
    
    UFUNCTION(BlueprintCallable)
    static USDIMeleeWeaponHitCapsuleComponent* GetWeaponHit(AActor* Actor, const FHitResult& HitInfo, bool bUseFindBestFallback, bool bOnlyCanDamage);
    
    UFUNCTION(BlueprintPure)
    bool GetInstigatorInfo(AController*& OutController, APawn*& OutPawn) const;
    
    UFUNCTION(BlueprintCallable)
    static USDIMeleeWeaponHitCapsuleComponent* FindBestExternalWeaponHit(AActor* Actor, const FHitResult& HitInfo, bool bOnlyCanDamage, bool bCheckVelocity, bool bCheckValidDamageValues);
    
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

