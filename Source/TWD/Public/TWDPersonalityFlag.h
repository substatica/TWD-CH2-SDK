#pragma once
#include "CoreMinimal.h"
#include "TWDPersonalityFlag.generated.h"

USTRUCT(BlueprintType)
struct FTWDPersonalityFlag {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bSet;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bIsSetKnown;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float TimeKnown;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bCurrentlySet;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float TimeCurrentlySet;
    
    TWD_API FTWDPersonalityFlag();
};

