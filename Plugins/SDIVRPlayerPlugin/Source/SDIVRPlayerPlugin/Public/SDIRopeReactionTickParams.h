#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionTickParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionTickParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FName GripSegmentName;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float TautPct;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float TautLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector GripPivot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector BindPivot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector RopeDirection;
    
    FSDIRopeReactionTickParams();
};

