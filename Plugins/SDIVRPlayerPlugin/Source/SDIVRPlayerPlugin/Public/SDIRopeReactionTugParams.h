#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionTugParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionTugParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector RopeDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector TugDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bLateralTug;
    
    FSDIRopeReactionTugParams();
};

