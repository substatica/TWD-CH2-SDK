#include "TWDAmmoPropArrow.h"
#include "TWDWeaponHitCapsuleComponent.h"
#include "SDISplineGripComponent.h"

class ATWDWeaponBowV2;

void ATWDAmmoPropArrow::SetNockedBow_Implementation(ATWDWeaponBowV2* Bow) {
}

void ATWDAmmoPropArrow::OnArrowLaunched_Implementation(const FVector& LaunchVelocity) {
}

void ATWDAmmoPropArrow::Launch_Implementation(ATWDWeaponBowV2* Bow, const FVector& LaunchVelocity) {
}

ATWDWeaponBowV2* ATWDAmmoPropArrow::GetNockedBow() const {
    return NULL;
}

ATWDAmmoPropArrow::ATWDAmmoPropArrow() {
    this->ArrowHitCapsule = CreateDefaultSubobject<UTWDWeaponHitCapsuleComponent>(TEXT("ArrowHitCapsule"));
    this->ShaftGripLeft = CreateDefaultSubobject<USDISplineGripComponent>(TEXT("ShaftGripLeft"));
    this->ShaftGripRight = CreateDefaultSubobject<USDISplineGripComponent>(TEXT("ShaftGripRight"));
    this->ShaftGripLeftFlip = CreateDefaultSubobject<USDISplineGripComponent>(TEXT("ShaftGripLeftFlip"));
    this->ShaftGripRightFlip = CreateDefaultSubobject<USDISplineGripComponent>(TEXT("ShaftGripRightFlip"));
    this->NockedStabMinTime = 0.50f;
    this->LaunchedMaxDuration = 5.00f;
    this->LaunchedMinVelocity = 1024.00f;
    this->MaxMergeDurabilityDelta = 1.00f;
    this->LaunchedTimestamp = 0.00f;
}

