#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionTickParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionTickParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FName GripSegmentName;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautPct;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector GripPivot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector BindPivot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector RopeDirection;
    
    FSDIRopeReactionTickParams();
};

