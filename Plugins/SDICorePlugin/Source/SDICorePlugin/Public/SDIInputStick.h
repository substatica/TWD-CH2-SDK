#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIInputStick.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIInputStick {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector2D Cumulative;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector2D Normalized;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Angle;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Deflection;
    
public:
    FSDIInputStick();
};

