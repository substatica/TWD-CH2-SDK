#include "SDICoreFXManager.h"

class UObject;
class ULightComponent;
class ASDICoreFXManager;
class UCurveFloat;

void ASDICoreFXManager::RemoveLightFlicker(ULightComponent* LightComponent) {
}

ASDICoreFXManager* ASDICoreFXManager::GetFXManager(const UObject* WorldContextObject) {
    return NULL;
}

void ASDICoreFXManager::AddLightFlicker(ULightComponent* LightComponent, UCurveFloat* IntensityCurve, float StartTime, bool bLooping) {
}

ASDICoreFXManager::ASDICoreFXManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxLightFlickerUpdatesPerFrame = 0;
    this->LightFlickerUpdateIndex = 0;
}

