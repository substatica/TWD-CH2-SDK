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
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDWaypointSettings DefaultWaypointSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FTWDWaypointSettings> Waypoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<ATWDWaypoint*> WaypointList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsLooping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bShowDebugWapointConnections;
    
    UPROPERTY(Instanced)
    USplineComponent* EditorPathSpline;
    
    ATWDWaypointPath(const FObjectInitializer& ObjectInitializer);
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

