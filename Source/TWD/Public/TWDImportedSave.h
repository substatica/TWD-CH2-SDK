#pragma once
#include "CoreMinimal.h"
#include "TWDSaveGame.h"
#include "TWDImportedSave.generated.h"

UCLASS()
class TWD_API UTWDImportedSave : public UTWDSaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FText DebugMenuText;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString LiveSaveNameOverride;
    
    UTWDImportedSave();
};

