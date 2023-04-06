#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponFirearmAmmoTrace.h"
#include "Curves/CurveFloat.h"
#include "TWDWeaponDismemberChance.h"
#include "TWDWeaponPelletCharacterHit.h"
#include "SDITuningAttribute_TWDWeaponFirearmAmmoTrace.h"
#include "TWDWeaponFirearmAmmoTrace.generated.h"

class ATWDCharacter;
class UCurveFloat;
class UAkAudioEvent;
class ATWDWeaponFirearmAmmoTrace;

UCLASS()
class ATWDWeaponFirearmAmmoTrace : public ASDIWeaponFirearmAmmoTrace {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ImpactNoiseRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve DurabilityAdditionalSpreadDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve HeadshotPenetrationChanceDistanceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<TSoftClassPtr<ATWDCharacter>, FRuntimeFloatCurve> HeadshotPenetrationChanceDistanceCurveOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve PassThroughChanceDistanceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<TSoftClassPtr<ATWDCharacter>, FRuntimeFloatCurve> PassThroughChanceDistanceCurveOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 PassThroughMax;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* PassThroughCountToEnergyCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDWeaponDismemberChance DismemberChance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<TSoftClassPtr<ATWDCharacter>, FTWDWeaponDismemberChance> DismemberChanceOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* ImpactAkEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString ImpactAkEventSurfaceSwitchGroup;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanPenetrateHelmet;
    
    UPROPERTY(EditDefaultsOnly)
    float AimAssistMaxDistance;
    
    UPROPERTY(EditDefaultsOnly)
    float AimAssistRadius;
    
    UPROPERTY(EditDefaultsOnly)
    float AimAssistAngleDeg;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAimAssistUseSpreadTransform;
    
    UPROPERTY(EditAnywhere)
    int32 AimAssistAsyncTracePlatformLevel;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ATWDCharacter>, FTWDWeaponPelletCharacterHit> PelletCharacterHits;
    
public:
    ATWDWeaponFirearmAmmoTrace(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    ATWDWeaponFirearmAmmoTrace* TuneTWDWeaponFirearmAmmoTrace(FSDITuningAttribute_TWDWeaponFirearmAmmoTrace Attr, float PreModifier, float Add, float PostModifier);
    
    UFUNCTION(BlueprintPure)
    float GetImpactNoiseRadius() const;
    
};

