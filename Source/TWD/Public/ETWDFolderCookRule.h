#pragma once
#include "CoreMinimal.h"
#include "ETWDFolderCookRule.generated.h"

UENUM()
enum class ETWDFolderCookRule : uint8 {
    Unknown,
    NeverCook,
    DevelopmentCook,
};

