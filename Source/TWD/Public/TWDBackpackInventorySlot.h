#pragma once
#include "CoreMinimal.h"
#include "TWDPlayerInventorySlot.h"
#include "TWDBackpackInventorySlot.generated.h"

UCLASS()
class ATWDBackpackInventorySlot : public ATWDPlayerInventorySlot {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MeshElementIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 AuxMeshElementIndex;
    
public:
    ATWDBackpackInventorySlot(const FObjectInitializer& ObjectInitializer);
};

