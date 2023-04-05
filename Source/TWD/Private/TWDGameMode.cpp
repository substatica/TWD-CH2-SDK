#include "TWDGameMode.h"
#include "Templates/SubclassOf.h"

class UTWDAnimIdManager;
class AController;
class UTWDAIManager;
class ATWDCharacter;
class ATWDAIController;
class UDamageType;
class AActor;

void ATWDGameMode::StartBells_Implementation() {
}

void ATWDGameMode::SetMatchSubState(FName NewState) {
}

bool ATWDGameMode::RemoveQueuedExplosion(const FTWDQueuedExplosionDelegate& ExplosionDelegate) {
    return false;
}

void ATWDGameMode::QueueExplosion(AController* EventInstigator, const FTWDQueuedExplosionDelegate& ExplosionDelegate) {
}

void ATWDGameMode::ProcessQueuedExplosions() {
}

void ATWDGameMode::OnMatchSubStateSet_Implementation() {
}

void ATWDGameMode::OnCharacterDeath_Implementation(ATWDCharacter* Character, float PrevHealth, TSubclassOf<UDamageType> DamageTypeClass, AActor* DamageCauser) {
}

bool ATWDGameMode::IsNotebookEnabled() const {
    return false;
}

bool ATWDGameMode::IsExplosionQueued(const FTWDQueuedExplosionDelegate& ExplosionDelegate) {
    return false;
}

void ATWDGameMode::InitializeAIByGameMode_Implementation(ATWDAIController* AIController) {
}

UTWDAnimIdManager* ATWDGameMode::GetAnimIdManager() {
    return NULL;
}

UTWDAIManager* ATWDGameMode::GetAIManager() {
    return NULL;
}

ATWDGameMode::ATWDGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bProcessingQueuedExplosions = false;
    this->AIManagerClass = NULL;
    this->bEnableSleepingAISystem = false;
    this->GameDirectorBlueprint = NULL;
    this->bNotebookEnabled = false;
    this->GameDirector = NULL;
    this->AIManager = NULL;
    this->AnimIdManager = NULL;
}

