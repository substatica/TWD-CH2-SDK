#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIStrideDataFootCycleDefinition.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIStrideDataFootCycleDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector StancePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StanceDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float StanceCycle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector MiddlePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector ToStrideStartPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FootLiftCycle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FootOffCycle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FootStrikeCycle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FootLandCycle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTransform RootTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 Frame;
    
    FSDIStrideDataFootCycleDefinition();
};

