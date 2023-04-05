#include "SDIEnterExitSphereTrigger.h"
#include "Components/SphereComponent.h"

ASDIEnterExitSphereTrigger::ASDIEnterExitSphereTrigger() {
    this->EnterCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("EnterCollisionComponent"));
    this->ExitCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ExitCollisionComponent"));
}

