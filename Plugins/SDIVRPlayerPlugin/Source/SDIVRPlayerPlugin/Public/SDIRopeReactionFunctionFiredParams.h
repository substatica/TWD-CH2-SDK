#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionAttachment.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionFunctionFiredParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionFunctionFiredParams : public FSDIRopeReactionAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector WorldLocation;
    
    FSDIRopeReactionFunctionFiredParams();
};

