#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "EMapTerritoryNodeType.h"
#include "TWDDifficultyMods.h"
#include "TWDGameProgressionChapterProperties.h"
#include "EProgressionMode.h"
#include "UObject/NoExportTypes.h"
#include "TWDPlayerSicknessInfo.h"
#include "TWDGameProgression_OnPlayerGainedSicknessDelegateDelegate.h"
#include "TWDGameProgression_SuspendedLoadDelegate.h"
#include "ETWDDifficultyMode.h"
#include "ETWDTimeOfDay.h"
#include "TWDAchievementData.h"
#include "TWDPersistentLevelSaveData.h"
#include "EGameActivityState.h"
#include "TWDPlayerCustomizationInfo.h"
#include "EQuestLine.h"
#include "TWDSavedInventoryItemData.h"
#include "UObject/NoExportTypes.h"
#include "TWDPersistentLevelItemData.h"
#include "SavedLookatNotebookData.h"
#include "ESicknessSourceType.h"
#include "TWDGameProgression.generated.h"

class UTWDFavorManager;
class UTWDMapManager;
class UTWDSaveGame;
class UTWDScenarioManager;
class UTWDTask;
class UTWDPlayerBuffManager;
class ATWDPersistentLevel;
class AActor;
class ATWDSuspendableLevel;
class UTWDCraftingTableProgression;
class UTWDWorldEvent;
class UTWDRecipe;
class ASDIInventoryActor;
class ATWDPlayerState;
class UTWDExileOrderEvent;

UCLASS(Blueprintable)
class TWD_API UTWDGameProgression : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    UTWDSaveGame* SaveGame;
    
    UPROPERTY(Transient)
    int32 WaveModeRulesIndex;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    FTWDGameProgressionChapterProperties ChapterOneProperties;
    
    UPROPERTY(EditDefaultsOnly)
    FTWDGameProgressionChapterProperties ChapterTwoProperties;
    
    UPROPERTY(Transient)
    UTWDMapManager* MapManager;
    
    UPROPERTY(Transient)
    UTWDMapManager* ChapterOneMapManager;
    
    UPROPERTY(Transient)
    UTWDFavorManager* FavorManager;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<UTWDFavorManager> FavorManagerClass;
    
    UPROPERTY(Transient)
    UTWDScenarioManager* ScenarioManager;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<TSubclassOf<UTWDTask>, TSubclassOf<UTWDTask>> TaskDependencies;
    
    UPROPERTY()
    FRandomStream RandomStream;
    
    UPROPERTY()
    FRandomStream MapInitStream;
    
    UPROPERTY()
    EMapTerritoryNodeType MapInitStreamLastMap;
    
    UPROPERTY()
    EProgressionMode ProgressionMode;
    
    UPROPERTY(Transient)
    float InitialSaveGamePlayTime;
    
    UPROPERTY(Transient)
    UTWDPlayerBuffManager* PlayerBuffManager;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<UTWDPlayerBuffManager> PlayerBuffManagerClass;
    
    UPROPERTY(Transient)
    FTWDPlayerSicknessInfo PlayerSicknessInfo;
    
    UPROPERTY(BlueprintAssignable)
    FTWDGameProgression_OnPlayerGainedSicknessDelegate OnPlayerGainedSickness;
    
