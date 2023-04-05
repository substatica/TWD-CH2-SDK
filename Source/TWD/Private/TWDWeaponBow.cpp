#include "TWDWeaponBow.h"
#include "Templates/SubclassOf.h"

class ASDIInventoryActor;
class ATWDAmmoProp;

bool ATWDWeaponBow::ShouldUseArrowProps() const {
    return false;
}

TSubclassOf<ASDIInventoryActor> ATWDWeaponBow::GetArrowPropCurrencyClass() const {
    return NULL;
}

TSubclassOf<ATWDAmmoProp> ATWDWeaponBow::GetArrowPropClass() const {
    return NULL;
}

ATWDWeaponBow::ATWDWeaponBow() {
    this->ArrowPropClass = NULL;
    this->bUseArrowProps = false;
}

