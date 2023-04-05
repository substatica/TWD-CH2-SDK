#pragma once
#include "CoreMinimal.h"
#include "LookAtCameraInfo.generated.h"

class UCameraComponent;

USTRUCT(BlueprintType)
struct FLookAtCameraInfo {
    GENERATED_BODY()
public:
    UPROPERTY(Instanced, Transient)
    UCameraComponent* Camera;
    
    TWD_API FLookAtCameraInfo();
};

