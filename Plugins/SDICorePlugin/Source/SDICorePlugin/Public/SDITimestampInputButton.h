#pragma once
#include "CoreMinimal.h"
#include "SDIInputButtonBase.h"
#include "SDITimestampInputButton.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDITimestampInputButton : public FSDIInputButtonBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAllowTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PressedTimestamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ReleasedTimestamp;
    
public:
    FSDITimestampInputButton();
};

