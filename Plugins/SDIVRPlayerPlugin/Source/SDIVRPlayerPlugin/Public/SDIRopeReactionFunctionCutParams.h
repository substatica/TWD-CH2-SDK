#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "SDIRopeReactionFunctionCutParams.generated.h"

class ASDIInteractiveRopeActor;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionFunctionCutParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIInteractiveRopeActor* OtherRope;
    
    FSDIRopeReactionFunctionCutParams();
};

