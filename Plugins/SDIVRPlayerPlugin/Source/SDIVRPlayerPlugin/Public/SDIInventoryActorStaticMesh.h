#pragma once
#include "CoreMinimal.h"
#include "SDIInventoryActor.h"
#include "SDIInventoryActorStaticMesh.generated.h"

class UStaticMeshComponent;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIInventoryActorStaticMesh : public ASDIInventoryActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* StaticMeshComponent;
    
public:
    ASDIInventoryActorStaticMesh(const FObjectInitializer& ObjectInitializer);
};

