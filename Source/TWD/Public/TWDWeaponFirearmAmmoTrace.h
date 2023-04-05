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
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ImpactNoiseRadius;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve DurabilityAdditionalSpreadDegrees;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve HeadshotPenetrationChanceDistanceCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<TSoftClassPtr<ATWDCharacter>, FRuntimeFloatCurve> HeadshotPenetrationChanceDistanceCurveOverrides;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve PassThroughChanceDistanceCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<TSoftClassPtr<ATWDCharacter>, FRuntimeFloatCurve> PassThroughChanceDistanceCurveOverrides;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 PassThroughMax;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* PassThroughCountToEnergyCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDWeaponDismemberChance DismemberChance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<TSoftClassPtr<ATWDCharacter>, FTWDWeaponDismemberChance> DismemberChanceOverrides;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* ImpactAkEvent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString ImpactAkEventSurfaceSwitchGroup;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
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

