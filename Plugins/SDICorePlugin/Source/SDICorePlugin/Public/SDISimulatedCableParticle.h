#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDISimulatedCableParticle.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDISimulatedCableParticle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Position;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector LastPosition;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Velocity;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float SegmentLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bFixed;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    int32 BoundBodyIndex;
    
    FSDISimulatedCableParticle();
};

