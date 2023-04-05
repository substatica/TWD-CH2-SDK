#include "TWDGameProgression.h"
#include "Templates/SubclassOf.h"

class UTWDRecipe;
class AActor;
class UTWDScenarioManager;
class ASDIInventoryActor;
class ATWDPlayerState;
class UTWDTask;
class UTWDSaveGame;
class UTWDExileOrderEvent;
class UTWDPlayerBuffManager;
class UTWDMapManager;
class UTWDFavorManager;
class UTWDCraftingTableProgression;
class UTWDWorldEvent;


void UTWDGameProgression::UpdatePlayerSicknessContext() {
}

void UTWDGameProgression::UpdateInitialSaveGamePlayTime() {
}

bool UTWDGameProgression::UntrackRecipe(TSoftClassPtr<UTWDRecipe> RecipeClass) {
    return false;
}

void UTWDGameProgression::UnlockStoryAchievementRepairFirstPump() {
}

void UTWDGameProgression::UnlockStoryAchievementMeetMay() {
}

void UTWDGameProgression::UnlockStoryAchievementMeetJB() {
}

void UTWDGameProgression::UnlockStoryAchievementMeetGeorgia() {
}

void UTWDGameProgression::UnlockStoryAchievementMayFate() {
}

void UTWDGameProgression::UnlockStoryAchievementGetReserveKey() {
}

void UTWDGameProgression::UnlockStoryAchievementFindAmbreDrawing() {
}

void UTWDGameProgression::UnlockStoryAchievementContactCasey() {
}

void UTWDGameProgression::UnlockStoryAchievementCaseyFate() {
}

void UTWDGameProgression::UnlockRecipe(TSubclassOf<AActor> ItemType) {
}

void UTWDGameProgression::TryUnlockExileOrderAchievements() {
}

bool UTWDGameProgression::TryGetLegacyContextString(const FString& ContextKey, FString& OutValue) const {
    return false;
}

bool UTWDGameProgression::TryGetLegacyContextInt(const FString& ContextKey, int32& OutValue) const {
    return false;
}

bool UTWDGameProgression::TryGetLegacyContextFloat(const FString& ContextKey, float& OutValue) const {
    return false;
}

bool UTWDGameProgression::TryGetLegacyContextBool(const FString& ContextKey, bool& OutValue) const {
    return false;
}

bool UTWDGameProgression::TryAwardMasterOfTheCraftAchievement() {
    return false;
}

void UTWDGameProgression::TrackRecipe(TSoftClassPtr<UTWDRecipe> RecipeClass) {
}

bool UTWDGameProgression::TowerPresenceTierChanged() const {
    return false;
}

void UTWDGameProgression::SetWaveModeRulesIndex(const int32 NewIndex) {
}

void UTWDGameProgression::SetUseImportedSave(bool InUseImportedSave) {
}

void UTWDGameProgression::SetTimeOfDay(ETWDTimeOfDay TimeOfDay) {
}

void UTWDGameProgression::SetStoryProgressionValue(int32 ProgressionValue) {
}

void UTWDGameProgression::SetShouldStartInTutorial(bool bInShouldStartInTutorial) {
}

void UTWDGameProgression::SetSaveGameInvalidForAchievements() {
}

void UTWDGameProgression::SetSavedTimeOfDay(ETWDTimeOfDay TimeOfDay, bool bUpdateMapManager) {
}

void UTWDGameProgression::SetRandomSeed(int32 InitialSeed) {
}

void UTWDGameProgression::SetProgressionMode(EProgressionMode Mode) {
}

void UTWDGameProgression::SetPlayerHasCompletedTutorial(bool bCompleted) {
}

void UTWDGameProgression::SetPlayerCustomizationInfo(const FTWDPlayerCustomizationInfo PlayerInfo) {
}

void UTWDGameProgression::SetPersistentLevelData(const FString& SaveKey, FTWDPersistentLevelSaveData& LevelData) {
}

void UTWDGameProgression::SetNumberOfPillowsInBus(int32 NumPillows) {
}

void UTWDGameProgression::SetNumberOfDemonStatuesInBus(int32 NumDemons) {
}

void UTWDGameProgression::SetNumberOfAngelStatuesInBus(int32 NumAngels) {
}

void UTWDGameProgression::SetNotebookSection(uint8 CurrentSection) {
}

void UTWDGameProgression::SetNightTravelEnabled(bool bEnable) {
}

void UTWDGameProgression::SetMapLocationIdentifier(FName NewIdentifier) {
}

