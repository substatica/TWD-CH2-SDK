#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDITargetSearchEntry.generated.h"

class AActor;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDITargetSearchEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    AActor* Actor;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UPrimitiveComponent* Comp;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Location;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Direction;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Angle;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Distance;
    
    FSDITargetSearchEntry();
};

