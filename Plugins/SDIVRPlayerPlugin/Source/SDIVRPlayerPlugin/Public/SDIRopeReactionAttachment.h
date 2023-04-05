#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIRopeReactionAttachment.generated.h"

class ASDIInteractiveRopeActor;
class USceneComponent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    ASDIInteractiveRopeActor* Rope;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    USceneComponent* Component;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FName BoneName;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector RelativeLocation;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bRopeEndAttached;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ElasticityWorldLocation;
    
    FSDIRopeReactionAttachment();
};

