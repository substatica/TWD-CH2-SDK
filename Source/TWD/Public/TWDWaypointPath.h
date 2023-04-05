#pragma once
#include "CoreMinimal.h"
#include "ETWDWaypointTriggerEvent.h"
#include "GameFramework/Actor.h"
#include "TWDWaypointSettings.h"
#include "TWDWaypointPath.generated.h"

class USplineComponent;
class ATWDWaypoint;
class UTWDWaypointPatrolComponent;

UCLASS()
class TWD_API ATWDWaypointPath : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FTWDWaypointSettings DefaultWaypointSettings;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FTWDWaypointSettings> Waypoints;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<ATWDWaypoint*> WaypointList;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bIsLooping;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bShowDebugWapointConnections;
    
    UPROPERTY(Instanced)
    USplineComponent* EditorPathSpline;
    
    ATWDWaypointPath();
    UFUNCTION(BlueprintImplementableEvent)
    void OnUnassigned(UTWDWaypointPatrolComponent* PatrolComponent);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnAssigned(UTWDWaypointPatrolComponent* PatrolComponent);
    
    UFUNCTION(BlueprintPure)
    FTWDWaypointSettings GetWaypointSettingsAtIndex(int32 Index) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetWaypointIndex(ATWDWaypoint* Waypoint) const;
    
    UFUNCTION(BlueprintPure)
    ATWDWaypoint* GetWaypointAtIndex(int32 Index) const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool CanActorSendWaypointEvent(const AActor* Actor, ATWDWaypoint* Waypoint, ETWDWaypointTriggerEvent Event) const;
    
};

