#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "PeekOcclusionRayCastTracker.h"
#include "TWDAIPerceptionModifierVolume.generated.h"

class ATWDCharacter;

UCLASS()
class TWD_API ATWDAIPerceptionModifierVolume : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNightModifier;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve PerceptionCurveOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StickinessInSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIncludeRayCastFromPointSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RayCastInterval;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<AActor>, FPeekOcclusionRayCastTracker> RayCastTrackers;
    
    ATWDAIPerceptionModifierVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintPure)
    float GetCanBeSeenDistanceFactor(const ATWDCharacter* Observered, const ATWDCharacter* Observer) const;
    
};

