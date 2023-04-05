#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionPullParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionPullParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float TautPct;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector PullDirection;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector PullOffset;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PullDistance;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector MovementStick;
    
    FSDIRopeReactionPullParams();
};

