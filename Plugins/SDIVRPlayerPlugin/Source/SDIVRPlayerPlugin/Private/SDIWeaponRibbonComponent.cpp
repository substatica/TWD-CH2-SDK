#include "SDIWeaponRibbonComponent.h"

USDIWeaponRibbonComponent::USDIWeaponRibbonComponent() {
    this->bRenderOnlyForDamage = true;
    this->bWeaponCouldCauseDamage = false;
    this->WeaponDamageValue = 0.00f;
    this->LastWeaponDamageTimestamp = 0.00f;
}

