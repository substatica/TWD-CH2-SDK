#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIComponentReplacement.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIComponentReplacement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<USceneComponent> Component;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<USceneComponent> Parent;
    
    UPROPERTY(VisibleDefaultsOnly)
    FName ParentName;
    
    UPROPERTY(VisibleDefaultsOnly)
    FName ParentSocket;
    
    UPROPERTY()
    FTransform RelTransform;
    
public:
    FSDIComponentReplacement();
};

