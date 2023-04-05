#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TWDSafariSplashData.generated.h"

class ATWDCharacter;
class AController;

USTRUCT(BlueprintType)
struct FTWDSafariSplashData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ATWDCharacter> SplashingActor;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Origin;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Direction;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ImpactEnergyNorm;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<AController> EventInstigator;
    
    TWD_API FTWDSafariSplashData();
};

