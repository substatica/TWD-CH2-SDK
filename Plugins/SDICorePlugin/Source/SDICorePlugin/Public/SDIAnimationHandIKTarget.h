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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform Transform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableEffectorSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Alpha;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> RelativeComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RelativeSocketName;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform RelativeTransform;
    
    FSDIAnimationHandIKTarget();
};

