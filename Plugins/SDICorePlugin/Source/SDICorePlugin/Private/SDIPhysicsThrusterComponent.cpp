#include "SDIPhysicsThrusterComponent.h"

class USDIPhysicsThrusterComponent;
class UPrimitiveComponent;
class AActor;
class UCurveBase;

void USDIPhysicsThrusterComponent::RemoveThrusterFrom(UPrimitiveComponent* Comp, int32 ID) {
}

USDIPhysicsThrusterComponent* USDIPhysicsThrusterComponent::GetThrusterComponentFor(AActor* Actor, bool bCreate) {
    return NULL;
}

int32 USDIPhysicsThrusterComponent::AddThrusterTo(UPrimitiveComponent* Comp, FName BodyName, const FTransform& WorldTransform, bool bAttached, bool bAccelChange, float Force, float Duration, int32 LoopCount, bool bCreate) {
    return 0;
}

int32 USDIPhysicsThrusterComponent::AddAnimatedThrusterTo(UPrimitiveComponent* Comp, FName BodyName, const FTransform& WorldTransform, bool bAttached, bool bAccelChange, UCurveBase* ForceCurve, float ForceCurveScale, int32 LoopCount, bool bCreate) {
    return 0;
}

USDIPhysicsThrusterComponent::USDIPhysicsThrusterComponent() {
    this->bDynamicallyCreated = false;
}

