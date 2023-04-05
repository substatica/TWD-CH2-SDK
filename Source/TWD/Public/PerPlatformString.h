#pragma once
#include "CoreMinimal.h"
#include "PerPlatformString.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FPerPlatformString {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FString Default;
    
    FPerPlatformString();
};

