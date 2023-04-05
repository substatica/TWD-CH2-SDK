#include "TWDStashBox.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"

class ASDIInventoryActor;
class ATWDPlayerInventorySlot;
class ASDIInventorySlot;

void ATWDStashBox::TransferFromPlayerInventory() {
}

void ATWDStashBox::OnStashContentChanged_Implementation() {
}

void ATWDStashBox::OnPageFlip_Implementation(int32 PrevPageIndex, int32 CurrentPageIndex) {
}

void ATWDStashBox::OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory) {
}

void ATWDStashBox::GoToPrevPage() {
}

void ATWDStashBox::GoToPage(int32 PageIndex) {
}

void ATWDStashBox::GoToNextPage() {
}

ASDIInventorySlot* ATWDStashBox::FindEmptyInventorySlot(ASDIInventoryActor* InventoryActor, int32& OutPage) {
    return NULL;
}

void ATWDStashBox::CheckForPageAutoAdvance() {
}

bool ATWDStashBox::AutoPlaceInventory(ASDIInventoryActor* InventoryActor, bool bForceCheckOnlyDontPlace) {
    return false;
}

ATWDStashBox::ATWDStashBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActivePageIndex = 0;
    this->AvailablePages = 1;
    this->InventorySlotBlueprint = NULL;
    this->InventorySlotRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InventorySlotRoot"));
    this->InventoryUIRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InventoryUIRoot"));
    this->InventorySlotRadius = 5.00f;
    this->NextPageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("NextPageCollision"));
    this->PrevPageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PrevPageCollision"));
    this->bEnableAutoAdvance = true;
    this->AutoAdvanceCheckDelay = 1.00f;
}

