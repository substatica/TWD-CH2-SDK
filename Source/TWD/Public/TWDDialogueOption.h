#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDDialogueOption.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDDialogueOption : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bOptional;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bExecuted;
    
    FTWDDialogueOption();
};

