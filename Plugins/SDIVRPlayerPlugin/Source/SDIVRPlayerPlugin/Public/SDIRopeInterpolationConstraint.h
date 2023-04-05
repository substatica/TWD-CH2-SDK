#pragma once
#include "CoreMinimal.h"
#include "SDIGripInfo.h"
#include "SDIRopeInterpolationConstraint.generated.h"

class UActorComponent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeInterpolationConstraint {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<UActorComponent> GripComp;
    
    UPROPERTY(Transient)
    FSDIGripInfo GripInfo;
    
    FSDIRopeInterpolationConstraint();
};

