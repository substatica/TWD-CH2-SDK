#pragma once
#include "CoreMinimal.h"
#include "MapBiomeTerritorySet.h"
#include "MapTerritoryNode.h"
#include "UObject/Object.h"
#include "MapInitializationCompleteDelegate.h"
#include "MapNodeAttributesUpdatedDelegate.h"
#include "MapNodeExplorationStatusUpdatedDelegate.h"
#include "MapNodeClickedDelegate.h"
#include "EMapTerritoryNodeType.h"
#include "MapTimeOfDayChangedDelegate.h"
#include "ETWDWorldEventType.h"
#include "EMapBiomeType.h"
#include "ETWDTimeOfDay.h"
#include "EMapTerritoryNodeStatus.h"
#include "MapTerritoryAttribute.h"
#include "TWDMapManager.generated.h"

class UMapTerritoryDataAsset;
class UMapAttributeDataAsset;
class UTWDSaveGame;

UCLASS(BlueprintType)
class TWD_API UTWDMapManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FMapInitializationComplete OnMapInitializationComplete;
    
    UPROPERTY(BlueprintAssignable)
    FMapNodeAttributesUpdated OnMapNodeAttributesUpdated;
    
    UPROPERTY(BlueprintAssignable)
    FMapNodeExplorationStatusUpdated OnMapNodeExplorationStatusUpdated;
    
    UPROPERTY(BlueprintAssignable)
    FMapNodeClicked OnMapNodeClicked;
    
    UPROPERTY(BlueprintAssignable)
    FMapTimeOfDayChanged OnTimeOfDayChanged;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    int32 CurrentNode;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    int32 PreviousNode;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool IsMapInitialized;
    
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TArray<FMapTerritoryNode> MapNodes;
    
    UPROPERTY(BlueprintReadWrite)
    TSet<EMapTerritoryNodeType> LockedNodeOverrides;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UMapTerritoryDataAsset* HubDataAsset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UMapTerritoryDataAsset* PrologueDataAsset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UMapTerritoryDataAsset* TutorialDataAsset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<EMapTerritoryNodeType, UMapTerritoryDataAsset*> TerritoryNodeDataMapping;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<ETWDWorldEventType, UMapAttributeDataAsset*> AttributeDataMapping;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<EMapBiomeType, FMapBiomeTerritorySet> TerritoriesPerBiomeMapping;
    
public:
    UTWDMapManager();
    UFUNCTION(BlueprintCallable)
    void UnlockAllNodes();
    
    UFUNCTION(BlueprintCallable)
    void UnlockAdjacentNodes();
    
    UFUNCTION(BlueprintCallable)
    bool TravelToTerritory(EMapTerritoryNodeType Territory, bool bAdvanceTimeOfDay);
    
    UFUNCTION(BlueprintCallable)
    bool TravelToNode(int32 NodeIndex, bool bAdvanceTimeOfDay);
    
    UFUNCTION(BlueprintCallable)
    void TravelToMap(FName MapName);
    
    UFUNCTION()
    void SetupInitialSaveGameData(UTWDSaveGame* NewSaveGame);
    
    UFUNCTION(BlueprintCallable)
    void SetTimeOfDay(ETWDTimeOfDay inTimeOfDay);
    
    UFUNCTION(BlueprintCallable)
    void SetNodeExplorationStatus(int32 NodeIndex, EMapTerritoryNodeStatus NewStatus);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentNode(int32 NewNodeIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    TSet<EMapTerritoryNodeType> SetAllLockedNodeOverrides();
    
public:
    UFUNCTION()
    void SaveMapDataToGameProgression(UTWDSaveGame* SaveGame);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAttributeOnNodeByType(EMapTerritoryNodeType NodeType, ETWDWorldEventType AttributeType);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAttributeOnNode(int32 NodeIndex, ETWDWorldEventType AttributeType);
    
    UFUNCTION()
    void LoadFromSaveData(UTWDSaveGame* SaveGame);
    
    UFUNCTION(BlueprintPure)
    bool IsNightLevel() const;
    
    UFUNCTION(BlueprintPure)
    bool IsInHubLevel() const;
    
    UFUNCTION(BlueprintCallable)
    bool HandleNodeClickedEvent(int32 NodeIndex);
    
    UFUNCTION(BlueprintCallable)
    bool HandleHubClickedEvent();
    
    UFUNCTION(BlueprintPure)
    FName GetUMAPName(EMapTerritoryNodeType MapEnum) const;
    
    UFUNCTION(BlueprintPure)
    ETWDTimeOfDay GetTimeOfDay() const;
    
    UFUNCTION(BlueprintPure)
    EMapTerritoryNodeType GetTerritoryTypeByName(FName MapName) const;
    
    UFUNCTION(BlueprintPure)
    EMapTerritoryNodeType GetTerritoryTypeByIndex(int32 NodeIndex);
    
    UFUNCTION(BlueprintPure)
    int32 GetTerritoryIndexByType(EMapTerritoryNodeType NodeType);
    
    UFUNCTION(BlueprintPure)
    EMapTerritoryNodeStatus GetNodeExplorationStatus(int32 NodeIndex);
    
    UFUNCTION(BlueprintPure)
    FText GetMapDisplayNameByHint(const FString& LevelName) const;
    
    UFUNCTION(BlueprintPure)
    FText GetMapDisplayName(FName LevelName) const;
    
    UFUNCTION()
    FName GetLightScenarioName() const;
    
    UFUNCTION()
    TArray<FName> GetLightingScenarioOverlayNames(bool bNighttime, bool bOverrun) const;
    
    UFUNCTION(BlueprintPure)
    EMapTerritoryNodeType GetCurrentMapTerritoryType() const;
    
    UFUNCTION(BlueprintPure)
    TArray<FMapTerritoryAttribute> GetAttributesOfNode(int32 NodeIndex);
    
    UFUNCTION(BlueprintCallable)
    bool CanPlayerTravelToNode(int32 NodeIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ApplyGammaForNode(bool bNighttime, bool bOverrun, int32 NodeIndex) const;
    
    UFUNCTION()
    void ApplyGammaForLevel(bool bNighttime, bool bOverrun, FName& LevelName);
    
    UFUNCTION()
    void ApplyGamma(bool bNighttime, bool bOverrun) const;
    
    UFUNCTION()
    void AdvanceMapValuesByOneDay();
    
    UFUNCTION(BlueprintCallable)
    void AddAttributesToNodeByType(EMapTerritoryNodeType NodeType, TArray<FMapTerritoryAttribute> NewAttributes);
    
    UFUNCTION(BlueprintCallable)
    void AddAttributesToNode(int32 NodeIndex, TArray<FMapTerritoryAttribute> NewAttributes);
    
};

