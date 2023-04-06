#pragma once
#include "CoreMinimal.h"
#include "TWDRecipe.h"
#include "TWDExileOrder.generated.h"

UCLASS()
class TWD_API UTWDExileOrder : public UTWDRecipe {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bHideOutputs;
    
public:
    UTWDExileOrder();
};

