#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIMotionHistoryEntry.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIMotionHistoryEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform Transform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Velocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Acceleration;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector AngularVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Timestamp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float FrameTime;
    
    FSDIMotionHistoryEntry();
};

