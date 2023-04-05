#include "TWDFogFadeCorridor.h"
#include "Components/BoxComponent.h"

class UPrimitiveComponent;
class AActor;

void ATWDFogFadeCorridor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATWDFogFadeCorridor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ATWDFogFadeCorridor::Initialize() {
}

ATWDFogFadeCorridor::ATWDFogFadeCorridor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
    this->TargetFog = NULL;
    this->ActiveTargetFog = NULL;
    this->bForceEntryValue = false;
    this->ValueOnEnter = 1.00f;
    this->ValueOnExit = 0.05f;
    this->CurrentValue = 0.00f;
    this->TargetValue = 1.00f;
    this->ValueChangeRate = 1.00f;
    this->LastProgress = 0.00f;
    this->EntryValue = 0.00f;
}

