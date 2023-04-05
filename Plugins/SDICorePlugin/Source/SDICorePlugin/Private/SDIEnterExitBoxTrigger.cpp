#include "SDIEnterExitBoxTrigger.h"
#include "Components/BoxComponent.h"

ASDIEnterExitBoxTrigger::ASDIEnterExitBoxTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EnterCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("EnterCollisionComponent"));
    this->ExitCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("ExitCollisionComponent"));
}

