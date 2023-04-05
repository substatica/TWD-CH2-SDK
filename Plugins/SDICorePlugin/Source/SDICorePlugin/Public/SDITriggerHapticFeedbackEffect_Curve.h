#pragma once
#include "CoreMinimal.h"
#include "Haptics/HapticFeedbackEffect_Curve.h"
#include "Curves/CurveFloat.h"
#include "SDITriggerHapticFeedbackEffect_Curve.generated.h"

UCLASS()
class SDICOREPLUGIN_API USDITriggerHapticFeedbackEffect_Curve : public UHapticFeedbackEffect_Curve {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve TriggerScale;
    
public:
    USDITriggerHapticFeedbackEffect_Curve();
};

