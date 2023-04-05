#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "TWDFavorDecaySettings.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDFavorDecaySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve PositiveFavorDeltaCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve NegativeFavorDeltaCurve;
    
    FTWDFavorDecaySettings();
};

