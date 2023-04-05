#include "AIAttribute.h"

FAIAttribute::FAIAttribute() {
    this->Type = EAIAttributeTypes::None;
    this->Current = 0.00f;
    this->Rate = 0.00f;
    this->Max = 0.00f;
    this->RandMax = 0.00f;
    this->RandMin = 0.00f;
    this->GOBUrgeMultiplier = 0.00f;
    this->GOBUrgeAdder = 0.00f;
}

