#pragma once
#include "CoreMinimal.h"
#include "SDIDynamicMeshLODSettings.h"
#include "SDIRibbonLODSettings.generated.h"

USTRUCT(BlueprintType)
struct FSDIRibbonLODSettings : public FSDIDynamicMeshLODSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    int32 EdgeResolution;
    
    UPROPERTY(EditAnywhere)
    int32 MotionResolution;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MotionSplineTension;
    
public:
    SDICOREPLUGIN_API FSDIRibbonLODSettings();
};

