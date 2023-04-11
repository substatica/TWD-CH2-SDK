#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponActor.h"
#include "SDIMeleeWeaponStabCompletedSignatureDelegate.h"
#include "SDIMeleeWeaponStabStartedSignatureDelegate.h"
#include "SDIDamageData.h"
#include "Engine/EngineTypes.h"
#include "SDIMeleeWeaponStabParams.h"
#include "SDIMeleeWeaponStabEndedSignatureDelegate.h"
#include "SDIMeleeWeaponHitSignatureDelegate.h"
#include "ESDIMeleeWeaponStabState.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDIMeleeWeaponActor.generated.h"

class UPrimitiveComponent;
class UAkComponent;
class UCurveFloat;
class USDIActiveRagdollComponent;
class AActor;
class USDIMeleeWeaponHitCapsuleComponent;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIMeleeWeaponActor : public ASDIWeaponActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UAkComponent* AkAudioComponent;
    
    UPROPERTY(EditDefaultsOnly)
    bool bStabSyncMoveTarget;
    
    UPROPERTY(EditDefaultsOnly)
    bool bStabSyncMoveAttacker;
    
    UPROPERTY(EditDefaultsOnly)
    float StabSyncMoveCharacterDistance;
    
    UPROPERTY(EditDefaultsOnly)
    float StabSyncMoveCharacterSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float StabSyncMoveCharacterMaxDuration;
    
    UPROPERTY(EditInstanceOnly)
    bool bStartEmbedded;
    
    UPROPERTY(EditInstanceOnly)
    FComponentReference EmbeddedIn;
    
    UPROPERTY(EditInstanceOnly)
    bool bExtractWhenEmbedded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIsShield;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bShieldStrappedToArm;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponHitSignature OnWeaponHit;
    
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabStartedSignature StabStartedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabCompletedSignature StabCompletedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabEndedSignature StabEndedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    ESDIMeleeWeaponStabState StabState;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIMeleeWeaponStabParams StabParams;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float InitialStabDepth;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float StabDepth;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UCurveFloat* CachedStabCurve;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UCurveFloat* CachedStabPullCurve;
    
    UPROPERTY(Transient)
    FTransform StabInterpolationTransform;
    
    UPROPERTY(Transient)
    float StabInterpolationTime;
    
    UPROPERTY(Transient)
    float StabExtractionDelay;
    
    UPROPERTY(Transient)
    float StabExtractionTime;
    
    UPROPERTY(Transient)
    float StabCapsuleOffset;
    
    UPROPERTY(Transient)
    float StabSyncMoveCharacterTimer;
    
    UPROPERTY(Transient)
    bool bIsEmbedded;
    
    UPROPERTY(Transient)
    bool bEmbeddedExtract;
    
    UPROPERTY(Transient)
    bool bStabToggledAR;
    
    UPROPERTY(Transient)
    bool bStabContacted;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USDIActiveRagdollComponent> StabAR;
    
    UPROPERTY(Transient)
    int32 StabSawIncrement;
    
    UPROPERTY(Transient)
    TArray<int32> StabLoopFeedbackIds;
    
public:
    ASDIMeleeWeaponActor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    void StabActiveRagdollDeactivated(AActor* Actor, USDIActiveRagdollComponent* Comp);
    
    UFUNCTION()
    void StabActiveRagdollActivated(AActor* Actor, USDIActiveRagdollComponent* Comp);
    
    UFUNCTION()
    void OnWeaponActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnAppliedDamage(USDIMeleeWeaponHitCapsuleComponent* Capsule, const FSDIDamageData& DamageData, const TArray<AActor*>& DamagedActors, const FHitResult& HitInfo, const FVector& ImpactVelocity, int32 DamageID);
    
    UFUNCTION(BlueprintPure)
    bool IsStuckOrStabbed(FHitResult& OutHitInfo) const;
    
protected:
    UFUNCTION(BlueprintPure)
    float GetStabLoopFeedbackHapticEffectScale(float& OutCurveTime) const;
    
public:
    UFUNCTION(BlueprintCallable)
    bool EmbedWeaponAt(const FHitResult& HitInfo, const FTransform& WeaponTransform, bool bMustExtract);
    
    UFUNCTION(BlueprintCallable)
    bool EmbedWeapon(UPrimitiveComponent* DesiredPrimComp, bool bMustExtract);
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool CanMeleeHitCapsuleComponentApplyDamage(const USDIMeleeWeaponHitCapsuleComponent* HitComponent) const;
    
};

