#pragma once
#include "CoreMinimal.h"
#include "SDIGameplayTagActor.h"
#include "SDIGameplayTagActorSkeletalMesh.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SDISTIMANDRESPONSEPLUGIN_API ASDIGameplayTagActorSkeletalMesh : public ASDIGameplayTagActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* SkeletalMeshComponent;
    
public:
    ASDIGameplayTagActorSkeletalMesh(const FObjectInitializer& ObjectInitializer);
};

