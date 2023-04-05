#include "SDICoreProjectileActorSphere.h"
#include "Components/SphereComponent.h"

ASDICoreProjectileActorSphere::ASDICoreProjectileActorSphere(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
}

