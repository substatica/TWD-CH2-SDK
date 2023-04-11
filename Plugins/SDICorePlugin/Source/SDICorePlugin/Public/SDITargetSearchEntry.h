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
    UPROPERTY(BlueprintReadWrite, Transient)
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UPrimitiveComponent* Comp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Direction;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator Angle;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Distance;
    
    FSDITargetSearchEntry();
};

