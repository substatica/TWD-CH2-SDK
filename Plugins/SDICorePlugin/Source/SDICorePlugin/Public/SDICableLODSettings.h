#pragma once
#include "CoreMinimal.h"
#include "SDIDynamicMeshLODSettings.h"
#include "SDICableLODSettings.generated.h"

USTRUCT(BlueprintType)
struct FSDICableLODSettings : public FSDIDynamicMeshLODSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SegmentsPerMeter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumSides;
    
    UPROPERTY(Transient)
    int32 NumSegments;
    
    UPROPERTY(Transient)
    TArray<float> SinCache;
    
    UPROPERTY(Transient)
    TArray<float> CosCache;
    
public:
    SDICOREPLUGIN_API FSDICableLODSettings();
};

