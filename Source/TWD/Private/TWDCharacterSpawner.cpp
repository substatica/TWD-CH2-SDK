#include "TWDCharacterSpawner.h"
#include "Templates/SubclassOf.h"

class ATWDCharacter;
class UDamageType;
class AActor;

void ATWDCharacterSpawner::StartSpawner_Implementation() {
}

void ATWDCharacterSpawner::SpawnSingle_Implementation() {
}

void ATWDCharacterSpawner::OnCharacterDied(ATWDCharacter* Character, float PrevHealth, TSubclassOf<UDamageType> DamageTypeClass, AActor* DamageCauser) {
}

ATWDCharacterSpawner::ATWDCharacterSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CharacterBlueprint = NULL;
}

