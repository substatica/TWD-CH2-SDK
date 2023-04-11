#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionStruggleActiveParams.h"
#include "SDIRopeReactionStruggleTickParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionStruggleTickParams : public FSDIRopeReactionStruggleActiveParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsActive;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAllowIncrement;
    
    FSDIRopeReactionStruggleTickParams();
};

