#pragma once
#include "CoreMinimal.h"
#include "SDITuningAttribute.generated.h"

USTRUCT(BlueprintType)
struct SDITUNINGPLUGIN_API FSDITuningAttribute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FName AttributeName;
    
    UPROPERTY(BlueprintReadWrite)
    bool bHasSubAttributes;
    
    FSDITuningAttribute();
};

