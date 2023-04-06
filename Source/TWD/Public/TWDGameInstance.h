#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDICoreGameInstance.h"
#include "OsPermissionsUpdatedDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "TWDSaveGameProfileData.h"
#include "TWDVRPlatformInfo.h"
#include "TWDEstimatedLevelLoadingTime.h"
#include "TWDLoadingScreenSettings.h"
#include "PreReadyForPlayDelegate.h"
#include "ReadyForPlayDelegate.h"
#include "UObject/NoExportTypes.h"
#include "TWDWarningErrorMessageCache.h"
#include "TWDExportResponse.h"
#include "SaveImporterResult.h"
#include "TWDCheatBooleansCache.h"
#include "ETWDDifficultyMode.h"
#include "TWDPlayerCustomizationInfo.h"
#include "UObject/NoExportTypes.h"
#include "EImportSaveGameResult.h"
#include "TWDGameInstance.generated.h"

class UTWDSaveGame;
class UDataTable;
class UTWDGeneralSaveData;
class UTWDSerializedProfile;
class UObject;
class UTWDGameProgression;
class UWorld;
class UTWDGameAchievements;
class UTWDGameEntitlements;
class AActor;
class UTexture;
class UTWDSaveImporter;

UCLASS(NonTransient)
class TWD_API UTWDGameInstance : public USDICoreGameInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOsPermissionsUpdatedDelegate OnOsPermissionsUpdated;
    
    UPROPERTY(Config)
    uint32 GameSaveDataVersion;
    
    UPROPERTY(Config)
    bool bAllowAutoSaving;
    
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentUserProfileIndex;
    
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentSaveProfileIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinimumPlayerWalkerDistanceToAutoSave;
    
    UPROPERTY(BlueprintReadWrite)
    bool bRevivePlayer;
    
    UPROPERTY(BlueprintReadWrite, Config)
    TArray<FTWDVRPlatformInfo> VRPlatformInfoList;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bPerformedInitialVRReset;
    
    UPROPERTY(BlueprintReadWrite, Config, VisibleDefaultsOnly)
    TArray<FTWDEstimatedLevelLoadingTime> EstimatedLevelLoadingTimes;
    
    UPROPERTY(BlueprintReadWrite, Config, VisibleDefaultsOnly)
    float DefaultLevelLoadingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bBootSequenceShown;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PreReadyForPlayTimerDefault;
    
    UPROPERTY(Transient)
    float PreReadyForPlayTimer;
    
    UPROPERTY(BlueprintAssignable)
    FPreReadyForPlay PreReadyForPlay;
    
    UPROPERTY(BlueprintAssignable)
    FReadyForPlay ReadyForPlay;
    
protected:
    UPROPERTY(Config)
    float DemoTimerDuration;
    
    UPROPERTY(Config, NoClear)
    FSoftClassPath GameSaveClass;
    
    UPROPERTY(Config, VisibleAnywhere)
    float FramerateStabilizationMilliseconds;
    
    UPROPERTY(Config, VisibleAnywhere)
    double MaxFramerateStabilizationTime;
    
    UPROPERTY(Config, VisibleAnywhere)
    int32 FlushStreamingCount;
    
    UPROPERTY(Config, VisibleAnywhere)
    float FlushStreamingDelay;
    
    UPROPERTY(EditAnywhere)
    FTWDLoadingScreenSettings LoadingScreenSettings;
    
    UPROPERTY(EditAnywhere)
    float MapTransitionFadeOutDuration;
    
    UPROPERTY(EditAnywhere)
    float MapTransitionFadeInDuration;
    
    UPROPERTY(EditAnywhere)
    float MapTransitionFadeInDelay;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<UDataTable*> PlatformAssetOverrideTables;
    
    UPROPERTY(Transient)
    TMap<FSoftObjectPath, UObject*> PlatformAssetOverrideCache;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UDataTable* PurchaseEntitlementTable;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UDataTable* ProductEntitlementMapTable;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UDataTable* FakeEntitlementTestTable;
    
    UPROPERTY(Transient)
    bool bHasCachedPlatformAssetOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FString> ValidTipTagRoots;
    
    UPROPERTY(Transient)
    FName MapTransitionTargetMap;
    
    UPROPERTY(Transient)
    TArray<FTWDWarningErrorMessageCache> WarningCache;
    
    UPROPERTY(Transient)
    TArray<FTWDWarningErrorMessageCache> ErrorCache;
    
    UPROPERTY(Transient)
    UTWDGameProgression* GameProgression;
    
    UPROPERTY(Transient)
    UTWDGameAchievements* GameAchievements;
    
    UPROPERTY(Transient)
    UTWDGameEntitlements* GameEntitlements;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<UTWDGameProgression> GameProgressionClass;
    
    UPROPERTY(EditAnywhere)
    bool bFlushStreamingDuringLoadingScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FString> PS4_LowGoreCoutryCodes;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UObject* IntentRecognizer;
    
    UPROPERTY(Transient)
    FTWDSaveGameProfileData LocalUserProfileData[3];
    
    UPROPERTY(Transient)
    UTWDGeneralSaveData* GeneralSaveData;
    
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<TSubclassOf<AActor>> SaveImportExclusions;
    
