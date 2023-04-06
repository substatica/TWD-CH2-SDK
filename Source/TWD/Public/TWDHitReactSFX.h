#pragma once
#include "CoreMinimal.h"
#include "TWDHitReactSFX.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct TWD_API FTWDHitReactSFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AKEvent;
    
    FTWDHitReactSFX();
};

