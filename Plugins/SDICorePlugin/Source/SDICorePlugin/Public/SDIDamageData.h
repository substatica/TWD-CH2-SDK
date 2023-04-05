#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Curves/CurveFloat.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "SDICameraShakeSettings.h"
#include "RFloatExp.h"
#include "SDIForceFeedbackSettings.h"
#include "SDIDamageData.generated.h"

class UDamageType;
class USDICoreDOTComponent;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIDamageData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<UDamageType> DamageTypeClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloatExp Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRuntimeFloatCurve DirectDamageCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<USDICoreDOTComponent> DirectDamageDOTClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DirectDamageMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bApplyDirectDamageCameraShakeToAttacker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bApplyDirectDamageCameraShakeToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDICameraShakeSettings DirectDamageCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIForceFeedbackSettings DirectDamageForceFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> DirectDamageEffectiveness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bRadialDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bRadialIgnoreDamageCauser;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bRadialIgnoreDirectHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bRadialIgnoreInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<UDamageType> RadialDamageTypeClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRadialDamageParams RadialDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRuntimeFloatCurve RadialDamageCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<USDICoreDOTComponent> RadialDamageDOTClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RadialDamageMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bApplyRadialDamageCameraShakeToAttacker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bApplyRadialDamageCameraShakeToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDICameraShakeSettings RadialDamageCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIForceFeedbackSettings RadialDamageForceFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> RadialDamageEffectiveness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TEnumAsByte<ECollisionChannel> RadialDamageLOSTraceChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DebugRenderDuration;
    
    FSDIDamageData();
};

