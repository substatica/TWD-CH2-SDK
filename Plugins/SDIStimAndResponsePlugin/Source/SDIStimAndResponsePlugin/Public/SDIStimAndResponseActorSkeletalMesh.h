#pragma once
#include "CoreMinimal.h"
#include "SDIStimAndResponseActor.h"
#include "SDIStimAndResponseActorSkeletalMesh.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SDISTIMANDRESPONSEPLUGIN_API ASDIStimAndResponseActorSkeletalMesh : public ASDIStimAndResponseActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* SkeletalMeshComponent;
    
public:
    ASDIStimAndResponseActorSkeletalMesh(const FObjectInitializer& ObjectInitializer);
};

