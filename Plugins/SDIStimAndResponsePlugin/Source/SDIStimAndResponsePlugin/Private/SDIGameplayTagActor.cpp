#include "SDIGameplayTagActor.h"

ASDIGameplayTagActor::ASDIGameplayTagActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}
