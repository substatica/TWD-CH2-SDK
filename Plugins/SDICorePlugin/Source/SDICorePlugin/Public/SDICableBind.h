#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SDICableBind.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICableBind {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FComponentReference Target;
    
    UPROPERTY(EditAnywhere)
    FName TargetBoneName;
    
    FSDICableBind();
};

