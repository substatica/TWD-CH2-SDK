#pragma once
#include "CoreMinimal.h"
#include "ETWDMockSkuGranting.generated.h"

UENUM(BlueprintType)
enum class ETWDMockSkuGranting : uint8 {
    Ignore,
    Grant,
    Deny,
};

