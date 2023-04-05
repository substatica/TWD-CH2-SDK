#pragma once
#include "CoreMinimal.h"
#include "ETWDCharacterHitRegion.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDSafariGunShotData.generated.h"

class ATWDCharacter;
class AController;

USTRUCT(BlueprintType)
struct FTWDSafariGunShotData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ATWDCharacter> Character;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform ImpactTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ImpactEnergyNorm;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<AController> EventInstigator;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult HitResult;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDCharacterHitRegion HitRegion;
    
    TWD_API FTWDSafariGunShotData();
};

