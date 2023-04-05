#pragma once
#include "CoreMinimal.h"
#include "SDIWorldSettings.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SpawnVFXAttachedParams -FallbackName=SpawnVFXAttachedParams
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Particles/WorldPSCPool.h"
#include "TWDWorldSettings.generated.h"

class UFXSystemAsset;
class UObject;

UCLASS()
class TWD_API ATWDWorldSettings : public ASDIWorldSettings {
    GENERATED_BODY()
public:
    ATWDWorldSettings(const FObjectInitializer& ObjectInitializer);
    UFUNCTION()
    void SpawnVFXAttached(FSpawnVFXAttachedParams Params);
    
    UFUNCTION(meta=(WorldContext="WorldContextObject"))
    void SpawnVFXAtLocation(const UObject* WorldContextObject, UFXSystemAsset* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivateSystem);
    
};

