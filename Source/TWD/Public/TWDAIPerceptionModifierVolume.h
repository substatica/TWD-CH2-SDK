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
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNightModifier;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve PerceptionCurveOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StickinessInSeconds;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bIncludeRayCastFromPointSource;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float RayCastInterval;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<AActor>, FPeekOcclusionRayCastTracker> RayCastTrackers;
    
    ATWDAIPerceptionModifierVolume();
    UFUNCTION(BlueprintPure)
    float GetCanBeSeenDistanceFactor(const ATWDCharacter* Observered, const ATWDCharacter* Observer) const;
    
};

