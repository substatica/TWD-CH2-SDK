#include "TWDSpawnManager.h"
#include "Templates/SubclassOf.h"

class AActor;
class ATWDCharacter;
class ATWDWeaponGun;

void ATWDSpawnManager::UpdateSpawnManager_Implementation() {
}

bool ATWDSpawnManager::UpdateOverrunRestoration() {
    return false;
}

void ATWDSpawnManager::StreamingLevelLoaded() {
}

void ATWDSpawnManager::StopSpawnTimer(int32 TimerCommandIndex) {
}

void ATWDSpawnManager::StartSpawnTimer(int32 TimerCommandIndex) {
}

void ATWDSpawnManager::SpawnTimerComplete(int32 TimerCommandIndex) {
}

void ATWDSpawnManager::SetSignificanceLimits(int32 MaxHumans, int32 MaxTotalAI) {
}

void ATWDSpawnManager::SetSignificanceAICountOverride(int32 MaxHumans, int32 MaxAIs) {
}

void ATWDSpawnManager::SetOverrun(bool bIsOverrun) {
}

void ATWDSpawnManager::SetInfested(bool bIsInfested) {
}

void ATWDSpawnManager::Revive_Implementation(FVector RespawnLocation) {
}

void ATWDSpawnManager::ResetOverrunRestoration() {
}

AActor* ATWDSpawnManager::RequestActor(TSubclassOf<AActor> SpawnClass, FTransform SpawnTransform) {
    return NULL;
}

void ATWDSpawnManager::PopulateSpawnTagMap(bool bIncludeClaimedSpawners) {
}

void ATWDSpawnManager::OnPlayerWeaponFired(ATWDCharacter* PlayerCharacter, ATWDWeaponGun* Weapon) {
}

void ATWDSpawnManager::OnPlayerDestroyed(AActor* PlayerActor) {
}

void ATWDSpawnManager::OnOverrunRestorationComplete_Implementation() {
}

bool ATWDSpawnManager::ModifyTimerTypeOverrideTag(int32 TimerCommandIndex, FName NewTypeOverrideTag, bool bFinishCurrentTimer) {
    return false;
}

bool ATWDSpawnManager::ModifyTimerTag(int32 TimerCommandIndex, FName NewTag, bool bFinishCurrentTimer) {
    return false;
}

bool ATWDSpawnManager::ModifyTimerCommand(int32 TimerCommandIndex, FRFloat NewTimerLengthInSeconds, int32 NewSpawnCount, float NewPlayerProximityRange, bool bFinishCurrentTimer) {
    return false;
}

bool ATWDSpawnManager::ModifySpawnLimit(int32 SpawnLimitIndex, int32 NewSpawnLimit) {
    return false;
}

bool ATWDSpawnManager::IsOverrun() const {
    return false;
}

bool ATWDSpawnManager::IsInsideSpawnableArea(FVector Location) {
    return false;
}

bool ATWDSpawnManager::IsInfested() const {
    return false;
}

void ATWDSpawnManager::GetSignificanceAICounts(int32& MaxHumans, int32& MaxAIs, bool& bHasLimit) {
}

FVector ATWDSpawnManager::GetPredictedSpawnAreaLocation(const ATWDCharacter* Character) {
    return FVector{};
}

int32 ATWDSpawnManager::GetPlayerWeaponFireToWalkerCount() {
    return 0;
}

FRandomStream ATWDSpawnManager::GetActiveStream() {
    return FRandomStream{};
}

void ATWDSpawnManager::ExplosionCausedByPlayer() {
}

void ATWDSpawnManager::ClearSignificanceAICountOverride() {
}


ATWDSpawnManager::ATWDSpawnManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MapEnum = EMapTerritoryNodeType::None;
    this->DefaultSpawnCurve = NULL;
    this->bForceScenarioSeed = false;
    this->ForceScenarioSeed = 1;
    this->SpawnCommandTable = NULL;
    this->ProjectTagTable = NULL;
    this->PlayerProximityRange = 7500.00f;
    this->PlayerProximityNoSpawnRange = 0.00f;
    this->DirectionMod = 0.00f;
    this->BackfaceCullSpawnersFromVelocity = false;
    this->bShowPlayerProximityRange = false;
    this->bUseWasRecentlyRenderedForSpawning = false;
    this->StreamingLevelsLoading = 0;
    this->ReviveKillRadiusAroundPlayerStart = 1000.00f;
    this->bIsReviveDuringBells = false;
    this->CurrentPlayerWeaponFireValue = 0.00f;
    this->MaxPlayerWeaponFireValue = 10.00f;
    this->ValuePerPlayerWeaponFire = 1.00f;
    this->ValuePerPlayerExplosion = 0.00f;
    this->ValuePerPlayerWeaponFireDecayRate = 0.50f;
    this->PlayerWeaponFireToWalkerCurve = NULL;
    this->UpdateSpawnManagerInterval = 0.10f;
    this->MaxSignificanceHuman = 6;
    this->MaxSignificanceAICharacters = 10;
    this->MaxSignificanceHumanTier0 = 6;
    this->MaxSignificanceAICharactersTier0 = 8;
    this->MaxSignificanceHumanDelMar = 6;
    this->MaxSignificanceAICharactersDelMar = 10;
    this->MaxSignificanceHumanHi = 12;
    this->MaxSignificanceAICharactersHi = 30;
    this->MaxSignificanceHumanOverride = -1;
    this->MaxSignificanceAICharactersOverride = -1;
    this->bUseSpawnOverrides = false;
    this->SpawnClassOverride = NULL;
    this->WalkerSpawnClassOverride = NULL;
    this->CurrentRegionIndex = 0;
    this->OverrunRestorationRequiredTime = 0.00f;
    this->OverrunRestorationRequiredKills = 0;
    this->bOverrunRestorationEnabled = false;
    this->OverrunRestorationInitTimestamp = 0.00f;
    this->OverrunRestorationCurrentKills = 0;
    this->bShowTimedSpawnerDebug = false;
    this->bShowSpawnLimitDebug = false;
    this->bShowLineOfSightCheckDebug = false;
    this->TimeLineOfSightCheckDebug = 0.50f;
    this->bShowFoundSpawnerTags = false;
    this->bIgnoreNetworkedSpawners = true;
    this->bRefreshPossibleSpawnCounts = false;
    this->bMapCheckAllPossibleSpawns = true;
    this->bWaveMode = false;
    this->GameDirector = NULL;
    this->bInfested = false;
    this->bOverrun = false;
}

