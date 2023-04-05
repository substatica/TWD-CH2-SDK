#pragma once
#include "CoreMinimal.h"
#include "SDIElbowIKRopeConstraint.h"
#include "SDIElbowIKRope.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIElbowIKRope {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<FSDIElbowIKRopeConstraint> Constraints;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bCanBeUsedForMovement;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bOtherHandGripping;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsRopeClimbing;
    
    FSDIElbowIKRope();
};

