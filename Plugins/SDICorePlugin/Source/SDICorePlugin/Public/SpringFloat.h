#pragma once
#include "CoreMinimal.h"
#include "RFloat.h"
#include "SpringFloat.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSpringFloat {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    float Target;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Current;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Velocity;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SpringK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SpringDamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat VelocityClamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat TargetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat ValueRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAllowOvershoot;
    
    FSpringFloat();
};

