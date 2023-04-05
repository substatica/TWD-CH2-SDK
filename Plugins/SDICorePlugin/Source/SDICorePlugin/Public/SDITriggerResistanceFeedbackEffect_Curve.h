#pragma once
#include "CoreMinimal.h"
#include "Haptics/HapticFeedbackEffect_Base.h"
#include "Curves/CurveFloat.h"
#include "SDITriggerResistanceFeedbackEffect_Curve.generated.h"

UCLASS()
class SDICOREPLUGIN_API USDITriggerResistanceFeedbackEffect_Curve : public UHapticFeedbackEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve Resistance;
    
public:
    USDITriggerResistanceFeedbackEffect_Curve();
};

