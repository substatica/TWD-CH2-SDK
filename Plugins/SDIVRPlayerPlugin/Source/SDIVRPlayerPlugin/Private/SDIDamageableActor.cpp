#include "SDIDamageableActor.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "SDICoreAttributeComponent.h"

class AController;
class USDISkinObject;
class AActor;
class APawn;
class UDamageType;

int32 ASDIDamageableActor::SetHealthPctNonZeroMinimum(float Pct, int32 NonZeroMinimumValue) {
    return 0;
}

int32 ASDIDamageableActor::SetHealth(int32 NewValue) {
    return 0;
}

void ASDIDamageableActor::ServerSetSkin_IFC_Implementation(TSubclassOf<USDISkinObject> SkinClass, bool bForceUpdate, bool bForceReInit) {
}
bool ASDIDamageableActor::ServerSetSkin_IFC_Validate(TSubclassOf<USDISkinObject> SkinClass, bool bForceUpdate, bool bForceReInit) {
    return true;
}

void ASDIDamageableActor::OnTotalHealthChanged_Implementation(USDICoreAttributeComponent* Attr, int32 OldTotal, int32 NewTotal) {
}

void ASDIDamageableActor::OnRepair_Implementation() {
}

void ASDIDamageableActor::OnRep_RepSkinData(const FSDISkinReplicationData& OldRepSkinData) {
}

void ASDIDamageableActor::OnRep_RepDamageTakenData(const FSDIReplicatedDamageData& OldRepDamageTakenData) {
}

void ASDIDamageableActor::OnNonDamageHit_Implementation(AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void ASDIDamageableActor::OnDestruction_Implementation(AController* InstigatorController, APawn* InstigatorPawn, AActor* DamageCauser, const FSDIReplicatedDamageData& DamageTakenData) {
}

void ASDIDamageableActor::MulticastOnRepair_Implementation() {
}

void ASDIDamageableActor::MulticastOnDestruction_Implementation(AController* InstigatorController, APawn* InstigatorPawn, AActor* DamageCauser, const FSDIReplicatedDamageData& DamageTakenData) {
}

float ASDIDamageableActor::ModifyDamageTaken_Implementation(float Damage, TSubclassOf<UDamageType> DamageTypeClass, AController* EventInstigator, AActor* DamageCauser, bool bRadialDamage, const FVector& ShotDirection, const FHitResult& HitInfo, const FVector& ImpactVelocity) {
    return 0.0f;
}

bool ASDIDamageableActor::K2ShouldTakeDamage_Implementation(float Damage, TSubclassOf<UDamageType> DamageTypeClass, AController* EventInstigator, AActor* DamageCauser) const {
    return false;
}

bool ASDIDamageableActor::GetTypeDamageModifier(TSubclassOf<UDamageType> DamageType, float& OutModifier) const {
    return false;
}

float ASDIDamageableActor::GetTotalHealthPct() const {
    return 0.0f;
}

int32 ASDIDamageableActor::GetTotalHealth() const {
    return 0;
}

int32 ASDIDamageableActor::GetMaxHealth() const {
    return 0;
}

FSDIReplicatedDamageData ASDIDamageableActor::GetLastDamageTaken() const {
    return FSDIReplicatedDamageData{};
}

TSubclassOf<USDISkinObject> ASDIDamageableActor::GetDamageSkin_Implementation() const {
    return NULL;
}

bool ASDIDamageableActor::CanBeDestroyedByDamage_Implementation(float Damage, TSubclassOf<UDamageType> DamageTypeClass, AController* EventInstigator, AActor* DamageCauser, bool bRadialDamage, const FVector& ShotDirection, const FHitResult& HitInfo, const FVector& ImpactVelocity) const {
    return false;
}

bool ASDIDamageableActor::CanBeAffectedByDamageData_Implementation(float& OutModifier, const FSDIDamageData& DamageData, bool bRadialDamage, AController* EventInstigator, AActor* DamageCauser) const {
    return false;
}

int32 ASDIDamageableActor::AlterHealth(int32 Amount) {
    return 0;
}

void ASDIDamageableActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASDIDamageableActor, RepDamageTakenData);
    DOREPLIFETIME(ASDIDamageableActor, RepSkinData);
}

ASDIDamageableActor::ASDIDamageableActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HealthAttr = CreateDefaultSubobject<USDICoreAttributeComponent>(TEXT("Health"));
    this->NonDamageHitMinImpactVelocity = 64.00f;
    this->NonDamageHitInterval = 0.50f;
    this->NonDamageHitTimestamp = 0.00f;
    this->SkinComponent = NULL;
    this->bAllowStab = false;
}

