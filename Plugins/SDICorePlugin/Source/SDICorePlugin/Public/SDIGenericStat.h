#pragma once
#include "CoreMinimal.h"
#include "SDIGenericStat.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIGenericStat {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 Count;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Time;
    
public:
    FSDIGenericStat();
};