void UTWDGameProgression::SetDifficultyMode(const ETWDDifficultyMode NewMode) {
}

void UTWDGameProgression::SetCurrentMapName(FName NewMapName, bool bResetIdentifier) const {
}

void UTWDGameProgression::SetCurrentDay(int32 Day, bool bUseChapterOffset) {
}

void UTWDGameProgression::SetConversationProgress(EQuestLine Questline, int32 NewValue) {
}

void UTWDGameProgression::SetContextString(const FString& ContextKey, const FString& StringValue) {
}

void UTWDGameProgression::SetContextInt(const FString& ContextKey, int32 IntValue) {
}

void UTWDGameProgression::SetContextFloat(const FString& ContextKey, float FloatValue) {
}

void UTWDGameProgression::SetContextBool(const FString& ContextKey, bool BoolValue) {
}

void UTWDGameProgression::SaveStashItems(const TArray<FTWDSavedInventoryItemData> inStashItems) {
}

void UTWDGameProgression::SavePlayerState(ATWDPlayerState* PlayerState) {
}

void UTWDGameProgression::SaveInventoryItems(const TArray<FTWDSavedInventoryItemData> inInventoryItems) {
}

void UTWDGameProgression::ResolveImportedSaveMerge() {
}

void UTWDGameProgression::RemoveTask(TSubclassOf<UTWDTask> Task) {
}

void UTWDGameProgression::RemoveSuspendedLevelSaveContext(const FString& SaveContext) {
}

void UTWDGameProgression::RemoveNoteFromNotebook(const TSubclassOf<ASDIInventoryActor> Note) {
}

void UTWDGameProgression::PrintValidationLog(const TArray<FString>& StringsToPrint) {
}

UTWDSaveGame* UTWDGameProgression::PrepareSaveGame(bool bCreateUniqueSaveObject) {
    return NULL;
}

void UTWDGameProgression::NativeValidateGameProgression() {
}

void UTWDGameProgression::LogStacks(const FString& DescriptionMessage) const {
}

TArray<FTWDSavedInventoryItemData> UTWDGameProgression::LoadStashItems() const {
    return TArray<FTWDSavedInventoryItemData>();
}

TArray<FTWDSavedInventoryItemData> UTWDGameProgression::LoadInventoryItems() const {
    return TArray<FTWDSavedInventoryItemData>();
}

void UTWDGameProgression::LoadFromSaveGame(UTWDSaveGame* NewSaveGame, bool bIsNewGame, bool bIsStartup) {
}

bool UTWDGameProgression::IsTrackingMaterial(FGuid MaterialGuid, TSubclassOf<UTWDRecipe>& OutWhichRecipe) const {
    return false;
}

bool UTWDGameProgression::IsTrackingInventory(const ASDIInventoryActor* InvActor, TSubclassOf<UTWDRecipe>& OutWhichRecipe) const {
    return false;
}

bool UTWDGameProgression::IsSaveGameValidForAchievements() const {
    return false;
}

bool UTWDGameProgression::IsNightTravelEnabled() const {
    return false;
}

bool UTWDGameProgression::IsNightLevel() const {
    return false;
}

bool UTWDGameProgression::IsInventoryInActiveExileOrder(const ASDIInventoryActor* InvActor, UTWDExileOrderEvent*& RequiredByOrderEvent) const {
    return false;
}

bool UTWDGameProgression::IsInventoryClassInActiveExileOrder(TSubclassOf<ASDIInventoryActor> InvClass, UTWDExileOrderEvent*& RequiredByOrderEvent) const {
    return false;
}

bool UTWDGameProgression::IsInActivePersistentLevel() const {
    return false;
}

bool UTWDGameProgression::IsChapterTwoEnabled() const {
    return false;
}

void UTWDGameProgression::InitializePlayerState(ATWDPlayerState* PlayerState) {
}

void UTWDGameProgression::IncrementNumberOfWalkersKilledWithSMG() {
}

void UTWDGameProgression::IncrementNumberOfWalkersKilledWithSawedOff() {
}

void UTWDGameProgression::IncrementNumberOfWalkersKilledWithSapGloves() {
}

void UTWDGameProgression::IncrementNumberOfUndeadEradicatorsKilled() {
}

void UTWDGameProgression::IncrementNumberOfTwinkiesEaten() {
}

void UTWDGameProgression::IncrementNumberOfTowerSoldiersKilled() {
}

void UTWDGameProgression::IncrementNumberOfTimesUsedGutsMode() {
}

