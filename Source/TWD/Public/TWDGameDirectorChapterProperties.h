#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDGameDirectorChapterProperties.generated.h"

class ATWDDialogueManager;

USTRUCT(BlueprintType)
struct FTWDGameDirectorChapterProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ATWDDialogueManager> DialogueManagerBlueprint;
    
    TWD_API FTWDGameDirectorChapterProperties();
};

