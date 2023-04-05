#include "TWDGameDirector.h"

ATWDGameDirector::ATWDGameDirector(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnManagerBlueprint = NULL;
    this->UtilityManagerBlueprint = NULL;
    this->CorpseManagerBlueprint = NULL;
    this->DialogueManager = NULL;
    this->SpawnManager = NULL;
    this->AIDirector = NULL;
    this->UtilityManager = NULL;
    this->CorpseManager = NULL;
}

