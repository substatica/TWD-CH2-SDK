#include "TWDSkiff.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

class UPrimitiveComponent;
class AActor;
class ASDIInventoryActor;
class ATWDPlayerInventorySlot;

void ATWDSkiff::OnReadyForPlay() {
}

void ATWDSkiff::OnInventorySwapVolumeTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ATWDSkiff::OnInventorySlotContentChanged(ATWDPlayerInventorySlot* InvSlot, ASDIInventoryActor* CurrentInventory) {
}

void ATWDSkiff::LoadSlotContents() {
}

FName ATWDSkiff::GetPlayerStartTag() const {
    return NAME_None;
}

void ATWDSkiff::ActivateMagicSlots() {
}

ATWDSkiff::ATWDSkiff(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SkiffMesh"));
    this->bMagicSlotsEnabled = false;
    this->MagicSlotClass = NULL;
    this->MagicSlotRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MagicSlotRoot"));
    this->MagicSlotRadius = 5.00f;
    this->InventorySwapVolume = CreateDefaultSubobject<USphereComponent>(TEXT("SlotInventorySwapVolume"));
}

