#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SDITriggerResistanceFeedbackEffect_Curve.generated.h"

UCLASS()
class SDICOREPLUGIN_API USDITriggerResistanceFeedbackEffect_Curve : public UObject {
    GENERATED_BODY()
public:
	void GetValues(const float EvalTime, UObject& Values);

	float GetDuration() const;
protected:
    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve Resistance;
    
public:
    USDITriggerResistanceFeedbackEffect_Curve();
};

