#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TWDPrimaryAssetRule.generated.h"

USTRUCT(BlueprintType)
struct FTWDPrimaryAssetRule {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FPrimaryAssetId PrimaryAssetId;
    
    UPROPERTY(EditAnywhere)
    TArray<FString> Platforms;
    
    UPROPERTY(EditAnywhere)
    TArray<FString> Versions;
    
    TWD_API FTWDPrimaryAssetRule();
};

