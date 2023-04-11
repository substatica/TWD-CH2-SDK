#pragma once
#include "CoreMinimal.h"
#include "SDIHeldActor.h"
#include "SDIHeldActorSkeletalMesh.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIHeldActorSkeletalMesh : public ASDIHeldActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* SkeletalMeshComponent;
    
public:
    ASDIHeldActorSkeletalMesh(const FObjectInitializer& ObjectInitializer);
};

