#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDLoadingScreenTutorial.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct TWD_API FTWDLoadingScreenTutorial : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftObjectPtr<UTexture2D> Image;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxPercentage;
    
    FTWDLoadingScreenTutorial();
};

