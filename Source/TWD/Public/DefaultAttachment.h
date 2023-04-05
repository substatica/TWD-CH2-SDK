#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DefaultAttachment.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FDefaultAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> Comp;
    
    UPROPERTY(Transient)
    FTransform Transform;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> Parent;
    
    UPROPERTY(Transient)
    FName Socket;
    
    TWD_API FDefaultAttachment();
};

