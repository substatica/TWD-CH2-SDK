#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "TWDFavorDecaySettings.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDFavorDecaySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve PositiveFavorDeltaCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve NegativeFavorDeltaCurve;
    
    FTWDFavorDecaySettings();
};

