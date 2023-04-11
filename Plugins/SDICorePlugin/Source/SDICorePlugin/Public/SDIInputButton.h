#pragma once
#include "CoreMinimal.h"
#include "SDIInputButtonBase.h"
#include "SDIInputButton.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIInputButton : public FSDIInputButtonBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    float PressedTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ReleasedTimer;
    
public:
    FSDIInputButton();
};

