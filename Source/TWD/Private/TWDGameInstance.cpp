#include "TWDGameInstance.h"

class UTWDGameAchievements;
class UWorld;
class UTWDSaveImporter;
class UTWDGameProgression;
class UTWDSaveGame;
class UDataTable;
class UTWDGeneralSaveData;
class UTWDGameEntitlements;

void UTWDGameInstance::TurnOnSplashScreen() {
}

void UTWDGameInstance::TravelForMapTransition() {
}

void UTWDGameInstance::StartDemoTimer() {
}

void UTWDGameInstance::ShowLocalPlayerPosition() {
}

void UTWDGameInstance::ShowBuildVersion() {
}

void UTWDGameInstance::SetUserProfileIndex(int32 NewProfileIndex) {
}


void UTWDGameInstance::SetupHMDSettings() {
}

void UTWDGameInstance::SetSDIMobileGamma(float G) {
}

void UTWDGameInstance::SetPreReadyForPlayTimer(float Timer) {
}

void UTWDGameInstance::SetCheatBooleans(FTWDCheatBooleansCache NewCheatBooleansCache) {
}

bool UTWDGameInstance::SaveGameExistsAtIndex(int32 Index) const {
    return false;
}

bool UTWDGameInstance::SaveGameAtIndex(int32 Index) {
    return false;
}

bool UTWDGameInstance::SaveCustomGame(const FString& CustomGameName) {
    return false;
}

bool UTWDGameInstance::SaveAtOldestIndex() {
    return false;
}

bool UTWDGameInstance::SaveAtCurrentIndex() {
    return false;
}

void UTWDGameInstance::RequestOsReadPermissions() {
}

void UTWDGameInstance::RefreshSaveGames() {
}

void UTWDGameInstance::PreLoadMapCallback(const FString& MapName) {
}

void UTWDGameInstance::PostLoadMapCallback(UWorld* LoadedWorld) {
}

void UTWDGameInstance::PerformMapReadyTransition() {
}

void UTWDGameInstance::OnTelemetryHeartbeatTimerComplete() {
}

void UTWDGameInstance::OnReadPermissionsChanged() {
}

void UTWDGameInstance::OnLocalAutoSaveTimerComplete() {
}

void UTWDGameInstance::OnImportSubsystemResponseReceived(FSaveImporterResult Response) {
}


void UTWDGameInstance::OnExportSubsystemResponseReceived(FTWDExportResponse Response) {
}

void UTWDGameInstance::OnDemoTimerExpired() {
}

void UTWDGameInstance::OnAutoSavingDisabledTimerComplete() {
}

void UTWDGameInstance::OnAutoSaveTimerComplete() {
}

bool UTWDGameInstance::NewGameFromImportedSave(ETWDDifficultyMode DifficultyMode, bool bLoadNewGame, FName StartingMapName) {
    return false;
}

bool UTWDGameInstance::NewGameFromExistingSave(UTWDSaveGame* SaveGame, FTWDPlayerCustomizationInfo PlayerCustomizationInfo, ETWDDifficultyMode DifficultyMode, bool bLoadNewGame) {
    return false;
}

bool UTWDGameInstance::NewGameAtIndex(int32 Index, FTWDPlayerCustomizationInfo PlayerCustomizationInfo, ETWDDifficultyMode DifficultyMode, bool bLoadNewGame, FName StartingMapName) {
    return false;
}

bool UTWDGameInstance::LoadSaveGame(UTWDSaveGame* SaveGame, bool bLoadIntoLevel, bool bIsNewGame) {
    return false;
}

void UTWDGameInstance::LoadLightScenario() {
}

bool UTWDGameInstance::LoadGameAtIndex(int32 Index, bool bLoadIntoLevel) {
    return false;
}

bool UTWDGameInstance::LoadCustomGame(const FString& CustomGameName) {
    return false;
}

TArray<int32> UTWDGameInstance::K2_GetSortedSaveGameIndices() {
    return TArray<int32>();
}

bool UTWDGameInstance::IsUserProfileCorrupt(int32 Index) const {
    return false;
}

bool UTWDGameInstance::IsTransitioningMapTimerActive() {
    return false;
}

bool UTWDGameInstance::IsTipValid(const FString& Tag) {
    return false;
}

bool UTWDGameInstance::IsInMainMenuMap() const {
    return false;
}

int32 UTWDGameInstance::GetTotalSaveIndices() const {
    return 0;
}

TArray<int32> UTWDGameInstance::GetSortedSaveGameIndices(const TArray<UTWDSaveGame*>& SaveGames) {
    return TArray<int32>();
}

float UTWDGameInstance::GetSDIMobileGamma() {
    return 0.0f;
}

UTWDSaveImporter* UTWDGameInstance::GetSaveImporter() const {
    return NULL;
}

void UTWDGameInstance::GetSaveGameDisplayData(int32 Index, FText& LevelText, int32& Day, FDateTime& SaveTime, float& TimePlayedInSeconds, ETWDDifficultyMode& DiffultyMode) {
}

UTWDSaveGame* UTWDGameInstance::GetSaveGameAt(int32 ProfileIndex, int32 SaveSlotIndex) const {
    return NULL;
}

UDataTable* UTWDGameInstance::GetPurchaseEntitlementTable() const {
    return NULL;
}

