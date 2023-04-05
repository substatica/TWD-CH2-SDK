#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/SaveGame.h"
#include "MapTerritoryNode.h"
#include "SavedLookatNotebookData.h"
#include "EMapTerritoryNodeType.h"
#include "UObject/NoExportTypes.h"
#include "TWDAchievementData.h"
#include "ETWDTimeOfDay.h"
#include "TWDSerializedWorldEvent.h"
#include "EventDeckContentsEntry.h"
#include "TWDSavedInventoryItemData.h"
#include "InputCoreTypes.h"
#include "TWDSavedItemData.h"
#include "TWDPersistentLevelSaveData.h"
#include "TWDPlayerCustomizationInfo.h"
#include "TWDSuspendedLevelSaveData.h"
#include "TWDHubStateInfo.h"
#include "TWDPlayerStateInfo.h"
#include "ETWDDifficultyMode.h"
#include "TWDPlayerSicknessInfo.h"
#include "TWDSerializedTask.h"
#include "TWDUniqueEntitlementItemID.h"
#include "TWDFavorDecayState.h"
#include "TWDSaveGame.generated.h"

class UTWDRecipe;
class UTWDWorldEvent;
class UTWDTask;
class UTWDSaveGame;
class UTWDDialogue;

UCLASS(BlueprintType)
class TWD_API UTWDSaveGame : public USaveGame {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(VisibleAnywhere)
    FString SaveSlotName;
    
    UPROPERTY(VisibleAnywhere)
    uint32 UserIndex;
    
    UPROPERTY(VisibleAnywhere)
    bool bSaveDirty;
    
public:
    UPROPERTY()
    FDateTime SaveTime;
    
    UPROPERTY()
    float TimeInSecondsPlayed;
    
    UPROPERTY()
    int32 CurrentRandomStreamSeed;
    
    UPROPERTY()
    int32 MapInitRandomStreamSeed;
    
    UPROPERTY()
    EMapTerritoryNodeType MapInitRandomStreamMap;
    
    UPROPERTY()
    uint32 CreationGameSaveDataVersion;
    
    UPROPERTY()
    uint32 ImportedGameSaveDataVersion;
    
    UPROPERTY()
    bool bCreatedFromImportedSave;
    
    UPROPERTY()
    TArray<FMapTerritoryNode> MapNodes;
    
    UPROPERTY(BlueprintReadWrite)
    ETWDTimeOfDay TimeOfDay;
    
    UPROPERTY()
    TSet<EMapTerritoryNodeType> LockedNodeOverrides;
    
    UPROPERTY()
    int32 CachedPrevTowerPresenceTier;
    
    UPROPERTY()
    int32 CachedCurrTowerPresenceTier;
    
private:
    UPROPERTY()
    bool HasPlayerTraveledToday;
    
public:
    UPROPERTY(VisibleAnywhere)
    bool bNightTravelEnabled;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, int32> CraftingTableLevels;
    
    UPROPERTY(VisibleAnywhere)
    TSet<FString> CraftingTableSpecialUnlocks;
    
    UPROPERTY(VisibleAnywhere)
    TSet<FString> CraftingTableHasNotBeenViewed;
    
    UPROPERTY(VisibleAnywhere)
    TArray<TSoftClassPtr<UTWDRecipe>> TrackedRecipes;
    
    UPROPERTY(VisibleAnywhere)
    uint8 CurrentNotebookSection;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FSavedLookatNotebookData> SavedNotebookNotes;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FTWDSerializedWorldEvent> ActiveEvents;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FTWDSerializedWorldEvent> ExpendedEvents;
    
    UPROPERTY(VisibleAnywhere)
    TArray<TSoftClassPtr<UTWDWorldEvent>> CompletedStoryEvents;
    
    UPROPERTY(VisibleAnywhere)
    int32 StoryProgressionValue;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FEventDeckContentsEntry> EventDeck;
    
    UPROPERTY(VisibleAnywhere)
    bool bEventDeckUnlocked;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FTWDSavedInventoryItemData> InventoryItems;
    
