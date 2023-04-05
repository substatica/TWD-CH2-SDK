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
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float Current;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float Rate;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float Max;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float RandMax;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float RandMin;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float GOBUrgeMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float GOBUrgeAdder;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDIEnumTypeHandle AttributeFilter;
    
    TWD_API FAIAttribute();
};

