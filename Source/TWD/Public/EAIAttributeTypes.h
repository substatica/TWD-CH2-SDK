#pragma once
#include "CoreMinimal.h"
#include "EAIAttributeTypes.generated.h"

UENUM(BlueprintType)
enum class EAIAttributeTypes : uint8 {
    None,
    Random,
    Eat,
    Drink,
    Restroom,
    Money,
    SendMail,
    InterestA,
    InterestB,
    WorkStationA,
    WorkStationB,
    WorkStationC,
    WorkStationD,
    WorkStationE,
    DeadBody,
    TrashCan,
    CashRegisterA,
    CashRegisterB,
    CashRegisterC,
    ControlPanel,
    BeggingA,
    BeggingB,
    BeggingC,
    FoodVendorA,
    FoodVendorB,
    FoodVendorC,
    DrinkVendorA,
    DrinkVendorB,
    DrinkVendorC,
    RepairA,
    RepairB,
    RepairC,
    GuardA,
    GuardB,
    GuardC,
};

