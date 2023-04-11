#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDISimulatedCableParticle.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDISimulatedCableParticle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector LastPosition;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Velocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float SegmentLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bFixed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 BoundBodyIndex;
    
    FSDISimulatedCableParticle();
};

