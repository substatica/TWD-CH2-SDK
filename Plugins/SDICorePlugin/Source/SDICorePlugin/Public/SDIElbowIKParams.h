#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIElbowIKParams.generated.h"

USTRUCT()
struct SDICOREPLUGIN_API FSDIElbowIKParams {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    FTransform ShoulderTransform;
    
    UPROPERTY(Transient)
    FVector ShoulderLocation;
    
    UPROPERTY(Transient)
    FVector ShoulderForwardAxis;
    
    UPROPERTY(Transient)
    FVector ShoulderSideAxis;
    
    UPROPERTY(Transient)
    FVector ShoulderUpAxis;
    
    UPROPERTY(Transient)
    FVector WristLocation;
    
    UPROPERTY(Transient)
    FVector ShoulderWristDir;
    
    UPROPERTY(Transient)
    float ShoulderWristDistance;
    
    UPROPERTY(Transient)
    FVector HandDirection;
    
    UPROPERTY(Transient)
    FVector HandPalmDirection;
    
    UPROPERTY(Transient)
    FVector HandThumbDirection;
    
    UPROPERTY(Transient)
    FVector BaseElbowDirection;
    
    UPROPERTY(Transient)
    float UpperArmLength;
    
    UPROPERTY(Transient)
    float ForeArmLength;
    
    UPROPERTY(Transient)
    float ExtensionDistance;
    
    UPROPERTY(Transient)
    float ExtensionScale;
    
    UPROPERTY(Transient)
    float ExtensionShoulderOffset;
    
    FSDIElbowIKParams();
};

