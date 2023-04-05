#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionTugParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionTugParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector RopeDirection;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector TugDirection;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bLateralTug;
    
    FSDIRopeReactionTugParams();
};

