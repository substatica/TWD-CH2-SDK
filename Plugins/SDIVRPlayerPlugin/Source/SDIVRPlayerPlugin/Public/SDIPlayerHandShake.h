#pragma once
#include "CoreMinimal.h"
#include "VectorRandomOscillator.h"
#include "RotatorRandomOscillator.h"
#include "SDIPlayerHandShake.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIPlayerHandShake {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    int32 ID;
    
    UPROPERTY(Transient)
    float Scale;
    
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FVectorRandomOscillator Location;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FRotatorRandomOscillator Rotation;
    
    FSDIPlayerHandShake();
};

