#pragma once
#include "CoreMinimal.h"
#include "SpawnerCharacterSpawnedDelegate.generated.h"

class ATWDCharacter;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnerCharacterSpawned, ATWDCharacter*, Character);

