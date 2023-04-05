#pragma once
#include "CoreMinimal.h"
#include "SDIComponentReplacement.h"
#include "SDIComponentReplacementSphere.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIComponentReplacementSphere : public FSDIComponentReplacement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(VisibleDefaultsOnly)
    float Radius;
    
public:
    FSDIComponentReplacementSphere();
};

