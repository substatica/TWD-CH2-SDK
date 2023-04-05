#pragma once
#include "CoreMinimal.h"
#include "RFloat.h"
#include "UObject/NoExportTypes.h"
#include "SDIBlendOption.h"
#include "SDIWaveformAxis.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIWaveformAxis {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TEnumAsByte<EAxis::Type> Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat CyclesPerMeter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption CyclesPerMeterBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat Amplitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIBlendOption AmplitudeBlend;
    
    FSDIWaveformAxis();
};