void UTWDGameProgression::IncrementNumberOfTimesGivenItemToBeggar() {
}

void UTWDGameProgression::IncrementNumberOfSurvivalTableItemsCrafted(TSubclassOf<AActor> ItemType) {
}

void UTWDGameProgression::IncrementNumberOfRetributionsAchievements() {
}

void UTWDGameProgression::IncrementNumberOfNightItemsScavenged() {
}

void UTWDGameProgression::IncrementNumberOfMedicineItemsCrafted(TSubclassOf<AActor> ItemType) {
}

void UTWDGameProgression::IncrementNumberOfLowQualityFoodEaten() {
}

void UTWDGameProgression::IncrementNumberOfLivingEradicatorsKilled() {
}

void UTWDGameProgression::IncrementNumberOfLaserSightHeadshots() {
}

void UTWDGameProgression::IncrementNumberOfKillsWithPropaneTankExplosion() {
}

void UTWDGameProgression::IncrementNumberOfKillsOfUnawareEnemy() {
}

void UTWDGameProgression::IncrementNumberOfKilledHumans() {
}

void UTWDGameProgression::IncrementNumberOfHumansKilledWithSapGloves() {
}

void UTWDGameProgression::IncrementNumberOfHumansKilledWithGrenadeLauncher() {
}

void UTWDGameProgression::IncrementNumberOfHumansKilledWithEsteemedMortal() {
}

void UTWDGameProgression::IncrementNumberOfHumansKilledWithElephantGun() {
}

void UTWDGameProgression::IncrementNumberOfGunTableItemsCrafted(TSubclassOf<AActor> ItemType) {
}

void UTWDGameProgression::IncrementNumberOfGrapplesStarted() {
}

void UTWDGameProgression::IncrementNumberOfGearTableItemsCrafted(TSubclassOf<AActor> ItemType) {
}

void UTWDGameProgression::IncrementNumberOfFoodItemsCrafted(TSubclassOf<AActor> FoodType) {
}

void UTWDGameProgression::IncrementNumberOfFoodItemsConsumed(TSubclassOf<AActor> FoodType) {
}

void UTWDGameProgression::IncrementNumberOfEnemiesKilledWithSilencedWeaponsUndetected() {
}

void UTWDGameProgression::IncrementNumberOfEnemiesKilledWithGrenadeLauncher() {
}

void UTWDGameProgression::IncrementNumberOfEnemiesKilledWithChainsaw() {
}

void UTWDGameProgression::IncrementNumberOfDissidentsKilled() {
}

void UTWDGameProgression::IncrementNumberOfBrainedWalkerWithSpikedBat() {
}

void UTWDGameProgression::IncrementNumberOfBrainedWalkerWithScrewDriver() {
}

void UTWDGameProgression::IncrementNumberOfBrainedWalkers() {
}

void UTWDGameProgression::IncrementNumberOfBrainedEliteWalkerWithAxe() {
}

void UTWDGameProgression::IncrementNumberOfBackpackItemsScavenged() {
}

void UTWDGameProgression::IncrementDistanceClimbed(float Delta) {
}

int32 UTWDGameProgression::IncrementConversationProgress(EQuestLine Questline, int32 Increment) {
    return 0;
}

bool UTWDGameProgression::HasTask(TSubclassOf<UTWDTask> Task) {
    return false;
}

bool UTWDGameProgression::HasPlayerResolvedTask(TSubclassOf<UTWDTask> TaskToCheck) {
    return false;
}

bool UTWDGameProgression::HasPlayerCompletedTutorial() const {
    return false;
}

bool UTWDGameProgression::HasNoteInNotebook(const TSubclassOf<ASDIInventoryActor> Note) const {
    return false;
}

int32 UTWDGameProgression::GetWaveModeRulesIndex() const {
    return 0;
}

TArray<UTWDExileOrderEvent*> UTWDGameProgression::GetUnassignedExileOrderEvents() const {
    return TArray<UTWDExileOrderEvent*>();
}

TArray<TSoftClassPtr<UTWDRecipe>> UTWDGameProgression::GetTrackedRecipes() const {
    return TArray<TSoftClassPtr<UTWDRecipe>>();
}

ETWDTimeOfDay UTWDGameProgression::GetTimeOfDay() const {
    return ETWDTimeOfDay::Morning;
}

TArray<UTWDTask*> UTWDGameProgression::GetTasks() const {
    return TArray<UTWDTask*>();
}

UTWDTask* UTWDGameProgression::GetTask(TSubclassOf<UTWDTask> Task) {
    return NULL;
}

