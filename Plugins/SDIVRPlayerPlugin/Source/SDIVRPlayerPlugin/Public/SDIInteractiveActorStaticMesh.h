#pragma once
#include "CoreMinimal.h"
#include "SDIInteractiveActor.h"
#include "SDIInteractiveActorStaticMesh.generated.h"

class UStaticMeshComponent;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIInteractiveActorStaticMesh : public ASDIInteractiveActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* StaticMeshComponent;
    
public:
    ASDIInteractiveActorStaticMesh(const FObjectInitializer& ObjectInitializer);
};

