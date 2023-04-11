#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionPullParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionPullParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautPct;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector PullDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector PullOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PullDistance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector MovementStick;
    
    FSDIRopeReactionPullParams();
};

