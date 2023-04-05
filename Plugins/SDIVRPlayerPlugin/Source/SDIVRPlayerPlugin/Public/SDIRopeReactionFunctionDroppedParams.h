#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "SDIRopeReactionFunctionDroppedParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionFunctionDroppedParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    FSDIRopeReactionFunctionDroppedParams();
};