public:
    UPROPERTY()
    ATWDPersistentLevel* ActivePersistentLevel;
    
    UPROPERTY()
    ATWDSuspendableLevel* ActiveSuspendableLevel;
    
    UPROPERTY(BlueprintAssignable)
    FTWDGameProgression_SuspendedLoad SuspendedGameLoaded;
    
    UPROPERTY(EditAnywhere, Instanced)
    TArray<UTWDCraftingTableProgression*> CraftingTableProgressions;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UTWDWorldEvent>> NewGameWorldEvents;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 BalancedGameLength;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    int32 TotalStoryEvents;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float StoryEventWeight;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<ETWDDifficultyMode, FTWDDifficultyMods> DifficultyMods;
    
    UPROPERTY()
    FString QuestLineContextKeys[4];
    
    UPROPERTY(BlueprintReadOnly)
    bool UseImportedSave;
    
    UPROPERTY(BlueprintReadOnly)
    bool ShouldStartInTutorial;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FTWDAchievementData AchievementRequirements;
    
    UPROPERTY()
    EGameActivityState GameActivityStates;
    
    UTWDGameProgression();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ValidateGameProgression();
    
    UFUNCTION()
    void UpdatePlayerSicknessContext();
    
    UFUNCTION()
    void UpdateInitialSaveGamePlayTime();
    
    UFUNCTION(BlueprintCallable)
    bool UntrackRecipe(TSoftClassPtr<UTWDRecipe> RecipeClass);
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementRepairFirstPump();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementMeetMay();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementMeetJB();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementMeetGeorgia();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementMayFate();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementGetReserveKey();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementFindAmbreDrawing();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementContactCasey();
    
    UFUNCTION(BlueprintCallable)
    void UnlockStoryAchievementCaseyFate();
    
    UFUNCTION(BlueprintCallable)
    void UnlockRecipe(TSubclassOf<AActor> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void TryUnlockExileOrderAchievements();
    
protected:
    UFUNCTION(BlueprintPure)
    bool TryGetLegacyContextString(const FString& ContextKey, FString& OutValue) const;
    
    UFUNCTION(BlueprintPure)
    bool TryGetLegacyContextInt(const FString& ContextKey, int32& OutValue) const;
    
    UFUNCTION(BlueprintPure)
    bool TryGetLegacyContextFloat(const FString& ContextKey, float& OutValue) const;
    
    UFUNCTION(BlueprintPure)
    bool TryGetLegacyContextBool(const FString& ContextKey, bool& OutValue) const;
    
public:
    UFUNCTION(BlueprintCallable)
    bool TryAwardMasterOfTheCraftAchievement();
    
    UFUNCTION(BlueprintCallable)
    void TrackRecipe(TSoftClassPtr<UTWDRecipe> RecipeClass);
    
    UFUNCTION(BlueprintPure)
    bool TowerPresenceTierChanged() const;
    
    UFUNCTION(BlueprintCallable)
    void SetWaveModeRulesIndex(const int32 NewIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetUseImportedSave(bool InUseImportedSave);
    
    UFUNCTION(BlueprintCallable)
    void SetTimeOfDay(ETWDTimeOfDay TimeOfDay);
    
    UFUNCTION(BlueprintCallable)
    void SetStoryProgressionValue(int32 ProgressionValue);
    
    UFUNCTION(BlueprintCallable)
    void SetShouldStartInTutorial(bool bInShouldStartInTutorial);
    
    UFUNCTION(BlueprintCallable)
    void SetSaveGameInvalidForAchievements();
    
    UFUNCTION(BlueprintCallable)
    void SetSavedTimeOfDay(ETWDTimeOfDay TimeOfDay, bool bUpdateMapManager);
    
    UFUNCTION()
    void SetRandomSeed(int32 InitialSeed);
    
    UFUNCTION(BlueprintCallable)
    void SetProgressionMode(EProgressionMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerHasCompletedTutorial(bool bCompleted);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerCustomizationInfo(const FTWDPlayerCustomizationInfo PlayerInfo);
    
    UFUNCTION()
    void SetPersistentLevelData(const FString& SaveKey, FTWDPersistentLevelSaveData& LevelData);
    
    UFUNCTION(BlueprintCallable)
    void SetNumberOfPillowsInBus(int32 NumPillows);
    
    UFUNCTION(BlueprintCallable)
    void SetNumberOfDemonStatuesInBus(int32 NumDemons);
    
    UFUNCTION(BlueprintCallable)
    void SetNumberOfAngelStatuesInBus(int32 NumAngels);
    
    UFUNCTION()
    void SetNotebookSection(uint8 CurrentSection);
    
    UFUNCTION(BlueprintCallable)
    void SetNightTravelEnabled(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetMapLocationIdentifier(FName NewIdentifier);
    
    UFUNCTION(BlueprintCallable)
    void SetDifficultyMode(const ETWDDifficultyMode NewMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetCurrentMapName(FName NewMapName, bool bResetIdentifier) const;
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentDay(int32 Day, bool bUseChapterOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetConversationProgress(EQuestLine Questline, int32 NewValue);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetContextString(const FString& ContextKey, const FString& StringValue);
    
    UFUNCTION(BlueprintCallable)
    void SetContextInt(const FString& ContextKey, int32 IntValue);
    
    UFUNCTION(BlueprintCallable)
    void SetContextFloat(const FString& ContextKey, float FloatValue);
    
    UFUNCTION(BlueprintCallable)
    void SetContextBool(const FString& ContextKey, bool BoolValue);
    
public:
    UFUNCTION(BlueprintCallable)
    void SaveStashItems(const TArray<FTWDSavedInventoryItemData> inStashItems);
    
    UFUNCTION()
    void SavePlayerState(ATWDPlayerState* PlayerState);
    
    UFUNCTION(BlueprintCallable)
    void SaveInventoryItems(const TArray<FTWDSavedInventoryItemData> inInventoryItems);
    
    UFUNCTION(BlueprintCallable)
    void ResolveImportedSaveMerge();
    
    UFUNCTION(BlueprintCallable)
    void RemoveTask(TSubclassOf<UTWDTask> Task);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSuspendedLevelSaveContext(const FString& SaveContext);
    
    UFUNCTION(BlueprintCallable)
    void RemoveNoteFromNotebook(const TSubclassOf<ASDIInventoryActor> Note);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PrintValidationLog(const TArray<FString>& StringsToPrint);
    
public:
    UFUNCTION()
    UTWDSaveGame* PrepareSaveGame(bool bCreateUniqueSaveObject);
    
    UFUNCTION()
    void NativeValidateGameProgression();
    
    UFUNCTION()
    void LogStacks(const FString& DescriptionMessage) const;
    
    UFUNCTION(BlueprintPure)
    TArray<FTWDSavedInventoryItemData> LoadStashItems() const;
    
    UFUNCTION(BlueprintPure)
    TArray<FTWDSavedInventoryItemData> LoadInventoryItems() const;
    
    UFUNCTION()
    void LoadFromSaveGame(UTWDSaveGame* NewSaveGame, bool bIsNewGame, bool bIsStartup);
    
    UFUNCTION(BlueprintPure)
    bool IsTrackingMaterial(FGuid MaterialGuid, TSubclassOf<UTWDRecipe>& OutWhichRecipe) const;
    
    UFUNCTION(BlueprintPure)
    bool IsTrackingInventory(const ASDIInventoryActor* InvActor, TSubclassOf<UTWDRecipe>& OutWhichRecipe) const;
    
    UFUNCTION(BlueprintPure)
    bool IsSaveGameValidForAchievements() const;
    
    UFUNCTION(BlueprintPure)
    bool IsNightTravelEnabled() const;
    
    UFUNCTION(BlueprintPure)
    bool IsNightLevel() const;
    
    UFUNCTION(BlueprintPure)
    bool IsInventoryInActiveExileOrder(const ASDIInventoryActor* InvActor, UTWDExileOrderEvent*& RequiredByOrderEvent) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInventoryClassInActiveExileOrder(TSubclassOf<ASDIInventoryActor> InvClass, UTWDExileOrderEvent*& RequiredByOrderEvent) const;
    
    UFUNCTION(BlueprintPure)
    bool IsInActivePersistentLevel() const;
    
    UFUNCTION(BlueprintPure)
    bool IsChapterTwoEnabled() const;
    
    UFUNCTION()
    void InitializePlayerState(ATWDPlayerState* PlayerState);
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfWalkersKilledWithSMG();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfWalkersKilledWithSawedOff();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfWalkersKilledWithSapGloves();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfUndeadEradicatorsKilled();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfTwinkiesEaten();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfTowerSoldiersKilled();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfTimesUsedGutsMode();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfTimesGivenItemToBeggar();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfSurvivalTableItemsCrafted(TSubclassOf<AActor> ItemType);
    
    UFUNCTION()
    void IncrementNumberOfRetributionsAchievements();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfNightItemsScavenged();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfMedicineItemsCrafted(TSubclassOf<AActor> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfLowQualityFoodEaten();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfLivingEradicatorsKilled();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfLaserSightHeadshots();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfKillsWithPropaneTankExplosion();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfKillsOfUnawareEnemy();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfKilledHumans();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfHumansKilledWithSapGloves();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfHumansKilledWithGrenadeLauncher();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfHumansKilledWithEsteemedMortal();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfHumansKilledWithElephantGun();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfGunTableItemsCrafted(TSubclassOf<AActor> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfGrapplesStarted();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfGearTableItemsCrafted(TSubclassOf<AActor> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfFoodItemsCrafted(TSubclassOf<AActor> FoodType);
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfFoodItemsConsumed(TSubclassOf<AActor> FoodType);
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfEnemiesKilledWithSilencedWeaponsUndetected();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfEnemiesKilledWithGrenadeLauncher();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfEnemiesKilledWithChainsaw();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfDissidentsKilled();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfBrainedWalkerWithSpikedBat();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfBrainedWalkerWithScrewDriver();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfBrainedWalkers();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfBrainedEliteWalkerWithAxe();
    
    UFUNCTION(BlueprintCallable)
    void IncrementNumberOfBackpackItemsScavenged();
    
    UFUNCTION(BlueprintCallable)
    void IncrementDistanceClimbed(float Delta);
    
    UFUNCTION(BlueprintCallable)
    int32 IncrementConversationProgress(EQuestLine Questline, int32 Increment);
    
    UFUNCTION(BlueprintCallable)
    bool HasTask(TSubclassOf<UTWDTask> Task);
    
    UFUNCTION(BlueprintCallable)
    bool HasPlayerResolvedTask(TSubclassOf<UTWDTask> TaskToCheck);
    
    UFUNCTION(BlueprintPure)
    bool HasPlayerCompletedTutorial() const;
    
    UFUNCTION(BlueprintPure)
    bool HasNoteInNotebook(const TSubclassOf<ASDIInventoryActor> Note) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetWaveModeRulesIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UTWDExileOrderEvent*> GetUnassignedExileOrderEvents() const;
    
    UFUNCTION(BlueprintPure)
    TArray<TSoftClassPtr<UTWDRecipe>> GetTrackedRecipes() const;
    
    UFUNCTION(BlueprintPure)
    ETWDTimeOfDay GetTimeOfDay() const;
    
    UFUNCTION(BlueprintPure)
    TArray<UTWDTask*> GetTasks() const;
    
    UFUNCTION(BlueprintCallable)
    UTWDTask* GetTask(TSubclassOf<UTWDTask> Task);
    
    UFUNCTION(BlueprintPure)
    int32 GetStoryProgressionValue() const;
    
    UFUNCTION(BlueprintPure)
    UTWDScenarioManager* GetScenarioManager() const;
    
    UFUNCTION()
    UTWDSaveGame* GetSaveGame();
    
    UFUNCTION(BlueprintPure)
    EProgressionMode GetProgressionMode();
    
    UFUNCTION(BlueprintPure)
    int32 GetPreviousTowerPresenceTier() const;
    
    UFUNCTION(BlueprintPure)
    float GetPlayerSicknessStaminaMultiplier() const;
    
    UFUNCTION(BlueprintPure)
    float GetPlayerSickness() const;
    
    UFUNCTION(BlueprintPure)
    FTWDPlayerCustomizationInfo GetPlayerCustomizationInfo() const;
    
    UFUNCTION(BlueprintPure)
    UTWDPlayerBuffManager* GetPlayerBuffManager() const;
    
    UFUNCTION()
    bool GetPersistentLevelData(const FString& SaveKey, FTWDPersistentLevelSaveData& LevelData);
    
    UFUNCTION()
    uint8 GetNotebookSection();
    
    UFUNCTION(BlueprintPure)
    UTWDMapManager* GetMapManager() const;
    
    UFUNCTION(BlueprintPure)
    FName GetMapLocationIdentifier() const;
    
    UFUNCTION()
    FRandomStream GetMapInitStream(EMapTerritoryNodeType MapEnum);
    
    UFUNCTION()
    float GetInitialSaveGamePlayTime();
    
    UFUNCTION(BlueprintCallable)
    bool GetHubItemSerializationStringByGuid(FGuid uid, FString& OutString);
    
    UFUNCTION()
    bool GetHubItemDataByGuid(FGuid uid, FTWDPersistentLevelItemData& OutItemData);
    
    UFUNCTION(BlueprintPure)
    UTWDFavorManager* GetFavorManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UTWDExileOrderEvent* GetExileOrderEventForTerritory(EMapTerritoryNodeType Territory) const;
    
    UFUNCTION(BlueprintPure)
    ETWDDifficultyMode GetDifficultyMode() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetCurrentTowerPresenceTier() const;
    
    UFUNCTION(BlueprintPure)
    FName GetCurrentMapName() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetCurrentLevelFavorTierDifficultyRating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UTWDExileOrderEvent* GetCurrentLevelExileOrderEvent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UTWDExileOrderEvent* GetCurrentLevelAssignedExileOrderEvent() const;
    
    UFUNCTION(BlueprintPure)
    float GetCurrentDayPercentage() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetCurrentDay(bool bUseChapterOffset) const;
    
    UFUNCTION(BlueprintPure)
    UTWDCraftingTableProgression* GetCraftingTableProgression(TSoftClassPtr<AActor> CraftingTableBlueprint) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetConversationProgress(EQuestLine Questline) const;
    
protected:
    UFUNCTION(BlueprintPure)
    FString GetContextString(const FString& ContextKey) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetContextInt(const FString& ContextKey) const;
    
    UFUNCTION(BlueprintPure)
    float GetContextFloat(const FString& ContextKey) const;
    
    UFUNCTION(BlueprintPure)
    bool GetContextBool(const FString& ContextKey) const;
    
public:
    UFUNCTION(BlueprintPure)
    TArray<TSoftClassPtr<UTWDWorldEvent>> GetCompletedStoryEvents() const;
    
protected:
    UFUNCTION(BlueprintPure)
    FTWDGameProgressionChapterProperties GetChapterProperties() const;
    
public:
    UFUNCTION(BlueprintPure)
    UTWDMapManager* GetChapterOneMapManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UTWDExileOrderEvent*> GetAssignedExileOrderEvents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UTWDExileOrderEvent* GetAssignedExileOrderEventForTerritory(EMapTerritoryNodeType Territory) const;
    
    UFUNCTION(BlueprintPure)
    TArray<FSavedLookatNotebookData> GetAllSavedNotebookNoteData() const;
    
    UFUNCTION()
    FRandomStream GetActiveStream();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<UTWDExileOrderEvent*> GetActiveExileOrderEvents() const;
    
    UFUNCTION(BlueprintCallable)
    void DebugSavePersistentItems();
    
    UFUNCTION(BlueprintCallable)
    void DebugLoadPersistentItems();
    
    UFUNCTION()
    UTWDSaveGame* CreateNewSaveGameObject();
    
    UFUNCTION(BlueprintCallable)
    void ClearProgressionData();
    
    UFUNCTION(BlueprintCallable)
    void CheckPoint(bool bBeforeThisMoment);
    
    UFUNCTION(BlueprintPure)
    bool CheckOnlineItemAlreadyAwarded(const FName& OnlineEntitlementName) const;
    
    UFUNCTION(BlueprintCallable)
    void AwardOnlineItem(const FName& OnlineEntitlementName);
    
    UFUNCTION(BlueprintCallable)
    bool AssignActiveExileOrderEvent(UTWDExileOrderEvent* OrderEvent);
    
    UFUNCTION(BlueprintCallable)
    bool AreTaskDependenciesCleared(TSubclassOf<UTWDTask> Task);
    
    UFUNCTION(BlueprintCallable)
    float AlterPlayerSickness(float Delta, ESicknessSourceType SourceType);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceStoryProgressionValue(TSoftClassPtr<UTWDWorldEvent> CompletedEventClass);
    
    UFUNCTION(BlueprintCallable)
    int32 AdvanceDay();
    
    UFUNCTION(BlueprintCallable)
    void AddVisitedMap(FName MapName);
    
    UFUNCTION(BlueprintCallable)
    void AddTask(UTWDTask* Task);
    
    UFUNCTION(BlueprintCallable)
    void AddSuspendedLevelSaveContext(const FString& SaveContext);
    
    UFUNCTION(BlueprintCallable)
    void AddStashItem(const TSubclassOf<ASDIInventoryActor> ItemClass, int32 quantity, uint8 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void AddResolvedTask(TSubclassOf<UTWDTask> ResolvedTask);
    
    UFUNCTION(BlueprintCallable)
    void AddNoteToNotebook(FSavedLookatNotebookData& SavedNoteData);
    
    UFUNCTION(BlueprintCallable)
    void AddMapWithExileLeaderKill();
    
    UFUNCTION(BlueprintCallable)
    void AddInventoryItem(const TSubclassOf<ASDIInventoryActor> ItemClass, int32 quantity, uint8 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void AddExcludedActorToSuspendedLevel(AActor* ActorToExclude);
    
    UFUNCTION(BlueprintCallable)
    void AddCompletedStoryEvent(TSoftClassPtr<UTWDWorldEvent> EventClass);
    
};

