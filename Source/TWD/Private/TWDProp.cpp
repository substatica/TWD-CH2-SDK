#include "TWDProp.h"
#include "Net/UnrealNetwork.h"
#include "TWDAutoTickAkComponent.h"

class UStaticMeshComponent;
class UAkAudioEvent;

void ATWDProp::StopAkAudioComponent() {
}

void ATWDProp::SetAkAudioComponentSwitch(const FString& SwitchGroup, const FString& SwitchState) {
}

void ATWDProp::SetAkAudioComponentRTPCValue(const FString& RTPC, float Value, int32 InterpolationTimeMs) {
}

void ATWDProp::ServerSetInventorySlotIdx_IFC_Implementation(uint8 InventorySlotIdx) {
}
bool ATWDProp::ServerSetInventorySlotIdx_IFC_Validate(uint8 InventorySlotIdx) {
    return true;
}

void ATWDProp::ReturnKeyItemToBackpack_Implementation() {
}

int32 ATWDProp::PostEventToAkAudioComponent(UAkAudioEvent* Event, const FString& EventName) {
    return 0;
}

void ATWDProp::OnRep_RepTWDInventoryData_Timer() {
}

void ATWDProp::OnRep_RepTWDInventoryData(const FTWDReplicatedInventoryActorInterfaceData& OldRepTWDInventoryData) {
}

FText ATWDProp::GetCollectibleString_Implementation() const {
    return FText::GetEmpty();
}

UStaticMeshComponent* ATWDProp::DuplicateStaticMesh(UStaticMeshComponent* Source) {
    return NULL;
}

bool ATWDProp::AkAudioComponentHasActiveEvents() const {
    return false;
}

void ATWDProp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATWDProp, RepTWDInventoryData);
}

ATWDProp::ATWDProp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AkAudioComponent = CreateDefaultSubobject<UTWDAutoTickAkComponent>(TEXT("AkAudioComponent"));
    this->bBlockInventorySlotPlacement = false;
}

