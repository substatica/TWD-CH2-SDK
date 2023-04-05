#include "SDIEnterExitCapsuleTrigger.h"
#include "Components/CapsuleComponent.h"

ASDIEnterExitCapsuleTrigger::ASDIEnterExitCapsuleTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EnterCollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("EnterCollisionComponent"));
    this->ExitCollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("ExitCollisionComponent"));
}

