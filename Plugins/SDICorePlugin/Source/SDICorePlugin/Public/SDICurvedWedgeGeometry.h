#pragma once
#include "CoreMinimal.h"
#include "SDITransformCollisionShape.h"
#include "RFloat.h"
#include "RFloatExp.h"
#include "SDIBlendOption.h"
#include "Curves/CurveFloat.h"
#include "SDICurvedWedgeGeometry.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICurvedWedgeGeometry {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloat Distance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bFlattenWedge;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp HeightRange;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUseAngleDegCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloat AngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIBlendOption AngleDegBlend;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve AngleDegCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float BoundingShapeStep;
    
    UPROPERTY(Transient)
    bool bIsDirty;
    
    UPROPERTY(Transient)
    FSDITransformCollisionShape BoundingShape;
    
public:
    FSDICurvedWedgeGeometry();
};

