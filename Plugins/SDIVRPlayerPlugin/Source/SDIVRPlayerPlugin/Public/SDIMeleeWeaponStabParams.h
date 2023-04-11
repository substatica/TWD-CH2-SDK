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
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIMeleeWeaponActor* Weapon;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    USDIMeleeWeaponHitCapsuleComponent* Capsule;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIMeleeWeaponStabSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult LocalStabHit;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult WorldStabHit;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector LocalActorStabImpactVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector WorldActorStabImpactVel;
    
    FSDIMeleeWeaponStabParams();
};

