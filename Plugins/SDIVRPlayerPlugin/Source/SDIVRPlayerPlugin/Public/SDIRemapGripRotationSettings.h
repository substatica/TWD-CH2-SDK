#pragma once
#include "CoreMinimal.h"
#include "SDIRemapGripRotationSettings.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRemapGripRotationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float TwistThreshold;
    
    UPROPERTY(EditAnywhere)
    float Swing1Threshold;
    
    UPROPERTY(EditAnywhere)
    float Swing2Threshold;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* TwistCurve;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* Swing1Curve;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* Swing2Curve;
    
    FSDIRemapGripRotationSettings();
};

