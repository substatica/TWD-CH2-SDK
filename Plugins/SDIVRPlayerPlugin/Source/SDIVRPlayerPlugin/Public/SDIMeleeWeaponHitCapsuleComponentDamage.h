#pragma once
#include "CoreMinimal.h"
#include "SDICachedCollisionInfoShapeScaleOverride.h"
#include "ESDIAxis.h"
#include "SDIDamageData.h"
#include "SDIMeleeWeaponHitCapsuleComponentDamage.generated.h"

class UHapticFeedbackEffect_Base;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIMeleeWeaponHitCapsuleComponentDamage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ESDIAxis VelocityAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinContinuousVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinContinuousVelocityTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIDamageData DamageData;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FSDICachedCollisionInfoShapeScaleOverride> DamageOverlapScaleOverrides;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UHapticFeedbackEffect_Base* DamageFeedback;
    
    FSDIMeleeWeaponHitCapsuleComponentDamage();
};

