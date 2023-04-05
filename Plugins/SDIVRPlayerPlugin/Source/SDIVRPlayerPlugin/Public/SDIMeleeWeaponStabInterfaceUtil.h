#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SDIMeleeWeaponStabInterfaceData.h"
#include "SDIMeleeWeaponStabParams.h"
#include "SDIMeleeWeaponStabInterfaceUtil.generated.h"

class UPrimitiveComponent;
class USDIActiveRagdollComponent;
class ASDIMeleeWeaponActor;
class UCurveFloat;
class USkeletalMeshComponent;

UCLASS(BlueprintType)
class SDIVRPLAYERPLUGIN_API USDIMeleeWeaponStabInterfaceUtil : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USDIMeleeWeaponStabInterfaceUtil();
    UFUNCTION(BlueprintCallable)
    static void SetPhysicalAnimationProfiles(UPARAM(Ref) FSDIMeleeWeaponStabInterfaceData& IfcData, USDIActiveRagdollComponent* ARComp);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveStuckWeapon(UPARAM(Ref) FSDIMeleeWeaponStabInterfaceData& IfcData, ASDIMeleeWeaponActor* Weapon);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveStabWeapon(UPARAM(Ref) FSDIMeleeWeaponStabInterfaceData& IfcData, ASDIMeleeWeaponActor* Weapon);
    
    UFUNCTION(BlueprintPure)
    static bool IsStabPossible(const FSDIMeleeWeaponStabInterfaceData& IfcData, const UPrimitiveComponent* StabComp, FName BoneName);
    
    UFUNCTION(BlueprintPure)
    static UCurveFloat* GetStabPullCurve(const FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintPure)
    static UCurveFloat* GetStabCurve(const FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintCallable)
    static void ClearPhysicalAnimationProfiles(UPARAM(Ref) FSDIMeleeWeaponStabInterfaceData& IfcData);
    
    UFUNCTION(BlueprintPure)
    static bool CheckBoneStabMap(const FSDIMeleeWeaponStabInterfaceData& IfcData, const USkeletalMeshComponent* Mesh, const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintCallable)
    static void AddStuckWeapon(UPARAM(Ref) FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams, float DropTime);
    
    UFUNCTION(BlueprintCallable)
    static void AddStabWeapon(UPARAM(Ref) FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams);
    
};

