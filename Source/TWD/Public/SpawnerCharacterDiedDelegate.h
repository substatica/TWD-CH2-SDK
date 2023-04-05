#pragma once
#include "CoreMinimal.h"
#include "SpawnerCharacterDiedDelegate.generated.h"

class ATWDCharacter;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpawnerCharacterDied, ATWDCharacter*, Character, float, PrevHealth);