protected:
    UPROPERTY(Transient)
    TArray<UTWDSerializedProfile*> LocalUserProfileSerialized;
    
    UPROPERTY(Transient)
    TArray<bool> UserProfileCorruptStatus;
    
    UPROPERTY(Transient)
    UTWDSaveGame* LocalRecentAutoSave;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Transient)
    float LocalAutoSaveFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Transient)
    float AutoSaveFrequency;
    
    UPROPERTY(Config)
    float TelemetryHeartbeatFrequency;
    
    UPROPERTY(Transient)
    double PostLoadTotalDelayStart;
    
    UPROPERTY(Transient)
    double FlushStreamingDelayStart;
    
    UPROPERTY(Transient)
    double SkinCacheLoadingDelayStart;
    
    UPROPERTY(Transient)
    double FramerateStabilizationDelayStart;
    
    UPROPERTY(Transient)
    int32 FlushStreamingCounter;
    
    UPROPERTY(Transient)
    bool bPreReadyForPlaySent;
    
    UPROPERTY(Transient)
    UTexture* SplashTexture;
    
    UPROPERTY(Transient)
    double LevelLoadingTime;
    
    UPROPERTY(Transient)
    float EstimatedLevelLoadingTime;
    
    UPROPERTY(Transient)
    FString PreviousMapName;
    
public:
    UTWDGameInstance();
protected:
    UFUNCTION()
    void TurnOnSplashScreen();
    
    UFUNCTION()
    void TravelForMapTransition();
    
public:
    UFUNCTION(BlueprintCallable)
    void StartDemoTimer();
    
    UFUNCTION(Exec)
    void ShowLocalPlayerPosition();
    
    UFUNCTION(Exec)
    void ShowBuildVersion();
    
    UFUNCTION(BlueprintCallable)
    void SetUserProfileIndex(int32 NewProfileIndex);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void SetupMaterialParameterCollectionValues();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetupHMDSettings();
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetSDIMobileGamma(float G);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetPreReadyForPlayTimer(float Timer);
    
    UFUNCTION()
    void SetCheatBooleans(FTWDCheatBooleansCache NewCheatBooleansCache);
    
    UFUNCTION(BlueprintPure)
    bool SaveGameExistsAtIndex(int32 Index) const;
    
    UFUNCTION(BlueprintCallable)
    bool SaveGameAtIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    bool SaveCustomGame(const FString& CustomGameName);
    
    UFUNCTION(BlueprintCallable)
    bool SaveAtOldestIndex();
    
    UFUNCTION(BlueprintCallable)
    bool SaveAtCurrentIndex();
    
    UFUNCTION(BlueprintCallable)
    void RequestOsReadPermissions();
    
    UFUNCTION(BlueprintCallable)
    void RefreshSaveGames();
    
protected:
    UFUNCTION()
    void PreLoadMapCallback(const FString& MapName);
    
    UFUNCTION()
    void PostLoadMapCallback(UWorld* LoadedWorld);
    
    UFUNCTION()
    void PerformMapReadyTransition();
    
public:
    UFUNCTION()
    void OnTelemetryHeartbeatTimerComplete();
    
private:
    UFUNCTION()
    void OnReadPermissionsChanged();
    
public:
    UFUNCTION()
    void OnLocalAutoSaveTimerComplete();
    
    UFUNCTION()
    void OnImportSubsystemResponseReceived(FSaveImporterResult Response);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnGoreLevelChanged(int32 newGoreLevel);
    
public:
    UFUNCTION()
    void OnExportSubsystemResponseReceived(FTWDExportResponse Response);
    
protected:
    UFUNCTION()
    void OnDemoTimerExpired();
    
public:
    UFUNCTION()
    void OnAutoSavingDisabledTimerComplete();
    
    UFUNCTION()
    void OnAutoSaveTimerComplete();
    
    UFUNCTION(BlueprintCallable)
    bool NewGameFromImportedSave(ETWDDifficultyMode DifficultyMode, bool bLoadNewGame, FName StartingMapName);
    
    UFUNCTION(BlueprintCallable)
    bool NewGameFromExistingSave(UTWDSaveGame* SaveGame, FTWDPlayerCustomizationInfo PlayerCustomizationInfo, ETWDDifficultyMode DifficultyMode, bool bLoadNewGame);
    
    UFUNCTION(BlueprintCallable)
    bool NewGameAtIndex(int32 Index, FTWDPlayerCustomizationInfo PlayerCustomizationInfo, ETWDDifficultyMode DifficultyMode, bool bLoadNewGame, FName StartingMapName);
    
    UFUNCTION(BlueprintCallable)
    bool LoadSaveGame(UTWDSaveGame* SaveGame, bool bLoadIntoLevel, bool bIsNewGame);
    
