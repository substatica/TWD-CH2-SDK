#include "TWDLookActor.h"
#include "Components/StaticMeshComponent.h"
#include "TWDAutoTickAkComponent.h"

ATWDLookActor::ATWDLookActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StartLookingAudioEvent = NULL;
    this->LookingLoopPlayAudioEvent = NULL;
    this->LookingLoopStopAudioEvent = NULL;
    this->FinishLookingAudioEvent = NULL;
    this->LookMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LookMeshComponent"));
    this->LookMaterialInstance = NULL;
    this->AkAudioComponent = CreateDefaultSubobject<UTWDAutoTickAkComponent>(TEXT("AkAudioComponent"));
}

