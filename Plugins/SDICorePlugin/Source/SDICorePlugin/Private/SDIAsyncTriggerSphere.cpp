#include "SDIAsyncTriggerSphere.h"
#include "SDIAsyncOverlapEventGeneratorComponent.h"

ASDIAsyncTriggerSphere::ASDIAsyncTriggerSphere(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OverlapGenerator = CreateDefaultSubobject<USDIAsyncOverlapEventGeneratorComponent>(TEXT("OverlapGenerator"));
}

