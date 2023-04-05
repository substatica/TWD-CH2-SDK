#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESDIAxisType.h"
#include "Curves/CurveFloat.h"
#include "UObject/NoExportTypes.h"
#include "SDIAxisControlCurve.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAxisControlCurve {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EAxis::Type> InputAxis;
    
    UPROPERTY(EditAnywhere)
    ESDIAxisType InputAxisType;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EAxis::Type> OutputAxis;
    
    UPROPERTY(EditAnywhere)
    ESDIAxisType OutputAxisType;
    
    UPROPERTY(EditAnywhere)
    float OutputScale;
    
    UPROPERTY(EditAnywhere)
    bool bOutputAdditive;
    
    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve ControlCurve;
    
    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator Spring;
    
protected:
    UPROPERTY(Transient)
    bool bResetSpring;
    
public:
    FSDIAxisControlCurve();
};

