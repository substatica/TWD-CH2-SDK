#pragma once
#include "CoreMinimal.h"
#include "ESDIHandGripState.h"
#include "UObject/NoExportTypes.h"
#include "SDIElbowIKHeldActor.h"
#include "SDIElbowIKRope.h"
#include "SDIElbowIK.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIElbowIK {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    bool bIsValid;
    
    UPROPERTY(Transient)
    ESDIHandGripState GripState;
    
    UPROPERTY(Transient)
    FTransform GripTransform;
    
    UPROPERTY(Transient)
    FTransform WristTransform;
    
    UPROPERTY(Transient)
    FTransform ElbowTransform;
    
    UPROPERTY(Transient)
    FTransform ShoulderTransform;
    
    UPROPERTY(Transient)
    FSDIElbowIKHeldActor HeldActorElbowIK;
    
    UPROPERTY(Transient)
    FSDIElbowIKRope RopeElbowIK;
    
    FSDIElbowIK();
};

