#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionStruggleTickParams.h"
#include "SDIRopeReactionStruggleCompleteParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionStruggleCompleteParams : public FSDIRopeReactionStruggleTickParams {
    GENERATED_BODY()
public:
    FSDIRopeReactionStruggleCompleteParams();
};

