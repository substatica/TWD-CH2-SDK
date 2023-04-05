#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIMeleeWeaponHitCapsuleComponentDamage.h"
#include "SDIMeleeWeaponHitSignatureDelegate.generated.h"

class ASDIMeleeWeaponActor;
class USDIMeleeWeaponHitCapsuleComponent;
class AActor;
class UPrimitiveComponent;
class UDamageType;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_NineParams(FSDIMeleeWeaponHitSignature, ASDIMeleeWeaponActor*, Weapon, USDIMeleeWeaponHitCapsuleComponent*, WeaponHitComponent, AActor*, HitActor, UPrimitiveComponent*, HitComp, const FVector&, HitVelocity, const FTransform&, HitTransform, const FHitResult&, HitInfo, const UDamageType*, DamageType, const FSDIMeleeWeaponHitCapsuleComponentDamage&, Damage);

