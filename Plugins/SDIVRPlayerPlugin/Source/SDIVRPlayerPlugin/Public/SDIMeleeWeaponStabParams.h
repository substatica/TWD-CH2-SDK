#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDIMeleeWeaponStabSettings.h"
#include "UObject/NoExportTypes.h"
#include "SDIMeleeWeaponStabParams.generated.h"

class ASDIMeleeWeaponActor;
class USDIMeleeWeaponHitCapsuleComponent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIMeleeWeaponStabParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    ASDIMeleeWeaponActor* Weapon;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    USDIMeleeWeaponHitCapsuleComponent* Capsule;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FSDIMeleeWeaponStabSettings Settings;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult LocalStabHit;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult WorldStabHit;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector LocalActorStabImpactVel;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector WorldActorStabImpactVel;
    
    FSDIMeleeWeaponStabParams();
};

