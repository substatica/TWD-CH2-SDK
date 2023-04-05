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
    UPROPERTY(BlueprintReadOnly, Transient)
    ASDIPlayerHand* GripHand;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bIsTwoHanded;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector WorldLocation;
    
    FSDIRopeReactionFunctionSharedParams();
};

