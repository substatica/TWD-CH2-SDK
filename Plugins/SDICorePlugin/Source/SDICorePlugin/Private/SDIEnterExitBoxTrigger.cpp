#include "SDIEnterExitBoxTrigger.h"
#include "Components/BoxComponent.h"

ASDIEnterExitBoxTrigger::ASDIEnterExitBoxTrigger() {
    this->EnterCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("EnterCollisionComponent"));
    this->ExitCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("ExitCollisionComponent"));
}