int32 UTWDGameProgression::GetStoryProgressionValue() const {
    return 0;
}

UTWDScenarioManager* UTWDGameProgression::GetScenarioManager() const {
    return NULL;
}

UTWDSaveGame* UTWDGameProgression::GetSaveGame() {
    return NULL;
}

EProgressionMode UTWDGameProgression::GetProgressionMode() {
    return EProgressionMode::EPM_Story;
}

int32 UTWDGameProgression::GetPreviousTowerPresenceTier() const {
    return 0;
}

float UTWDGameProgression::GetPlayerSicknessStaminaMultiplier() const {
    return 0.0f;
}

float UTWDGameProgression::GetPlayerSickness() const {
    return 0.0f;
}

FTWDPlayerCustomizationInfo UTWDGameProgression::GetPlayerCustomizationInfo() const {
    return FTWDPlayerCustomizationInfo{};
}

UTWDPlayerBuffManager* UTWDGameProgression::GetPlayerBuffManager() const {
    return NULL;
}

bool UTWDGameProgression::GetPersistentLevelData(const FString& SaveKey, FTWDPersistentLevelSaveData& LevelData) {
    return false;
}

uint8 UTWDGameProgression::GetNotebookSection() {
    return 0;
}

UTWDMapManager* UTWDGameProgression::GetMapManager() const {
    return NULL;
}

FName UTWDGameProgression::GetMapLocationIdentifier() const {
    return NAME_None;
}

FRandomStream UTWDGameProgression::GetMapInitStream(EMapTerritoryNodeType MapEnum) {
    return FRandomStream{};
}

float UTWDGameProgression::GetInitialSaveGamePlayTime() {
    return 0.0f;
}

bool UTWDGameProgression::GetHubItemSerializationStringByGuid(FGuid uid, FString& OutString) {
    return false;
}

bool UTWDGameProgression::GetHubItemDataByGuid(FGuid uid, FTWDPersistentLevelItemData& OutItemData) {
    return false;
}

UTWDFavorManager* UTWDGameProgression::GetFavorManager() const {
    return NULL;
}

UTWDExileOrderEvent* UTWDGameProgression::GetExileOrderEventForTerritory(EMapTerritoryNodeType Territory) const {
    return NULL;
}

ETWDDifficultyMode UTWDGameProgression::GetDifficultyMode() const {
    return ETWDDifficultyMode::ETWDDifficulty_Low;
}

int32 UTWDGameProgression::GetCurrentTowerPresenceTier() const {
    return 0;
}

FName UTWDGameProgression::GetCurrentMapName() const {
    return NAME_None;
}

int32 UTWDGameProgression::GetCurrentLevelFavorTierDifficultyRating() const {
    return 0;
}

UTWDExileOrderEvent* UTWDGameProgression::GetCurrentLevelExileOrderEvent() const {
    return NULL;
}

UTWDExileOrderEvent* UTWDGameProgression::GetCurrentLevelAssignedExileOrderEvent() const {
    return NULL;
}

float UTWDGameProgression::GetCurrentDayPercentage() const {
    return 0.0f;
}

int32 UTWDGameProgression::GetCurrentDay(bool bUseChapterOffset) const {
    return 0;
}

UTWDCraftingTableProgression* UTWDGameProgression::GetCraftingTableProgression(TSoftClassPtr<AActor> CraftingTableBlueprint) const {
    return NULL;
}

int32 UTWDGameProgression::GetConversationProgress(EQuestLine Questline) const {
    return 0;
}

FString UTWDGameProgression::GetContextString(const FString& ContextKey) const {
    return TEXT("");
}

int32 UTWDGameProgression::GetContextInt(const FString& ContextKey) const {
    return 0;
}

float UTWDGameProgression::GetContextFloat(const FString& ContextKey) const {
    return 0.0f;
}

bool UTWDGameProgression::GetContextBool(const FString& ContextKey) const {
    return false;
}

TArray<TSoftClassPtr<UTWDWorldEvent>> UTWDGameProgression::GetCompletedStoryEvents() const {
    return TArray<TSoftClassPtr<UTWDWorldEvent>>();
}

FTWDGameProgressionChapterProperties UTWDGameProgression::GetChapterProperties() const {
    return FTWDGameProgressionChapterProperties{};
}

UTWDMapManager* UTWDGameProgression::GetChapterOneMapManager() const {
    return NULL;
}

