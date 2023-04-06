#pragma once
#include "CoreMinimal.h"
#include "TWDAmmoPouchItemInfo.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDAmmoPouchItemInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FText AmmoName;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 AmmoClip;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 AmmoStock;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float FuelGauge;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float FuelStock;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bShowStock;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsFuel;
    
    FTWDAmmoPouchItemInfo();
};

