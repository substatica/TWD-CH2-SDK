#include "TWDPawnShopDrawer.h"
#include "Components/SceneComponent.h"

class ASDIInventoryActor;
class ATWDPlayerInventorySlot;

void ATWDPawnShopDrawer::OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory) {
}

bool ATWDPawnShopDrawer::AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bShuffle, bool bForceCheckOnlyDontPlace) {
    return false;
}

ATWDPawnShopDrawer::ATWDPawnShopDrawer() {
    this->InventorySlotRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InventorySlotRoot"));
}

