#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TWDPathQueryInfo.generated.h"

USTRUCT(BlueprintType)
struct FTWDPathQueryInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TArray<FVector> Path;
    
    TWD_API FTWDPathQueryInfo();
};

