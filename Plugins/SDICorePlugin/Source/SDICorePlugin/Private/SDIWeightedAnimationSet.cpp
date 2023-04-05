#include "SDIWeightedAnimationSet.h"
#include "Templates/SubclassOf.h"

class USDIWeightedAnimationSetBase;

bool USDIWeightedAnimationSet::GetAnimationFromSet(const TSubclassOf<USDIWeightedAnimationSetBase>& AnimSetClass, FSDIWeightedAnimation& OutAnim) {
    return false;
}

bool USDIWeightedAnimationSet::GetAnimation(FSDIWeightedAnimation& OutAnim) const {
    return false;
}

USDIWeightedAnimationSet::USDIWeightedAnimationSet() {
}

