#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "SDIMotionHistory.h"
#include "DebugTransformThreshold.h"
#include "SDIDebugTransformComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDIDebugTransformComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    bool bkeepHistory;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIMotionHistory LocationHistory;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIMotionHistory RotationHistory;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIMotionHistory ScaleHistory;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FDebugTransformThreshold> Location;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FDebugTransformThreshold> Rotation;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FDebugTransformThreshold> Scale;
    
protected:
    UPROPERTY(Transient)
    bool bUpdateInitialized;
    
    UPROPERTY(Transient)
    FTransform LastUpdatedRelTransform;
    
    UPROPERTY(Transient)
    FTransform LastUpdatedWorldTransform;
    
    UPROPERTY(Transient)
    float MaxUpdatedLocationDeltaSize;
    
    UPROPERTY(Transient)
    float MaxTickLocationVelocity;
    
    UPROPERTY(Transient)
    bool bTickInitialized;
    
    UPROPERTY(Transient)
    FTransform LastTickRelTransform;
    
    UPROPERTY(Transient)
    FTransform LastTickWorldTransform;
    
public:
    USDIDebugTransformComponent();
};

