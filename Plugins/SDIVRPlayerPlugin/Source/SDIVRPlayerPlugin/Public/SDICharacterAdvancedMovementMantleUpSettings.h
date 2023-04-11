#pragma once
#include "CoreMinimal.h"
#include "SDICharacterAdvancedMovementMantleUpSettings.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDICharacterAdvancedMovementMantleUpSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bRequireBothHands;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ForwardDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float VerticalClearance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float Velocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bEnableAutoMantle;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AutoMantleMinVerticalHandDistance;
    
    FSDICharacterAdvancedMovementMantleUpSettings();
};

