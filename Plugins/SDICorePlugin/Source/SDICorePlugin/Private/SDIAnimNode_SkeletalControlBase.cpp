#include "SDIAnimNode_SkeletalControlBase.h"

FSDIAnimNode_SkeletalControlBase::FSDIAnimNode_SkeletalControlBase() {
    this->Alpha = 0.00f;
    this->bIgnoreTimeDilation = false;
    this->ActualAlpha = 0.00f;
    this->RootIndex = 0;
    this->ActorCustomTimeDilation = 0.00f;
    this->bIsRelevant = false;
}

