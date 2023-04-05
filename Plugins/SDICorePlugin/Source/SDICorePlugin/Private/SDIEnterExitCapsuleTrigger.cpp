#include "SDIEnterExitCapsuleTrigger.h"
#include "Components/CapsuleComponent.h"

ASDIEnterExitCapsuleTrigger::ASDIEnterExitCapsuleTrigger() {
    this->EnterCollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("EnterCollisionComponent"));
    this->ExitCollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("ExitCollisionComponent"));
}

