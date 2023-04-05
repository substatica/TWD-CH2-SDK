#include "TWDNightModeLootHolder.h"
#include "Components/SceneComponent.h"

class ASDIInventoryActor;
class ATWDPlayerInventorySlot;

void ATWDNightModeLootHolder::SetSlotsVisible(bool NewVisible) {
}

void ATWDNightModeLootHolder::OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* NewInventory) {
}

ATWDNightModeLootHolder::ATWDNightModeLootHolder() {
    this->InventorySlotRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InventorySlotRoot"));
    this->LootInventoryTable = NULL;
}

