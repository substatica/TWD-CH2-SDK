#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TWDDragSettings.generated.h"

USTRUCT(BlueprintType)
struct FTWDDragSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PitchSpringStiffnessConstant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PitchSpringDampeningRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float YawSpringStiffnessConstant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float YawSpringDampeningRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MoveForwardPitchVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MoveRightYawVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator Limit;
    
    TWD_API FTWDDragSettings();
};

