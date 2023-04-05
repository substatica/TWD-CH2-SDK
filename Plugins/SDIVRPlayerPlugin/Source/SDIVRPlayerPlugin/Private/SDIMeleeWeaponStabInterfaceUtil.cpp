#include "SDIMeleeWeaponStabInterfaceUtil.h"

class UPrimitiveComponent;
class USDIActiveRagdollComponent;
class ASDIMeleeWeaponActor;
class UCurveFloat;
class USkeletalMeshComponent;

void USDIMeleeWeaponStabInterfaceUtil::SetPhysicalAnimationProfiles(FSDIMeleeWeaponStabInterfaceData& IfcData, USDIActiveRagdollComponent* ARComp) {
}

void USDIMeleeWeaponStabInterfaceUtil::RemoveStuckWeapon(FSDIMeleeWeaponStabInterfaceData& IfcData, ASDIMeleeWeaponActor* Weapon) {
}

void USDIMeleeWeaponStabInterfaceUtil::RemoveStabWeapon(FSDIMeleeWeaponStabInterfaceData& IfcData, ASDIMeleeWeaponActor* Weapon) {
}

bool USDIMeleeWeaponStabInterfaceUtil::IsStabPossible(const FSDIMeleeWeaponStabInterfaceData& IfcData, const UPrimitiveComponent* StabComp, FName BoneName) {
    return false;
}

UCurveFloat* USDIMeleeWeaponStabInterfaceUtil::GetStabPullCurve(const FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams) {
    return NULL;
}

UCurveFloat* USDIMeleeWeaponStabInterfaceUtil::GetStabCurve(const FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams) {
    return NULL;
}

void USDIMeleeWeaponStabInterfaceUtil::ClearPhysicalAnimationProfiles(FSDIMeleeWeaponStabInterfaceData& IfcData) {
}

bool USDIMeleeWeaponStabInterfaceUtil::CheckBoneStabMap(const FSDIMeleeWeaponStabInterfaceData& IfcData, const USkeletalMeshComponent* Mesh, const FSDIMeleeWeaponStabParams& StabParams) {
    return false;
}

void USDIMeleeWeaponStabInterfaceUtil::AddStuckWeapon(FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams, float DropTime) {
}

void USDIMeleeWeaponStabInterfaceUtil::AddStabWeapon(FSDIMeleeWeaponStabInterfaceData& IfcData, const FSDIMeleeWeaponStabParams& StabParams) {
}

USDIMeleeWeaponStabInterfaceUtil::USDIMeleeWeaponStabInterfaceUtil() {
}

