#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIAnimationHandIKTarget.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAnimationHandIKTarget {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    float ActivationSpeed;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform Transform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bEnableEffectorSpring;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Alpha;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<USceneComponent> RelativeComponent;
    
    UPROPERTY(Transient)
    FName RelativeSocketName;
    
    UPROPERTY(Transient)
    FTransform RelativeTransform;
    
    FSDIAnimationHandIKTarget();
};

