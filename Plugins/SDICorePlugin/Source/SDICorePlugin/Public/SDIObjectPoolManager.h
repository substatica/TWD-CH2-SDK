#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDICoreGameInstanceSubObject.h"
#include "SDIObjectPoolManagerEntry.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIObjectPoolManager.generated.h"

class ASDIObjectPool;
class UObject;

UCLASS(Config=Game)
class SDICOREPLUGIN_API USDIObjectPoolManager : public USDICoreGameInstanceSubObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Config, VisibleAnywhere)
    bool bEnablePooling;
    
    UPROPERTY(Config, VisibleAnywhere)
    TArray<FSDIObjectPoolManagerEntry> Pools;
    
    UPROPERTY(Transient)
    TMap<UClass*, ASDIObjectPool*> PoolMap;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<UClass*> AlwaysAllowCreateExactClassOverrides;
    
public:
    USDIObjectPoolManager();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddPoolStatic(const UObject* WorldContextObject, UClass* InObjectClass, int32 InStartingPoolSize, int32 InMaxPoolSize, TSubclassOf<ASDIObjectPool> InPoolClass);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UObject* AcquireFromPoolStatic(const UObject* WorldContextObject, const UClass*& ObjectClass, FVector Location, FRotator Rotation, FVector Scale3D, bool bCreateIfNecessary);
    
};

