#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionStruggleActiveParams.h"
#include "SDIRopeReactionStruggleTickParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionStruggleTickParams : public FSDIRopeReactionStruggleActiveParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bIsActive;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bAllowIncrement;
    
    FSDIRopeReactionStruggleTickParams();
};

