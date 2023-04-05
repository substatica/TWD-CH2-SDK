#pragma once
#include "CoreMinimal.h"
#include "SDIElbowIKHeldActor.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIElbowIKHeldActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bPrimaryGrip;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bOtherHandGripping;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bForearmLockedToGripDirection;
    
    FSDIElbowIKHeldActor();
};

