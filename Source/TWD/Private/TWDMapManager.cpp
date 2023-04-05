#include "TWDMapManager.h"

class UTWDSaveGame;

void UTWDMapManager::UnlockAllNodes() {
}

void UTWDMapManager::UnlockAdjacentNodes() {
}

bool UTWDMapManager::TravelToTerritory(EMapTerritoryNodeType Territory, bool bAdvanceTimeOfDay) {
    return false;
}

bool UTWDMapManager::TravelToNode(int32 NodeIndex, bool bAdvanceTimeOfDay) {
    return false;
}

void UTWDMapManager::TravelToMap(FName MapName) {
}

void UTWDMapManager::SetupInitialSaveGameData(UTWDSaveGame* NewSaveGame) {
}

void UTWDMapManager::SetTimeOfDay(ETWDTimeOfDay inTimeOfDay) {
}

void UTWDMapManager::SetNodeExplorationStatus(int32 NodeIndex, EMapTerritoryNodeStatus NewStatus) {
}

void UTWDMapManager::SetCurrentNode(int32 NewNodeIndex) {
}

TSet<EMapTerritoryNodeType> UTWDMapManager::SetAllLockedNodeOverrides() {
    return TSet<EMapTerritoryNodeType>();
}

void UTWDMapManager::SaveMapDataToGameProgression(UTWDSaveGame* SaveGame) {
}

void UTWDMapManager::RemoveAttributeOnNodeByType(EMapTerritoryNodeType NodeType, ETWDWorldEventType AttributeType) {
}

void UTWDMapManager::RemoveAttributeOnNode(int32 NodeIndex, ETWDWorldEventType AttributeType) {
}

void UTWDMapManager::LoadFromSaveData(UTWDSaveGame* SaveGame) {
}

bool UTWDMapManager::IsNightLevel() const {
    return false;
}

bool UTWDMapManager::IsInHubLevel() const {
    return false;
}

bool UTWDMapManager::HandleNodeClickedEvent(int32 NodeIndex) {
    return false;
}

bool UTWDMapManager::HandleHubClickedEvent() {
    return false;
}

FName UTWDMapManager::GetUMAPName(EMapTerritoryNodeType MapEnum) const {
    return NAME_None;
}

ETWDTimeOfDay UTWDMapManager::GetTimeOfDay() const {
    return ETWDTimeOfDay::Morning;
}

EMapTerritoryNodeType UTWDMapManager::GetTerritoryTypeByName(FName MapName) const {
    return EMapTerritoryNodeType::None;
}

EMapTerritoryNodeType UTWDMapManager::GetTerritoryTypeByIndex(int32 NodeIndex) {
    return EMapTerritoryNodeType::None;
}

int32 UTWDMapManager::GetTerritoryIndexByType(EMapTerritoryNodeType NodeType) {
    return 0;
}

EMapTerritoryNodeStatus UTWDMapManager::GetNodeExplorationStatus(int32 NodeIndex) {
    return EMapTerritoryNodeStatus::Locked;
}

FText UTWDMapManager::GetMapDisplayNameByHint(const FString& LevelName) const {
    return FText::GetEmpty();
}

FText UTWDMapManager::GetMapDisplayName(FName LevelName) const {
    return FText::GetEmpty();
}

FName UTWDMapManager::GetLightScenarioName() const {
    return NAME_None;
}

TArray<FName> UTWDMapManager::GetLightingScenarioOverlayNames(bool bNighttime, bool bOverrun) const {
    return TArray<FName>();
}

EMapTerritoryNodeType UTWDMapManager::GetCurrentMapTerritoryType() const {
    return EMapTerritoryNodeType::None;
}

TArray<FMapTerritoryAttribute> UTWDMapManager::GetAttributesOfNode(int32 NodeIndex) {
    return TArray<FMapTerritoryAttribute>();
}

bool UTWDMapManager::CanPlayerTravelToNode(int32 NodeIndex) {
    return false;
}

void UTWDMapManager::ApplyGammaForNode(bool bNighttime, bool bOverrun, int32 NodeIndex) const {
}

void UTWDMapManager::ApplyGammaForLevel(bool bNighttime, bool bOverrun, FName& LevelName) {
}

void UTWDMapManager::ApplyGamma(bool bNighttime, bool bOverrun) const {
}

void UTWDMapManager::AdvanceMapValuesByOneDay() {
}

void UTWDMapManager::AddAttributesToNodeByType(EMapTerritoryNodeType NodeType, TArray<FMapTerritoryAttribute> NewAttributes) {
}

void UTWDMapManager::AddAttributesToNode(int32 NodeIndex, TArray<FMapTerritoryAttribute> NewAttributes) {
}

UTWDMapManager::UTWDMapManager() {
    this->CurrentNode = -1;
    this->PreviousNode = -1;
    this->IsMapInitialized = false;
    this->HubDataAsset = NULL;
    this->PrologueDataAsset = NULL;
    this->TutorialDataAsset = NULL;
}

