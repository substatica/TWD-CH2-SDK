#pragma once
#include "CoreMinimal.h"
#include "EEGOAITestTypes.h"
#include "EEGOAIGraphTypes.h"
#include "EEGOAIActionTypes.h"
#include "EAIAttributeTypes.h"
#include "Curves/CurveFloat.h"
#include "EGOAIConsideration.generated.h"

USTRUCT(BlueprintType)
struct FEGOAIConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool Disable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool EditAdvance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EEGOAITestTypes TestType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float TestMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float TestMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString TestMaxBPVariableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString TestMinBPVariableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName TestTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EAIAttributeTypes TestAttributeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EEGOAIActionTypes TestTargetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString TestCustomBPName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bCanCacheTestCustomBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EEGOAIGraphTypes GraphType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GraphM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GraphK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GraphB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GraphC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRuntimeFloatCurve GraphCustomCurve;
    
    TWD_API FEGOAIConsideration();
};

