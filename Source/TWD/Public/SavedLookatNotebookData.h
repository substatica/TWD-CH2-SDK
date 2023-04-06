#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ETWDSavedNoteCategory.h"
#include "SavedLookatNotebookData.generated.h"

class ASDIInventoryActor;

USTRUCT(BlueprintType)
struct TWD_API FSavedLookatNotebookData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDSavedNoteCategory Category;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FText TitleToDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowRetrigger;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ASDIInventoryActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite)
    float CollectedTime;
    
    FSavedLookatNotebookData();
};

