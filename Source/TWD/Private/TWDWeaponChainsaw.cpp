#include "TWDWeaponChainsaw.h"
#include "SDIAsyncOverlapEventGeneratorComponent.h"
#include "Components/StaticMeshComponent.h"

class UPrimitiveComponent;
class AActor;
class UObject;


void ATWDWeaponChainsaw::ShowRefuelGuide() {
}

void ATWDWeaponChainsaw::OnChainsawBladeEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATWDWeaponChainsaw::OnChainsawBladeBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ATWDWeaponChainsaw::HideRefuelGuide() {
}

float ATWDWeaponChainsaw::GetFuelPropCurrencyAmountInternal(UObject* InventoryHolder) const {
    return 0.0f;
}

ATWDWeaponChainsaw::ATWDWeaponChainsaw() {
    this->OverlapGenerator = CreateDefaultSubobject<USDIAsyncOverlapEventGeneratorComponent>(TEXT("OverlapGenerator"));
    this->EnvironmentalEffectsRefreshTime = 0.05f;
    this->EnvironmentalSoundRefreshTime = 0.10f;
    this->BladeLength = 29.00f;
    this->BladeRadius = 6.00f;
    this->ReflectionAngle = 30.00f;
    this->bAllowWorldOverlap = false;
    this->FuelAmount = 0.00f;
    this->FuelCurrencyClass = NULL;
    this->bMotorIsOn = false;
    this->MotorOnDefaultMassInKg = -1.00f;
    this->MotorOnMassOverrideAlpha = 0.00f;
    this->ChainsawBladeCollisionComponent = NULL;
    this->ChainsawFXTimer = 0.00f;
    this->ChainsawSoundTimer = 0.00f;
    this->bSoundIsPlaying = false;
    this->SoundPlayEvent = NULL;
    this->SoundStopEvent = NULL;
    this->RefuelGuideMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RefuelGuideMesh"));
    this->ChainsawThreatDistance = 600.00f;
    this->ChainsawHighThreatDistance = 300.00f;
}