TArray<UTWDExileOrderEvent*> UTWDGameProgression::GetAssignedExileOrderEvents() const {
    return TArray<UTWDExileOrderEvent*>();
}

UTWDExileOrderEvent* UTWDGameProgression::GetAssignedExileOrderEventForTerritory(EMapTerritoryNodeType Territory) const {
    return NULL;
}

TArray<FSavedLookatNotebookData> UTWDGameProgression::GetAllSavedNotebookNoteData() const {
    return TArray<FSavedLookatNotebookData>();
}

FRandomStream UTWDGameProgression::GetActiveStream() {
    return FRandomStream{};
}

TArray<UTWDExileOrderEvent*> UTWDGameProgression::GetActiveExileOrderEvents() const {
    return TArray<UTWDExileOrderEvent*>();
}

void UTWDGameProgression::DebugSavePersistentItems() {
}

void UTWDGameProgression::DebugLoadPersistentItems() {
}

UTWDSaveGame* UTWDGameProgression::CreateNewSaveGameObject() {
    return NULL;
}

void UTWDGameProgression::ClearProgressionData() {
}

void UTWDGameProgression::CheckPoint(bool bBeforeThisMoment) {
}

bool UTWDGameProgression::CheckOnlineItemAlreadyAwarded(const FName& OnlineEntitlementName) const {
    return false;
}

void UTWDGameProgression::AwardOnlineItem(const FName& OnlineEntitlementName) {
}

bool UTWDGameProgression::AssignActiveExileOrderEvent(UTWDExileOrderEvent* OrderEvent) {
    return false;
}

bool UTWDGameProgression::AreTaskDependenciesCleared(TSubclassOf<UTWDTask> Task) {
    return false;
}

float UTWDGameProgression::AlterPlayerSickness(float Delta, ESicknessSourceType SourceType) {
    return 0.0f;
}

void UTWDGameProgression::AdvanceStoryProgressionValue(TSoftClassPtr<UTWDWorldEvent> CompletedEventClass) {
}

int32 UTWDGameProgression::AdvanceDay() {
    return 0;
}

void UTWDGameProgression::AddVisitedMap(FName MapName) {
}

void UTWDGameProgression::AddTask(UTWDTask* Task) {
}

void UTWDGameProgression::AddSuspendedLevelSaveContext(const FString& SaveContext) {
}

void UTWDGameProgression::AddStashItem(const TSubclassOf<ASDIInventoryActor> ItemClass, int32 quantity, uint8 SlotIndex) {
}

void UTWDGameProgression::AddResolvedTask(TSubclassOf<UTWDTask> ResolvedTask) {
}

void UTWDGameProgression::AddNoteToNotebook(FSavedLookatNotebookData& SavedNoteData) {
}

void UTWDGameProgression::AddMapWithExileLeaderKill() {
}

void UTWDGameProgression::AddInventoryItem(const TSubclassOf<ASDIInventoryActor> ItemClass, int32 quantity, uint8 SlotIndex) {
}

void UTWDGameProgression::AddExcludedActorToSuspendedLevel(AActor* ActorToExclude) {
}

void UTWDGameProgression::AddCompletedStoryEvent(TSoftClassPtr<UTWDWorldEvent> EventClass) {
}

UTWDGameProgression::UTWDGameProgression() {
    this->SaveGame = NULL;
    this->WaveModeRulesIndex = -1;
    this->MapManager = NULL;
    this->ChapterOneMapManager = NULL;
    this->FavorManager = NULL;
    this->FavorManagerClass = NULL;
    this->ScenarioManager = NULL;
    this->MapInitStreamLastMap = EMapTerritoryNodeType::None;
    this->ProgressionMode = EProgressionMode::EPM_Story;
    this->InitialSaveGamePlayTime = 0.00f;
    this->PlayerBuffManager = NULL;
    this->PlayerBuffManagerClass = NULL;
    this->ActivePersistentLevel = NULL;
    this->ActiveSuspendableLevel = NULL;
    this->BalancedGameLength = 16;
    this->TotalStoryEvents = 10;
    this->StoryEventWeight = 5.00f;
    this->QuestLineContextKeys[0] = TEXT("MayConvValue");
    this->QuestLineContextKeys[1] = TEXT("MayConvValue");
    this->QuestLineContextKeys[2] = TEXT("MayConvValue");
    this->QuestLineContextKeys[3] = TEXT("MayConvValue");
    this->UseImportedSave = false;
    this->ShouldStartInTutorial = false;
    this->GameActivityStates = EGameActivityState::Hidden;
}

