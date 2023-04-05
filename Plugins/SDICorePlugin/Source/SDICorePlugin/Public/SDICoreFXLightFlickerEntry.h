#pragma once
#include "CoreMinimal.h"
#include "SDICoreFXCurveAnimation.h"
#include "SDICoreFXLightFlickerEntry.generated.h"

class ULightComponent;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICoreFXLightFlickerEntry : public FSDICoreFXCurveAnimation {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<ULightComponent> LightComponent;
    
public:
    FSDICoreFXLightFlickerEntry();
};