protected:
    UFUNCTION()
    void LoadLightScenario();
    
public:
    UFUNCTION(BlueprintCallable)
    bool LoadGameAtIndex(int32 Index, bool bLoadIntoLevel);
    
    UFUNCTION(BlueprintCallable)
    bool LoadCustomGame(const FString& CustomGameName);
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> K2_GetSortedSaveGameIndices();
    
    UFUNCTION(BlueprintPure)
    bool IsUserProfileCorrupt(int32 Index) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsTransitioningMapTimerActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsTipValid(const FString& Tag);
    
    UFUNCTION(BlueprintPure)
    bool IsInMainMenuMap() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetTotalSaveIndices() const;
    
    UFUNCTION()
    TArray<int32> GetSortedSaveGameIndices(const TArray<UTWDSaveGame*>& SaveGames);
    
protected:
    UFUNCTION(BlueprintCallable)
    float GetSDIMobileGamma();
    
public:
    UFUNCTION(BlueprintPure)
    UTWDSaveImporter* GetSaveImporter() const;
    
    UFUNCTION(BlueprintCallable)
    void GetSaveGameDisplayData(int32 Index, FText& LevelText, int32& Day, FDateTime& SaveTime, float& TimePlayedInSeconds, ETWDDifficultyMode& DiffultyMode);
    
    UFUNCTION(BlueprintPure)
    UTWDSaveGame* GetSaveGameAt(int32 ProfileIndex, int32 SaveSlotIndex) const;
    
    UFUNCTION(BlueprintPure)
    UDataTable* GetPurchaseEntitlementTable() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetOldestSaveIndex();
    
    UFUNCTION(BlueprintPure)
    int32 GetMostRecentSaveIndex() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetLoadingScreenIndex(TArray<float> MinPercentages, TArray<float> MaxPercentages) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetLevelStartSaveIndex() const;
    
    UFUNCTION(BlueprintPure)
    bool GetIsPicoChinaMainland();
    
    UFUNCTION(BlueprintPure)
    EImportSaveGameResult GetImportedSaveStatus() const;
    
    UFUNCTION(BlueprintCallable)
    void GetImportedSaveGameDisplayData(FText& LevelText, int32& Day, FDateTime& SaveTime, float& TimePlayedInSeconds, ETWDDifficultyMode& DiffultyMode);
    
    UFUNCTION(BlueprintPure)
    UTWDGeneralSaveData* GetGeneralSaveData() const;
    
    UFUNCTION(BlueprintPure)
    UTWDGameProgression* GetGameProgression() const;
    
    UFUNCTION(BlueprintPure)
    UTWDGameEntitlements* GetGameEntitlements() const;
    
    UFUNCTION(BlueprintPure)
    UTWDGameAchievements* GetGameAchievements() const;
    
    UFUNCTION(BlueprintPure)
    FString GetDefaultMap() const;
    
    UFUNCTION(BlueprintCallable)
    float GetColorMid();
    
    UFUNCTION()
    FTWDCheatBooleansCache GetCheatBooleans();
    
protected:
    UFUNCTION()
    void EndLoadingScreen();
    
public:
    UFUNCTION(BlueprintCallable)
    void EnableAutoSaving(bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void DisableAutoSavingForDuration(float Duration);
    
    UFUNCTION(BlueprintCallable)
    void DisableAutoSaving();
    
    UFUNCTION(BlueprintCallable)
    bool DeleteGameAtIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    bool DebugLoadImportedGame(bool bLoadIntoLevel, FName StartingMapName);
    
    UFUNCTION(BlueprintCallable)
    void CheckAndroidPermissions(bool& OutMic, bool& OutRead, bool& OutWrite);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ChangeGoreLevel(int32 newGoreLevel);
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanAutoSave();
    
    UFUNCTION(BlueprintCallable)
    void BeginMapTransition(FName TargetMapName);
    
protected:
    UFUNCTION()
    void BeginLoadingScreen(const FString& MapName);
    
public:
    UFUNCTION(BlueprintCallable)
    bool AutoSaveCurrentGame();
    
    UFUNCTION()
    void AddPlayerContextTelemetryData(TMap<FString, FString>& TelemetryData);
    
};

