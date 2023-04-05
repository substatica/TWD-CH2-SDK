#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIDamageableActorSkin.h"
#include "SDIInteractiveActor.h"
#include "SDIDamageTakenReplicationInterface.h"
#include "SDISkinnedActorInterface.h"
#include "SDISkinnedActorBlueprintInterface.h"
#include "SDIMeleeWeaponStabInterface.h"
#include "Engine/EngineTypes.h"
#include "SDIDamageableActorHealthChangeSignatureDelegate.h"
#include "SDISkinReplicationData.h"
#include "SDIDamageableActorDestructionSignatureDelegate.h"
#include "SDIDamageableActorRepairSignatureDelegate.h"
#include "SDIReplicatedDamageData.h"
#include "SDISkinDynamicData.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/EngineTypes.h"
#include "SDIMeleeWeaponStabCompletedSignatureDelegate.h"
#include "SDIMeleeWeaponStabInterfaceData.h"
#include "SDIMeleeWeaponStabStartedSignatureDelegate.h"
#include "SDIMeleeWeaponStabEndedSignatureDelegate.h"
#include "UObject/NoExportTypes.h"
#include "SDIDamageData.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIDamageableActor.generated.h"

class USDICoreAttributeComponent;
class UDamageType;
class USceneComponent;
class UPrimitiveComponent;
class USDISkinObject;
class AActor;
class AController;
class APawn;
class UObject;
class UTexture;
class UMaterialInterface;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIDamageableActor : public ASDIInteractiveActor, public ISDIDamageTakenReplicationInterface, public ISDISkinnedActorInterface, public ISDISkinnedActorBlueprintInterface, public ISDIMeleeWeaponStabInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, VisibleAnywhere)
    USDICoreAttributeComponent* HealthAttr;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FSDIDamageableActorSkin> DamageSkins;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<TSubclassOf<UDamageType>, float> DamageModifierTypeMap;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonDamageHitMinImpactVelocity;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonDamageHitInterval;
    
    UPROPERTY(Transient)
    FTimerHandle OnNonDamageHitTimer;
    
    UPROPERTY(Transient)
    float NonDamageHitTimestamp;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIDamageableActorHealthChangeSignature HealthChangeDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIDamageableActorDestructionSignature DestructionDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIDamageableActorRepairSignature RepairDelegate;
    
protected:
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepDamageTakenData)
    FSDIReplicatedDamageData RepDamageTakenData;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_RepSkinData)
    FSDISkinReplicationData RepSkinData;
    
    UPROPERTY(EditDefaultsOnly)
    FSDISkinDynamicData DynamicSkinData;
    
    UPROPERTY(BlueprintReadWrite, Instanced)
    USceneComponent* SkinComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAllowStab;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIMeleeWeaponStabInterfaceData StabInterfaceData;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabStartedSignature StabStartedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabCompletedSignature StabCompletedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDIMeleeWeaponStabEndedSignature StabEndedDelegate;
    
    ASDIDamageableActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    int32 SetHealthPctNonZeroMinimum(float Pct, int32 NonZeroMinimumValue);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    int32 SetHealth(int32 NewValue);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetSkin_IFC(TSubclassOf<USDISkinObject> SkinClass, bool bForceUpdate, bool bForceReInit);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnTotalHealthChanged(USDICoreAttributeComponent* Attr, int32 OldTotal, int32 NewTotal);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRepair();
    
