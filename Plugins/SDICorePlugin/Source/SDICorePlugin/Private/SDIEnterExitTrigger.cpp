#include "SDIEnterExitTrigger.h"
#include "SDIAsyncOverlapEventGeneratorComponent.h"

class UPrimitiveComponent;
class AActor;

void ASDIEnterExitTrigger::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASDIEnterExitTrigger::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

ASDIEnterExitTrigger::ASDIEnterExitTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EnterOverlapGenerator = CreateDefaultSubobject<USDIAsyncOverlapEventGeneratorComponent>(TEXT("EnterOverlapGenerator"));
    this->ExitOverlapGenerator = CreateDefaultSubobject<USDIAsyncOverlapEventGeneratorComponent>(TEXT("ExitOverlapGenerator"));
}

