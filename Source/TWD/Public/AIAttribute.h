#pragma once
#include "CoreMinimal.h"
#include "EAIAttributeTypes.h"
#include "SDIEnumTypeHandle.h"
#include "AIAttribute.generated.h"

USTRUCT(BlueprintType)
struct FAIAttribute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EAIAttributeTypes Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Current;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Rate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Max;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RandMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RandMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GOBUrgeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GOBUrgeAdder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIEnumTypeHandle AttributeFilter;
    
    TWD_API FAIAttribute();
};

