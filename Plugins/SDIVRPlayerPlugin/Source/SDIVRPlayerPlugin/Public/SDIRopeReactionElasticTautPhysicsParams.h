#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionElasticTautPhysicsParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionElasticTautPhysicsParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector GripPivot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector RopeDirection;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float TautLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ElasticTautLength;
    
    FSDIRopeReactionElasticTautPhysicsParams();
};

