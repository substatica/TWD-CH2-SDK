#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionStruggleActiveParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionStruggleActiveParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautPct;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector RopeDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector HandOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector MovementStick;
    
    FSDIRopeReactionStruggleActiveParams();
};

