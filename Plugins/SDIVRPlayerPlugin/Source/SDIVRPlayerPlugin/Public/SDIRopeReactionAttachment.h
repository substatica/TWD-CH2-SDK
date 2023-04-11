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
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIInteractiveRopeActor* Rope;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    USceneComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector RelativeLocation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bRopeEndAttached;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector ElasticityWorldLocation;
    
    FSDIRopeReactionAttachment();
};

