#pragma once
#include "CoreMinimal.h"
#include "SDIEnumTypeHandle.generated.h"

class UEnum;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIEnumTypeHandle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UEnum* EnumData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName EnumValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName EnumName;
    
    FSDIEnumTypeHandle();
};