    UPROPERTY(VisibleAnywhere)
    TMap<EControllerHand, FTWDSavedItemData> GrippedItems;
    
    UPROPERTY(VisibleAnywhere)
    TMap<uint8, FTWDSavedInventoryItemData> SkiffItems;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, FTWDPersistentLevelSaveData> PersistentLevelData;
    
    UPROPERTY(VisibleAnywhere)
    FTWDSuspendedLevelSaveData SuspendedLevelData;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FTWDSavedInventoryItemData> StashItems;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FTWDSavedInventoryItemData> StolenStashItems;
    
    UPROPERTY(VisibleAnywhere)
    int32 CurrentDay;
    
    UPROPERTY(VisibleAnywhere)
    FName CurrentMapName;
    
    UPROPERTY(VisibleAnywhere)
    FName MapLocationIdentifier;
    
    UPROPERTY(VisibleAnywhere)
    FTWDHubStateInfo HubStateInfo;
    
    UPROPERTY(VisibleAnywhere)
    FTWDPlayerStateInfo PlayerStateInfo;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    FTWDPlayerCustomizationInfo PlayerCustomizationInfo;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ETWDDifficultyMode DifficultyMode;
    
    UPROPERTY(VisibleAnywhere)
    float CurrentHealth;
    
    UPROPERTY(VisibleAnywhere)
    float CurrentStamina;
    
    UPROPERTY(VisibleAnywhere)
    float CurrentMaxStamina;
    
    UPROPERTY(VisibleAnywhere)
    FTWDPlayerSicknessInfo PlayerSicknessInfo;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FName> TemporaryBuffs;
    
    UPROPERTY(VisibleAnywhere)
    bool bStealthModeActive;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, bool> PlayerContextBoolMap;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, int32> PlayerContextIntMap;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, float> PlayerContextFloatMap;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, FString> PlayerContextStringMap;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, bool> LegacyTitleContextBoolMap;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, int32> LegacyTitleContextIntMap;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, float> LegacyTitleContextFloatMap;
    
    UPROPERTY(VisibleAnywhere)
    TMap<FString, FString> LegacyTitleContextStringMap;
    
    UPROPERTY(VisibleAnywhere)
    TArray<FTWDSerializedTask> PlayerTasks;
    
    UPROPERTY(VisibleAnywhere)
    TArray<TSoftClassPtr<UTWDTask>> ResolvedTasks;
    
    UPROPERTY(VisibleAnywhere)
    TMap<TSubclassOf<UTWDDialogue>, FString> DialogueBookmarks;
    
    UPROPERTY(VisibleAnywhere)
    bool bCompletedTutorial;
    
    UPROPERTY(BlueprintReadOnly)
    FTWDAchievementData AchievementProgress;
    
    UPROPERTY()
    TArray<FTWDUniqueEntitlementItemID> OnlineItemsAlreadyAwarded;
    
    UPROPERTY(VisibleAnywhere)
    bool bFavorManagerEnabled;
    
    UPROPERTY(VisibleAnywhere)
    TMap<EMapTerritoryNodeType, float> LocalFavorByTerritory;
    
    UPROPERTY(VisibleAnywhere)
    TMap<EMapTerritoryNodeType, FTWDFavorDecayState> FavorDecayStateByTerritory;
    
    UPROPERTY(VisibleAnywhere)
    uint32 PlayerDeathCount;
    
    UTWDSaveGame();
    UFUNCTION()
    void WriteVerboseDescription(const FString& OutFileName) const;
    
    UFUNCTION()
    void RetrofitTimeOfDay();
    
    UFUNCTION(BlueprintPure)
    bool IsSaveDirty() const;
    
    UFUNCTION(BlueprintPure)
    FString GetSaveSlotName() const;
    
    UFUNCTION(BlueprintCallable)
    void DumpPlayerInventory();
    
    UFUNCTION()
    void CopyData(const UTWDSaveGame* DataToCopy);
    
};

