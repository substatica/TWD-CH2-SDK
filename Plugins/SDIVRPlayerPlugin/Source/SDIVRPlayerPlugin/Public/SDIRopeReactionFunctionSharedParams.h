#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionAttachment.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionFunctionSharedParams.generated.h"

class ASDIPlayerHand;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionFunctionSharedParams : public FSDIRopeReactionAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIPlayerHand* GripHand;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsTwoHanded;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector WorldLocation;
    
    FSDIRopeReactionFunctionSharedParams();
};

