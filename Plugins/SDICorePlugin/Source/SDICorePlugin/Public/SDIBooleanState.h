#pragma once
#include "CoreMinimal.h"
#include "ESDIBooleanState.h"
#include "SDIBooleanState.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIBooleanState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    ESDIBooleanState State;
    
public:
    FSDIBooleanState();
};

