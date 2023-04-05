#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIStrideDataFootBaseTrajectory.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIStrideDataFootBaseTrajectory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector TranslationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Progression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 BaseFootIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RotationAbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RotationProgression;
    
    FSDIStrideDataFootBaseTrajectory();
};

