#include "SDIAsyncTriggerCapsule.h"
#include "SDIAsyncOverlapEventGeneratorComponent.h"

ASDIAsyncTriggerCapsule::ASDIAsyncTriggerCapsule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OverlapGenerator = CreateDefaultSubobject<USDIAsyncOverlapEventGeneratorComponent>(TEXT("OverlapGenerator"));
}

