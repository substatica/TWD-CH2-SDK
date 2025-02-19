#pragma once
#include "CoreMinimal.h"
#include "TWDInventoryHolderActor.h"
#include "TWDPlayerLootDrop.generated.h"

class AActor;

UCLASS()
class ATWDPlayerLootDrop : public ATWDInventoryHolderActor {
    GENERATED_BODY()
public:
    ATWDPlayerLootDrop(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintNativeEvent)
    bool GiveContentsTo(AActor* NewOwner);
    
};

