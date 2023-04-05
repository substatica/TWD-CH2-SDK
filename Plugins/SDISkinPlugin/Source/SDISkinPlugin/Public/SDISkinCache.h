#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "SDICoreGameInstanceSubObject.h"
#include "SDISkinCacheScope.h"
#include "UObject/NoExportTypes.h"
#include "ESDISkinCacheScope.h"
#include "SDISkinCache.generated.h"

class AActor;
class USkeletalMesh;
class USDISkinObject;
class UObject;
class USDISkinCompositeSkeletalMesh;

UCLASS(Config=Game)
class SDISKINPLUGIN_API USDISkinCache : public USDICoreGameInstanceSubObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Config)
    bool bEnableCaching;
    
    UPROPERTY(Config)
    bool bCheckForMissingPreAuthoredMeshes;
    
    UPROPERTY(Config)
    TArray<FSoftClassPath> GlobalSkins;
    
    UPROPERTY(Config)
    TArray<FSoftObjectPath> GlobalSkinResources;
    
    UPROPERTY(Config)
    TArray<TSoftObjectPtr<USkeletalMesh>> IncompatibleFeatureLevelFallbackMeshes;
    
    UPROPERTY(Config)
    TMap<TSoftClassPtr<AActor>, TSoftObjectPtr<USkeletalMesh>> IncompatibleFeatureLevelFallbackMeshesByClass;
    
    UPROPERTY(Transient)
    TMap<ESDISkinCacheScope, FSDISkinCacheScope> SkinCacheScopes;
    
    UPROPERTY(Transient)
    TMap<TSubclassOf<USDISkinObject>, ESDISkinCacheScope> CachedSkins;
    
    UPROPERTY(Transient)
    TSet<UObject*> HandledObjects;
    
    UPROPERTY(Transient)
    TSet<TSubclassOf<USDISkinObject>> VerifiedCachedSkins;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<USDISkinCompositeSkeletalMesh>> WeakCompositeMeshReferences;
    
public:
    USDISkinCache();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CacheMapSkins(const UObject* WorldContextObject, const TArray<UClass*>& Templates, bool bAsync);
    
};

