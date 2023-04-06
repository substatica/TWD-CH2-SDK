#pragma once
#include "CoreMinimal.h"
#include "ETWDWaypointTriggerEvent.h"
#include "ETWDWaypointFilterType.h"
#include "TWDWaypointTriggerEventData.generated.h"

class ATWDWaypoint;
class AActor;

USTRUCT(BlueprintType)
struct FTWDWaypointTriggerEventData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ATWDWaypoint* Waypoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<AActor*> ActorFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDWaypointFilterType FilterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDWaypointTriggerEvent Event;
    
    TWD_API FTWDWaypointTriggerEventData();
};

