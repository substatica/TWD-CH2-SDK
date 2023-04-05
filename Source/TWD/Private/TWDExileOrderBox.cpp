#include "TWDExileOrderBox.h"
#include "Components/SceneComponent.h"

class ASDIInventoryActor;
class ATWDPlayerInventorySlot;
class ASDIInventorySlot;

bool ATWDExileOrderBox::TryLateAssignExileOrderEvent() {
    return false;
}

bool ATWDExileOrderBox::SetBoxOpenState(bool bNewOpen, bool& bStateChanged) {
    return false;
}

bool ATWDExileOrderBox::SetBoxLockedState(bool bNewLocked, bool& bStateChanged) {
    return false;
}

void ATWDExileOrderBox::OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory) {
}

ASDIInventorySlot* ATWDExileOrderBox::FindEmptyInventorySlot(ASDIInventoryActor* InventoryActor, bool bShuffle) {
    return NULL;
}

bool ATWDExileOrderBox::AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bShuffle, bool bForceCheckOnlyDontPlace) {
    return false;
}

ATWDExileOrderBox::ATWDExileOrderBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InventorySlotRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InventorySlotRoot"));
    this->AssociatedExileOrderEvent = NULL;
    this->bBoxOpen = false;
    this->bBoxLocked = false;
    this->bStartLocked = false;
}

