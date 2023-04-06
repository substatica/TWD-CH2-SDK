#pragma once
#include "CoreMinimal.h"
#include "ETWDWaypointMovementMode.h"
#include "EAIBaseGroundMovementSpeedType.h"
#include "ECharacterStance.h"
#include "TWDWaypointTrigger.h"
#include "TWDWaypointSettings.generated.h"

class ATWDWaypoint;

USTRUCT(BlueprintType)
struct FTWDWaypointSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ATWDWaypoint* Waypoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDWaypointMovementMode MovementMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ThreatRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EAIBaseGroundMovementSpeedType BaseGroundMovementSpeedType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ECharacterStance Stance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bClearHistoryOnDeparture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FTWDWaypointTrigger> Triggers;
    
    TWD_API FTWDWaypointSettings();
};

