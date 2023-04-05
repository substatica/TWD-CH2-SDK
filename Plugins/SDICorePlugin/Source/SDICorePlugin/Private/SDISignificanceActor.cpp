#include "SDISignificanceActor.h"

class UObject;

float ASDISignificanceActor::SignificanceFunction(UObject* QueryObj, const FTransform& ViewerTransform) {
    return 0.0f;
}

ASDISignificanceActor::ASDISignificanceActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SignificanceTag = TEXT("SDISignificanceActor");
}