protected:
    UFUNCTION()
    void OnRep_RepSkinData(const FSDISkinReplicationData& OldRepSkinData);
    
    UFUNCTION()
    void OnRep_RepDamageTakenData(const FSDIReplicatedDamageData& OldRepDamageTakenData);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnNonDamageHit(AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnDestruction(AController* InstigatorController, APawn* InstigatorPawn, AActor* DamageCauser, const FSDIReplicatedDamageData& DamageTakenData);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastOnRepair();
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastOnDestruction(AController* InstigatorController, APawn* InstigatorPawn, AActor* DamageCauser, const FSDIReplicatedDamageData& DamageTakenData);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    float ModifyDamageTaken(float Damage, TSubclassOf<UDamageType> DamageTypeClass, AController* EventInstigator, AActor* DamageCauser, bool bRadialDamage, const FVector& ShotDirection, const FHitResult& HitInfo, const FVector& ImpactVelocity);
    
    UFUNCTION(BlueprintNativeEvent)
    bool K2ShouldTakeDamage(float Damage, TSubclassOf<UDamageType> DamageTypeClass, AController* EventInstigator, AActor* DamageCauser) const;
    
    UFUNCTION(BlueprintPure)
    bool GetTypeDamageModifier(TSubclassOf<UDamageType> DamageType, float& OutModifier) const;
    
    UFUNCTION(BlueprintPure)
    float GetTotalHealthPct() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetTotalHealth() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetMaxHealth() const;
    
    UFUNCTION(BlueprintPure)
    FSDIReplicatedDamageData GetLastDamageTaken() const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    TSubclassOf<USDISkinObject> GetDamageSkin() const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool CanBeDestroyedByDamage(float Damage, TSubclassOf<UDamageType> DamageTypeClass, AController* EventInstigator, AActor* DamageCauser, bool bRadialDamage, const FVector& ShotDirection, const FHitResult& HitInfo, const FVector& ImpactVelocity) const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool CanBeAffectedByDamageData(float& OutModifier, const FSDIDamageData& DamageData, bool bRadialDamage, AController* EventInstigator, AActor* DamageCauser) const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    int32 AlterHealth(int32 Amount);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    bool SwapSkinTextureParam(UObject* ParamOwner, int32 inIndex, FName InParam, UTexture* OldValue, UTexture* NewValue) override PURE_VIRTUAL(SwapSkinTextureParam, return false;);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    bool SwapSkinMaterialParam(UObject* ParamOwner, int32 inIndex, FName InParam, UMaterialInterface* OldValue, UMaterialInterface* NewValue) override PURE_VIRTUAL(SwapSkinMaterialParam, return false;);
    
    UFUNCTION(BlueprintCallable)
    void SkinSetComponentIgnorances(const TArray<UPrimitiveComponent*>& OtherComps) override PURE_VIRTUAL(SkinSetComponentIgnorances,);
    
    UFUNCTION(BlueprintCallable)
    void SkinSetComponentIgnorance(UPrimitiveComponent* OtherComp) override PURE_VIRTUAL(SkinSetComponentIgnorance,);
    
    UFUNCTION(BlueprintCallable)
    void SkinIgnoreChannelUntilClear(TEnumAsByte<ECollisionChannel> Channel) override PURE_VIRTUAL(SkinIgnoreChannelUntilClear,);
    
    UFUNCTION(BlueprintCallable)
    void SkinClearComponentIgnorances(const TArray<UPrimitiveComponent*>& OtherComps, bool bWaitForClearance) override PURE_VIRTUAL(SkinClearComponentIgnorances,);
    
    UFUNCTION(BlueprintCallable)
    void SkinClearComponentIgnorance(UPrimitiveComponent* OtherComp, bool bWaitForClearance) override PURE_VIRTUAL(SkinClearComponentIgnorance,);
    
    UFUNCTION(BlueprintCallable)
    void SkinClearAllComponentIgnorances(bool bWaitForClearance) override PURE_VIRTUAL(SkinClearAllComponentIgnorances,);
    
    UFUNCTION(BlueprintCallable)
    void SkinCancelWaitForClearance(TEnumAsByte<ECollisionChannel> Channel) override PURE_VIRTUAL(SkinCancelWaitForClearance,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinVectorParam(UObject* ParamOwner, int32 inIndex, FName InParam, FVector InValue) override PURE_VIRTUAL(SetSkinVectorParam,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinTextureParam(UObject* ParamOwner, int32 inIndex, FName InParam, UTexture* InValue) override PURE_VIRTUAL(SetSkinTextureParam,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinScalarParam(UObject* ParamOwner, int32 inIndex, FName InParam, float InValue) override PURE_VIRTUAL(SetSkinScalarParam,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinRenderCustomDepth(bool bRenderCustomDepth) override PURE_VIRTUAL(SetSkinRenderCustomDepth,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinOwnerNoSee(bool bOwnerNoSee) override PURE_VIRTUAL(SetSkinOwnerNoSee,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinOnlyOwnerSee(bool bOnlyOwnerSee) override PURE_VIRTUAL(SetSkinOnlyOwnerSee,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinMaterialParam(UObject* ParamOwner, int32 inIndex, FName InParam, UMaterialInterface* InValue) override PURE_VIRTUAL(SetSkinMaterialParam,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinHiddenInGame(bool NewBHidden) override PURE_VIRTUAL(SetSkinHiddenInGame,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinCustomDepthStencilWriteMask(ERendererStencilMask CustomDepthStencilWriteMask) override PURE_VIRTUAL(SetSkinCustomDepthStencilWriteMask,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinCustomDepthStencilValue(int32 CustomDepthStencilValue) override PURE_VIRTUAL(SetSkinCustomDepthStencilValue,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSkinColorParam(UObject* ParamOwner, int32 inIndex, FName InParam, FLinearColor InValue) override PURE_VIRTUAL(SetSkinColorParam,);
    
    UFUNCTION(BlueprintCallable)
    bool SetSkin(TSubclassOf<USDISkinObject> SkinClass, bool bForceUpdate, bool bForceReInit) override PURE_VIRTUAL(SetSkin, return false;);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void RemoveSkinParam(UObject* ParamOwner, int32 inIndex, FName InParam) override PURE_VIRTUAL(RemoveSkinParam,);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void RemoveAllSkinParams(UObject* ParamOwner) override PURE_VIRTUAL(RemoveAllSkinParams,);
    
    UFUNCTION(BlueprintCallable)
    bool IsValidSkin(TSubclassOf<USDISkinObject> SkinClass) const override PURE_VIRTUAL(IsValidSkin, return false;);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<USDISkinObject> GetSkin() const override PURE_VIRTUAL(GetSkin, return NULL;);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool CopySkin(AActor* Other, bool bForceReInit) override PURE_VIRTUAL(CopySkin, return false;);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void ApplySkinParams(bool bForce) override PURE_VIRTUAL(ApplySkinParams,);
    
};

