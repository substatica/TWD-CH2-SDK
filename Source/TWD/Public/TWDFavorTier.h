#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TWDFavorTier.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct TWD_API FTWDFavorTier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinimumFavorRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftObjectPtr<UTexture2D> UIIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor UIColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 DifficultyRating;
    
    FTWDFavorTier();
};

