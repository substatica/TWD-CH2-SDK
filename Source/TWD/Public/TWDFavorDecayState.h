#pragma once
#include "CoreMinimal.h"
#include "TWDFavorDecayState.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDFavorDecayState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 ConsecutiveOrdersFailed;
    
    FTWDFavorDecayState();
};