int32 UTWDGameInstance::GetOldestSaveIndex() {
    return 0;
}

int32 UTWDGameInstance::GetMostRecentSaveIndex() const {
    return 0;
}

int32 UTWDGameInstance::GetLoadingScreenIndex(TArray<float> MinPercentages, TArray<float> MaxPercentages) const {
    return 0;
}

int32 UTWDGameInstance::GetLevelStartSaveIndex() const {
    return 0;
}

bool UTWDGameInstance::GetIsPicoChinaMainland() {
    return false;
}

EImportSaveGameResult UTWDGameInstance::GetImportedSaveStatus() const {
    return EImportSaveGameResult::OK;
}

void UTWDGameInstance::GetImportedSaveGameDisplayData(FText& LevelText, int32& Day, FDateTime& SaveTime, float& TimePlayedInSeconds, ETWDDifficultyMode& DiffultyMode) {
}

UTWDGeneralSaveData* UTWDGameInstance::GetGeneralSaveData() const {
    return NULL;
}

UTWDGameProgression* UTWDGameInstance::GetGameProgression() const {
    return NULL;
}

UTWDGameEntitlements* UTWDGameInstance::GetGameEntitlements() const {
    return NULL;
}

UTWDGameAchievements* UTWDGameInstance::GetGameAchievements() const {
    return NULL;
}

FString UTWDGameInstance::GetDefaultMap() const {
    return TEXT("");
}

float UTWDGameInstance::GetColorMid() {
    return 0.0f;
}

FTWDCheatBooleansCache UTWDGameInstance::GetCheatBooleans() {
    return FTWDCheatBooleansCache{};
}

void UTWDGameInstance::EndLoadingScreen() {
}

void UTWDGameInstance::EnableAutoSaving(bool bForce) {
}

void UTWDGameInstance::DisableAutoSavingForDuration(float Duration) {
}

void UTWDGameInstance::DisableAutoSaving() {
}

bool UTWDGameInstance::DeleteGameAtIndex(int32 Index) {
    return false;
}

bool UTWDGameInstance::DebugLoadImportedGame(bool bLoadIntoLevel, FName StartingMapName) {
    return false;
}

void UTWDGameInstance::CheckAndroidPermissions(bool& OutMic, bool& OutRead, bool& OutWrite) {
}

void UTWDGameInstance::ChangeGoreLevel(int32 newGoreLevel) {
}

bool UTWDGameInstance::CanAutoSave() {
    return false;
}

void UTWDGameInstance::BeginMapTransition(FName TargetMapName) {
}

void UTWDGameInstance::BeginLoadingScreen(const FString& MapName) {
}

bool UTWDGameInstance::AutoSaveCurrentGame() {
    return false;
}

void UTWDGameInstance::AddPlayerContextTelemetryData(TMap<FString, FString>& TelemetryData) {
}

UTWDGameInstance::UTWDGameInstance() {
    this->GameSaveDataVersion = 4;
    this->bAllowAutoSaving = false;
    this->CurrentUserProfileIndex = 0;
    this->CurrentSaveProfileIndex = 0;
    this->MinimumPlayerWalkerDistanceToAutoSave = 500.00f;
    this->bRevivePlayer = false;
    this->VRPlatformInfoList.AddDefaulted(6);
    this->bPerformedInitialVRReset = false;
    this->DefaultLevelLoadingTime = 20.00f;
    this->bBootSequenceShown = false;
    this->PreReadyForPlayTimerDefault = 1.00f;
    this->PreReadyForPlayTimer = 1.00f;
    this->DemoTimerDuration = 1200.00f;
    this->FramerateStabilizationMilliseconds = 35.00f;
    this->MaxFramerateStabilizationTime = 5.00f;
    this->FlushStreamingCount = 1;
    this->FlushStreamingDelay = 0.10f;
    this->MapTransitionFadeOutDuration = 1.00f;
    this->MapTransitionFadeInDuration = 3.00f;
    this->MapTransitionFadeInDelay = 1.00f;
    this->PurchaseEntitlementTable = NULL;
    this->ProductEntitlementMapTable = NULL;
    this->FakeEntitlementTestTable = NULL;
    this->bHasCachedPlatformAssetOverrides = false;
    this->GameProgression = NULL;
    this->GameAchievements = NULL;
    this->GameEntitlements = NULL;
    this->GameProgressionClass = NULL;
    this->bFlushStreamingDuringLoadingScreen = true;
    this->IntentRecognizer = NULL;
    this->GeneralSaveData = NULL;
    this->LocalRecentAutoSave = NULL;
    this->LocalAutoSaveFrequency = 5.00f;
    this->AutoSaveFrequency = 240.00f;
    this->TelemetryHeartbeatFrequency = 300.00f;
    this->PostLoadTotalDelayStart = 0.00f;
    this->FlushStreamingDelayStart = 0.00f;
    this->SkinCacheLoadingDelayStart = 0.00f;
    this->FramerateStabilizationDelayStart = 0.00f;
    this->FlushStreamingCounter = 0;
    this->bPreReadyForPlaySent = false;
    this->SplashTexture = NULL;
    this->LevelLoadingTime = 0.00f;
    this->EstimatedLevelLoadingTime = 0.00f;
}

