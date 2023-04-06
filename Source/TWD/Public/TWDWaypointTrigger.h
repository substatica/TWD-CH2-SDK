#pragma once
#include "CoreMinimal.h"
#include "ETWDWaypointTriggerAction.h"
#include "ETWDWaypointTriggerOperation.h"
#include "TWDWaypointTriggerEventData.h"
#include "TWDWaypointTrigger.generated.h"

USTRUCT(BlueprintType)
struct FTWDWaypointTrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDWaypointTriggerOperation TriggerOperation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FTWDWaypointTriggerEventData> Events;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ETWDWaypointTriggerAction Action;
    
    TWD_API FTWDWaypointTrigger();
};

