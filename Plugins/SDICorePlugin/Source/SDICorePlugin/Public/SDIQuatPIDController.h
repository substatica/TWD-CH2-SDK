#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIPIDControllerSettings.h"
#include "SDIQuatPIDController.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIQuatPIDController : public FSDIPIDControllerSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    FQuat Integral;
    
    UPROPERTY(Transient)
    FQuat PreviousError;
    
public:
    FSDIQuatPIDController();
};

