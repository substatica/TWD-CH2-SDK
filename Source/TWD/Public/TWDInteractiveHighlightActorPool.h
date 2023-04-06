#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDInteractiveHighlightActorPool.generated.h"

class ATWDInteractiveHighlightActor;

USTRUCT(BlueprintType)
struct FTWDInteractiveHighlightActorPool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ATWDInteractiveHighlightActor> HighlightActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 InitialPoolSize;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<ATWDInteractiveHighlightActor*> Pool;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<ATWDInteractiveHighlightActor*> InUse;
    
    TWD_API FTWDInteractiveHighlightActorPool();
};

