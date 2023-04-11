#pragma once
#include "CoreMinimal.h"
#include "RTPCMapKey.generated.h"

class UAkRtpc;

USTRUCT(BlueprintType)
struct FRTPCMapKey {
    GENERATED_BODY()
public:
    UPROPERTY()
    UAkRtpc* RTPCValue;
    
    UPROPERTY()
    FString RTPC;
    
    AKAUDIO_API FRTPCMapKey();
};

