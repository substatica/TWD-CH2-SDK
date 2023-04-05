#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeComponentHandGrip.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeComponentHandGrip {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    FName BodyName;
    
    UPROPERTY(Transient)
    FFloatRK4SpringInterpolator GripTautSpring;
    
    UPROPERTY(Transient)
    float Timestamp;
    
    FSDIRopeComponentHandGrip();
};

