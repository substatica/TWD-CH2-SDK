#pragma once
#include "CoreMinimal.h"
#include "SDIRopeReactionFunctionSharedParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionElasticTautPhysicsParams.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionElasticTautPhysicsParams : public FSDIRopeReactionFunctionSharedParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector GripPivot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector RopeDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ElasticTautLength;
    
    FSDIRopeReactionElasticTautPhysicsParams();
};

