#pragma once
#include "CoreMinimal.h"
#include "PerPlatformSoftObjectWorldPtr.generated.h"

class UWorld;

USTRUCT()
struct TWD_API FPerPlatformSoftObjectWorldPtr {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UWorld> Default;
    
    FPerPlatformSoftObjectWorldPtr();
};

