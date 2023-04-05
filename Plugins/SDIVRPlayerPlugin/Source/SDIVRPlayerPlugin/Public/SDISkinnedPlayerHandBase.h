#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDISkinnedActorInterface.h"
#include "SDIPlayerHandBase.h"
#include "SDISkinnedActorBlueprintInterface.h"
#include "SDISkinReplicationData.h"
#include "SDISkinDynamicData.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/PrimitiveComponent.h"
#include "UObject/NoExportTypes.h"
#include "SDISkinnedPlayerHandBase.generated.h"

class AActor;
class UMaterialInterface;
class UTexture;
class UObject;
class UPrimitiveComponent;
class USDISkinObject;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDISkinnedPlayerHandBase : public ASDIPlayerHandBase, public ISDISkinnedActorInterface, public ISDISkinnedActorBlueprintInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FSDISkinReplicationData ReplicatedSkinData;
    
    UPROPERTY(Transient)
    bool bCosmeticPhysicsFingersWereActive;
    
    UPROPERTY(EditAnywhere)
    FSDISkinDynamicData DynamicSkinData;
    
public:
    ASDISkinnedPlayerHandBase(const FObjectInitializer& ObjectInitializer);
    
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

