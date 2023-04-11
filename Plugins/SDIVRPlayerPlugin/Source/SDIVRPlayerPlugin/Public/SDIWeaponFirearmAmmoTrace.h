#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponFirearmAmmoTraceNearMissData.h"
#include "SDIWeaponFirearmAmmo.h"
#include "SDIWeaponFirearmAmmoTraceShotInfo.h"
#include "Curves/CurveFloat.h"
#include "SDIDamageData.h"
#include "Engine/EngineTypes.h"
#include "SDIWeaponFirearmAmmoTracePendingPelletHitFX.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDITuningAttribute_SDIWeaponFirearmAmmoTrace.h"
#include "SDIWeaponFirearmFiredShotInfo.h"
#include "SDIWeaponFirearmFiredPelletInfo.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDIWeaponFirearmAmmoTracePelletHit.h"
#include "SDIWeaponFirearmAmmoTrace.generated.h"

class ASDIWeaponFirearmAmmoTrace;
class AActor;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIWeaponFirearmAmmoTrace : public ASDIWeaponFirearmAmmo {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData Damage;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TraceRange;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TraceImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TraceImpactMass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HitReactImpulseMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NearMissAlertRange;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 AsyncTracePlatformLevel;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 PassThroughAsyncTracePlatformLevel;
    
    UPROPERTY(EditAnywhere)
    float TraceChannel;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve DirectDamageDistanceMultiplierCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve RadialDamageDistanceMultiplierCurve;
    
    UPROPERTY(Transient)
    TArray<FSDIWeaponFirearmAmmoTraceShotInfo> AsyncShotInfos;
    
    UPROPERTY(Transient)
    TArray<FSDIWeaponFirearmAmmoTracePendingPelletHitFX> PendingPelletHitFX;
    
    UPROPERTY(Transient)
    FTimerHandle HandlePelletHitFXTimerHandle;
    
public:
    ASDIWeaponFirearmAmmoTrace(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    ASDIWeaponFirearmAmmoTrace* TuneSDIWeaponFirearmAmmoTrace(FSDITuningAttribute_SDIWeaponFirearmAmmoTrace Attr, float PreModifier, float Add, float PostModifier);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void SpawnTracerFX(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FVector& EndLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool SpawnImpactFX(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FHitResult& Hit);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerHandleHitsAndNearMisses(const FSDIWeaponFirearmAmmoTraceShotInfo& TraceShotInfo);
    
    UFUNCTION(NetMulticast, Unreliable)
    void MulticastHandleHits(int32 ShotID, const FSDIWeaponFirearmFiredShotInfo& FiredShotInfo, const FTransform& ShotTransform, const TArray<FSDIWeaponFirearmAmmoTracePelletHit>& PelletHits);
    
    UFUNCTION()
    void HandlePelletHitFXTimer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleNearMisses(const TArray<FSDIWeaponFirearmAmmoTraceNearMissData>& NearMissData);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleHit(int32 ShotID, const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FHitResult& Hit, const int32& HitIndex, const TArray<AActor*>& InDamagedActors, TArray<AActor*>& OutDamagedActors);
    
public:
/*
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TEnumAsByte<ECollisionChannel> GetTraceChannel(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform);
*/
  
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetTraceImpactVelocity(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FHitResult& Hit, const int32& HitIndex, const TArray<AActor*>& DamagedActors);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetTraceIgnoreActors(const FSDIWeaponFirearmFiredShotInfo& FiredShotInfo, const FTransform& ShotTransform);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetDamageMultiplier(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FHitResult& Hit, const TArray<AActor*>& DamagedActors, float& OutDirectDamageMultiplier, float& OutRadialDamageMultiplier);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FSDIDamageData GetDamageData(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FHitResult& Hit, const int32& HitIndex, const TArray<AActor*>& DamagedActors);
    
public:
    UFUNCTION(BlueprintPure)
    FSDIDamageData GetDamage() const;
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    bool AllowTracePassThrough(int32 PassThroughCount, const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FVector& TraceStart, const FVector& TraceEnd, const FHitResult& LastHit, const TArray<FHitResult>& AllHits) const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool AllowHitPassThrough(int32 PassThroughCount, const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, const FHitResult& LastHit, int32 LastHitIndex, const TArray<FHitResult>& AllHits, const TArray<AActor*>& DamagedActors) const;
    
};

