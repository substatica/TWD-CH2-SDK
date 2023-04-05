#include "TWDExileOrderEvent.h"
#include "Templates/SubclassOf.h"

class UObject;
class UTWDExileOrder;
class ASDIInventoryActor;

bool UTWDExileOrderEvent::IsOrderSatisfiedByHolder(UObject* RequirementHolder) const {
    return false;
}

bool UTWDExileOrderEvent::IsAssigned() const {
    return false;
}

TSubclassOf<UTWDExileOrder> UTWDExileOrderEvent::GetOrderClass() const {
    return NULL;
}

bool UTWDExileOrderEvent::DebugTakeRequirements(UObject* FromRequirementHolder) {
    return false;
}

void UTWDExileOrderEvent::DebugHandleOrderExchange(UObject* FromRequirementHolder, UObject* ToRewardHolder, bool& bSuccess, TArray<ASDIInventoryActor*>& RewardedInv) {
}

TArray<ASDIInventoryActor*> UTWDExileOrderEvent::DebugGiveRewards(UObject* ToRewardHolder) {
    return TArray<ASDIInventoryActor*>();
}

UTWDExileOrderEvent::UTWDExileOrderEvent() {
    this->bDeliveryComplete = false;
    this->bRewardClaimed = false;
    this->OrderClassTable = NULL;
    this->AssignedOrderClass = NULL;
}

