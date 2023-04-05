#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDIReplicatedMap_FName_Float.h"
#include "UObject/NoExportTypes.h"
#include "SDICameraShakeSettings.h"
#include "SDIForceFeedbackSettings.h"
#include "SDIPointDamageEvent.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIPointDamageEvent : public FPointDamageEvent {
    GENERATED_BODY()
public:
    UPROPERTY()
    FVector ImpactVelocity;
    
    UPROPERTY()
    float ImpactMass;
    
    UPROPERTY()
    float HitReactImpulseMultiplier;
    
    UPROPERTY()
    float HitReactMinSpeed;
    
    UPROPERTY()
    bool bApplyCameraShake;
    
    UPROPERTY()
    FSDICameraShakeSettings CameraShake;
    
    UPROPERTY()
    FSDIForceFeedbackSettings ForceFeedback;
    
    UPROPERTY()
    FSDIReplicatedMap_FName_Float DamageEffectiveness;
    
    UPROPERTY()
    int32 DamageID;
    
    FSDIPointDamageEvent();
};

