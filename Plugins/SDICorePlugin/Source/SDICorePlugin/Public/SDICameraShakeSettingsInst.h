#pragma once
#include "CoreMinimal.h"
#include "SDICameraShakeSettings.h"
#include "SDICameraShakeSettingsInst.generated.h"

class UCurveFloat;
class ASDICorePlayerCameraManager;
class UMatineeCameraShake;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICameraShakeSettingsInst : public FSDICameraShakeSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UCurveFloat* ShakeScaleCurve;
    
protected:
    UPROPERTY(Transient)
    TWeakObjectPtr<UMatineeCameraShake> WeakShake;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDICorePlayerCameraManager> WeakCameraManager;
    
public:
    FSDICameraShakeSettingsInst();
};

