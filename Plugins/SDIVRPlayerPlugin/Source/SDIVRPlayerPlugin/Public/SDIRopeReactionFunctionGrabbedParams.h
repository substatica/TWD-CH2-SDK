#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "SDIRopeReactionFunctionGrabbedParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionFunctionGrabbedParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    FSDIRopeReactionFunctionGrabbedParams();
};

