#include "EGOAIConsideration.h"

FEGOAIConsideration::FEGOAIConsideration() {
    this->Disable = false;
    this->EditAdvance = false;
    this->TestType = EEGOAITestTypes::None;
    this->TestMax = 0.00f;
    this->TestMin = 0.00f;
    this->TestAttributeType = EAIAttributeTypes::None;
    this->TestTargetState = EEGOAIActionTypes::NoAction;
    this->bCanCacheTestCustomBP = false;
    this->GraphType = EEGOAIGraphTypes::None;
    this->GraphM = 0.00f;
    this->GraphK = 0.00f;
    this->GraphB = 0.00f;
    this->GraphC = 0.00f;
}

