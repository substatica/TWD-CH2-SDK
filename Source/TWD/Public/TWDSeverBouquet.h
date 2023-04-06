#pragma once
#include "CoreMinimal.h"
#include "TWDSeverBouquetElement.h"
#include "TWDSeverBouquet.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct TWD_API FTWDSeverBouquet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AKEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FTWDSeverBouquetElement> Elements;
    
    FTWDSeverBouquet();
};

