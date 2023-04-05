#include "SDICoreLookAtActor.h"
#include "AkComponent.h"
#include "Components/SphereComponent.h"

class UPrimitiveComponent;
class ACharacter;
class AActor;

void ASDICoreLookAtActor::SetActive(bool bActive) {
}

void ASDICoreLookAtActor::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASDICoreLookAtActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool ASDICoreLookAtActor::IsEngaged(ACharacter*& OutCharacter, float& OutTime) const {
    return false;
}

bool ASDICoreLookAtActor::IsActive() const {
    return false;
}

void ASDICoreLookAtActor::EngageLookAt_Implementation(ACharacter* LookAtChar) {
}

void ASDICoreLookAtActor::DisengageLookAt_Implementation(ACharacter* LookAtChar) {
}

ASDICoreLookAtActor::ASDICoreLookAtActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
    this->AkAudioComponent = CreateDefaultSubobject<UAkComponent>(TEXT("AkAudioComponent"));
    this->EngageAngleDegrees = 15.00f;
    this->DisengageAngleDegrees = 20.00f;
    this->MinEngagedTime = 0.00f;
    this->ReEngageDelay = 0.00f;
    this->bReEngageRequiresDisengage = false;
    this->LosChannel = ECC_Visibility;
    this->LosRadius = 0.00f;
    this->bStartActive = true;
    this->EngagedTimestamp = 0.00f;
    this->ReEngageTimestamp = 0.00f;
}

