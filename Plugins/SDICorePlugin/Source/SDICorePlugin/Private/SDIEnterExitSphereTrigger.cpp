#include "SDIEnterExitSphereTrigger.h"
#include "Components/SphereComponent.h"

ASDIEnterExitSphereTrigger::ASDIEnterExitSphereTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EnterCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("EnterCollisionComponent"));
    this->ExitCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ExitCollisionComponent"));
}

