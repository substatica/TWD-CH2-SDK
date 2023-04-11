#pragma once
#include "CoreMinimal.h"
#include "SDICoreAttributeComponentSettings.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICoreAttributeComponentSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 InitialValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bRegenEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAllowRegenFromZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RegenDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RegenRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RegenPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 RegenMinPerInterval;
    
    FSDICoreAttributeComponentSettings();
};

