#pragma once
#include "CoreMinimal.h"
#include "InventorySlotContentChangedDelegate.generated.h"

class ASDIInventoryActor;
class ATWDPlayerInventorySlot;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInventorySlotContentChanged, ATWDPlayerInventorySlot*, InventorySlot, ASDIInventoryActor*, CurrentInventory);

