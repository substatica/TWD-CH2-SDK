#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionAttachment.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionFunctionDetachedParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionFunctionDetachedParams : public FSDIRopeReactionAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector WorldLocation;
    
    FSDIRopeReactionFunctionDetachedParams();
};

