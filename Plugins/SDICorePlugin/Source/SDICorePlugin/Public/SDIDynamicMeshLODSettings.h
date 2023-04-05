#pragma once
#include "CoreMinimal.h"
#include "SDIDynamicMeshLODSettings.generated.h"

USTRUCT(BlueprintType)
struct FSDIDynamicMeshLODSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float EngageDistance;
    
    UPROPERTY(Transient)
    int32 RequiredVertexCount;
    
    UPROPERTY(Transient)
    int32 RequiredIndexCount;
    
public:
    SDICOREPLUGIN_API FSDIDynamicMeshLODSettings();
};

