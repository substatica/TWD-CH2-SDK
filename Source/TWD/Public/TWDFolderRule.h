#pragma once
#include "CoreMinimal.h"
#include "ETWDFolderCookRule.h"
#include "TWDFolderRule.generated.h"

USTRUCT(BlueprintType)
struct FTWDFolderRule {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FString Folder;
    
    UPROPERTY(EditAnywhere)
    ETWDFolderCookRule CookRule;
    
    TWD_API FTWDFolderRule();
};

