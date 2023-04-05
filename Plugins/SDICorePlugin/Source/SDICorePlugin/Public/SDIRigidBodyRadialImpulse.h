#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "SDIRigidBodyRadialImpulse.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIRigidBodyRadialImpulse {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    FVector Origin;
    
    UPROPERTY(Transient)
    float Radius;
    
    UPROPERTY(Transient)
    float Strength;
    
    UPROPERTY(Transient)
    TEnumAsByte<ERadialImpulseFalloff> Falloff;
    
    UPROPERTY(Transient)
    bool bVelChange;
    
    FSDIRigidBodyRadialImpulse();
};

