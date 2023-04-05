#pragma once
#include "CoreMinimal.h"
#include "SDIRibbonLODSettings.h"
#include "Components/SplineComponent.h"
#include "ESDIAxis.h"
#include "SDIBlendOption.h"
#include "RFloat.h"
#include "PerPlatformProperties.h"
#include "SDICoreRibbonComponent.generated.h"

class UMaterialInterface;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDICoreRibbonComponent : public USplineComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    bool bIsAnimatedSpline;
    
    UPROPERTY(EditAnywhere)
    bool bAlwaysGenerateMesh;
    
    UPROPERTY(EditAnywhere)
    float MinimumMovementDistance;
    
    UPROPERTY(EditAnywhere)
    float ExtensionTime;
    
    UPROPERTY(EditAnywhere)
    float RetractionTime;
    
    UPROPERTY(EditAnywhere)
    int32 MaxMotionHistory;
    
    UPROPERTY(EditAnywhere)
    float MaxMotionAge;
    
    UPROPERTY(EditAnywhere)
    ESDIAxis MotionAxis;
    
    UPROPERTY(EditAnywhere)
    FSDIBlendOption MotionAxisBlend;
    
    UPROPERTY(EditAnywhere)
    FRFloat VelocityRange;
    
    UPROPERTY(EditAnywhere)
    FSDIBlendOption VelocityRangeBlend;
    
    UPROPERTY(EditAnywhere)
    bool bVelocityInMotionAxisOnly;
    
    UPROPERTY(EditAnywhere)
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FSDIRibbonLODSettings> LODSettings;
    
    UPROPERTY(EditAnywhere)
    FPerPlatformInt MinimumLOD;
    
    UPROPERTY(EditAnywhere)
    FPerPlatformInt ForcedLOD;
    
public:
    USDICoreRibbonComponent();
    UFUNCTION(BlueprintPure)
    bool IsIdle() const;
    
};

