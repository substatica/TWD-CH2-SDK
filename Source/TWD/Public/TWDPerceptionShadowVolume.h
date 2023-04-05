#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "TWDPerceptionShadowVolume.generated.h"

class UCurveFloat;

UCLASS(Deprecated, NotPlaceable)
class ADEPRECATED_TWDPerceptionShadowVolume : public AVolume {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    float BasePerceptionMultiplier;
    
    UPROPERTY(EditAnywhere)
    float BasePerceptionAdditive;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* PerceptionCurve;
    
    UPROPERTY(EditAnywhere)
    bool bUseCoverageAttenuation;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* CoverageAttenuationCurve;
    
public:
    ADEPRECATED_TWDPerceptionShadowVolume();
};

