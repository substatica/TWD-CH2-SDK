#include "TWDAmmoProp.h"
#include "Templates/SubclassOf.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SDIPointGripComponent.h"

class UObject;
class ASDIInventoryActor;

ASDIInventoryActor* ATWDAmmoProp::GetCurrencyInstance(UObject* InventoryHolder, TSubclassOf<ASDIInventoryActor> CurrencyClass) {
    return NULL;
}

void ATWDAmmoProp::DropAmmoProp_Implementation() {
}

ATWDAmmoProp::ATWDAmmoProp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AmmoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmmoMesh"));
    this->GripLeft = CreateDefaultSubobject<USDIPointGripComponent>(TEXT("GripLeft"));
    this->GripRight = CreateDefaultSubobject<USDIPointGripComponent>(TEXT("GripRight"));
    this->InsertDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("InsertDirection"));
    this->AmmoCurrencyClass = NULL;
}

