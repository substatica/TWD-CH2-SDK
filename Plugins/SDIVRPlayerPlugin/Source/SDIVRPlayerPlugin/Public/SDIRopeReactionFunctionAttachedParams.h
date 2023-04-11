#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionAttachment.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionFunctionAttachedParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionFunctionAttachedParams : public FSDIRopeReactionAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector WorldLocation;
    
    FSDIRopeReactionFunctionAttachedParams();
};

