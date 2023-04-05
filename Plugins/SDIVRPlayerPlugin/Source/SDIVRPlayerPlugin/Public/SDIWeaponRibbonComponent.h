#pragma once
#include "CoreMinimal.h"
#include "SDIHeldActorRibbonComponent.h"
#include "Engine/EngineTypes.h"
#include "RFloat.h"
#include "SDIWeaponRibbonComponent.generated.h"

class USDIMeleeWeaponHitCapsuleComponent;
class USDIWeaponHitCapsuleComponent;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIWeaponRibbonComponent : public USDIHeldActorRibbonComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<FComponentReference> MeleeWeaponHitCapsuleComponents;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FComponentReference> WeaponHitCapsuleComponents;
    
    UPROPERTY(EditDefaultsOnly)
    bool bRenderOnlyForDamage;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloat WeaponDamageDuration;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<USDIMeleeWeaponHitCapsuleComponent>> MeleeWeaponComponents;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<USDIWeaponHitCapsuleComponent>> WeaponComponents;
    
    UPROPERTY(Transient)
    bool bWeaponCouldCauseDamage;
    
    UPROPERTY(Transient)
    float WeaponDamageValue;
    
    UPROPERTY(Transient)
    float LastWeaponDamageTimestamp;
    
public:
    USDIWeaponRibbonComponent();
};

