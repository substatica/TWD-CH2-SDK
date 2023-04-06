#pragma once
#include "CoreMinimal.h"
#include "SDIInteractiveHighlightManager.h"
#include "ETWDInteractionType.h"
#include "TWDInteractiveHighlightActorPool.h"
#include "TWDInteractiveHighlightManagerEntry.h"
#include "Engine/EngineTypes.h"
#include "TWDInteractiveHighlightManager.generated.h"

class USceneComponent;
class AActor;

UCLASS(Config=Game)
class ATWDInteractiveHighlightManager : public ASDIInteractiveHighlightManager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<ETWDInteractionType, FTWDInteractiveHighlightActorPool> HighlightActorPools;
    
    UPROPERTY(BlueprintReadWrite, Config, EditDefaultsOnly)
    float NearbyRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<ECollisionChannel> NearbyOverlapChannel;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<ECollisionChannel> NearbyLOSChannel;
    
    UPROPERTY(Config, EditDefaultsOnly)
    bool bNearbyDistributeLOSChecks;
    
    UPROPERTY(Config, EditDefaultsOnly)
    bool bNearbyDistributeUpdates;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<FTWDInteractiveHighlightManagerEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<FTWDInteractiveHighlightManagerEntry> NearbyEntries;
    
    UPROPERTY(Transient)
    uint32 NearbyDistributionCounter;
    
public:
    ATWDInteractiveHighlightManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void SetCustomHighlight(AActor* Actor, USceneComponent* Component, bool bHighlighted, ETWDInteractionType Type);
    
};

