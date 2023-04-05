#include "SDIAsyncTriggerBox.h"
#include "SDIAsyncOverlapEventGeneratorComponent.h"

ASDIAsyncTriggerBox::ASDIAsyncTriggerBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OverlapGenerator = CreateDefaultSubobject<USDIAsyncOverlapEventGeneratorComponent>(TEXT("OverlapGenerator"));
}

