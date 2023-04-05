#pragma once
#include "CoreMinimal.h"
#include "TWDDismemberActor.h"
#include "TWDDismemberLimbCap.generated.h"

class UStaticMeshComponent;

UCLASS()
class ATWDDismemberLimbCap : public ATWDDismemberActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* StaticMeshComponent;
    
public:
    ATWDDismemberLimbCap(const FObjectInitializer& ObjectInitializer);
};

