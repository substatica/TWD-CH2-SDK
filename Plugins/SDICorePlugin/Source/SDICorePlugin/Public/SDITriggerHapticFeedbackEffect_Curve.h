#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SDITriggerHapticFeedbackEffect_Curve.generated.h"

UCLASS()
class SDICOREPLUGIN_API USDITriggerHapticFeedbackEffect_Curve : public UObject {
    GENERATED_BODY()
public:	
    void GetValues(const float EvalTime, UObject& Values);

	float GetDuration() const;
protected:
    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve TriggerScale;
    
public:
    USDITriggerHapticFeedbackEffect_Curve();
};

