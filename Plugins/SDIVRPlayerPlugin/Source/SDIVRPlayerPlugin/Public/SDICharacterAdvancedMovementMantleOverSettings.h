#pragma once
#include "CoreMinimal.h"
#include "RFloat.h"
#include "SDICharacterAdvancedMovementMantleOverSettings.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDICharacterAdvancedMovementMantleOverSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bRequireBothHands;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ForwardDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MinHeight;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float VerticalClearance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HorizontalClearance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float Velocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAdjustEyeHeight;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloat EyeHeightOffsetRange;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bEnableAutoMantle;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AutoMantleMinVerticalHandDistance;
    
    FSDICharacterAdvancedMovementMantleOverSettings();
};

