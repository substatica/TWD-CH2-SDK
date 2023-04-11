#pragma once
#include "CoreMinimal.h"
#include "SDICoreProjectileActor.h"
#include "SDICoreProjectileActorSphere.generated.h"

class USphereComponent;

UCLASS()
class SDICOREPLUGIN_API ASDICoreProjectileActorSphere : public ASDICoreProjectileActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USphereComponent* SphereCollision;
    
public:
    ASDICoreProjectileActorSphere();
};

