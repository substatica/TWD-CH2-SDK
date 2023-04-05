#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionStruggleActiveParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionStruggleActiveParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float TautPct;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float TautLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector RopeDirection;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector HandOffset;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector MovementStick;
    
    FSDIRopeReactionStruggleActiveParams();
};

