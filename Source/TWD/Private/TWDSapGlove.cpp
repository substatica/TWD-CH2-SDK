#include "TWDSapGlove.h"
#include "Templates/SubclassOf.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SplineComponent.h"
#include "TWDWeaponHitCapsuleComponent.h"
#include "SDIPointGripComponent.h"
#include "Components/StaticMeshComponent.h"

class ATWDCharacter;
class UDamageType;
class AActor;

void ATWDSapGlove::OnCharacterDied(ATWDCharacter* Character, float PrevHealth, TSubclassOf<UDamageType> DamageTypeClass, AActor* DamageCauser) {
}

ATWDSapGlove::ATWDSapGlove(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->EquipGuideMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EquipGuideMesh"));
    this->EquippedMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EquippedSkeletalMesh"));
    this->PrimaryGripLeftComponent = CreateDefaultSubobject<USDIPointGripComponent>(TEXT("PrimaryGripLeft"));
    this->PrimaryGripRightComponent = CreateDefaultSubobject<USDIPointGripComponent>(TEXT("PrimaryGripRight"));
    this->EquippedGripComponent = CreateDefaultSubobject<USDIPointGripComponent>(TEXT("EquippedGrip"));
    this->WeaponHitCapsule = CreateDefaultSubobject<UTWDWeaponHitCapsuleComponent>(TEXT("WeaponHitCapsule"));
    this->AttachedHitCapsule = CreateDefaultSubobject<UTWDWeaponHitCapsuleComponent>(TEXT("AttachedHitCapsule"));
    this->GrippedHitCapsule = CreateDefaultSubobject<UTWDWeaponHitCapsuleComponent>(TEXT("GrippedHitCapsule"));
    this->EquipSplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("EquipSplineComponent"));
    this->TargetHand = EControllerHand::Left;
    this->EquipGuideMaterial = NULL;
    this->InvalidEquipMaterial = NULL;
    this->EquippingHand = NULL;
    this->EquippedHand = NULL;
    this->StartEquipRadius = 14.00f;
    this->EquipRadius = 16.00f;
    this->StartRemoveRadius = 30.00f;
    this->StartRemoveAngleMax = 60.00f;
    this->RemoveRadius = 40.00f;
    this->RemoveHandOffset = 3.00f;
    this->EquippedHapticEffect = NULL;
    this->EquippedEffectScale = 0.00f;
    this->RemovedHapticEffect = NULL;
    this->RemovedEffectScale = 0.00f;
    this->EquippingHapticEffect = NULL;
    this->EquippingEffectScale = 0.00f;
}

