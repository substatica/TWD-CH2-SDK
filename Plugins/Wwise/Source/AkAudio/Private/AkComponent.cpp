#include "AkComponent.h"

class UAkAuxBus;
class UAkSwitchValue;
class UAkRtpc;
class UAkComponent;
class UAkTrigger;
class UAkAudioEvent;

void UAkComponent::UseReverbVolumes(bool inUseReverbVolumes) {
}

void UAkComponent::UseEarlyReflections(UAkAuxBus* AuxBus, int32 Order, float BusSendGain, float MaxPathLength, bool SpotReflectors, const FString& AuxBusName) {
}

void UAkComponent::SetSwitch(UAkSwitchValue* SwitchValue, const FString& SwitchGroup, const FString& SwitchState) {
}

void UAkComponent::SetStopWhenOwnerDestroyed(bool bStopWhenOwnerDestroyed) {
}

void UAkComponent::SetRTPCValue(UAkRtpc* RTPCValue, float Value, int32 InterpolationTimeMs, const FString& RTPC) {
}

void UAkComponent::SetOutputBusVolume(float BusVolume) {
}

void UAkComponent::SetListeners(const TArray<UAkComponent*>& Listeners) {
}

void UAkComponent::SetEarlyReflectionsVolume(float SendVolume) {
}

void UAkComponent::SetEarlyReflectionsAuxBus(const FString& AuxBusName) {
}

void UAkComponent::SetAttenuationScalingFactor(float Value) {
}

void UAkComponent::PostTrigger(UAkTrigger* TriggerValue, const FString& Trigger) {
}

void UAkComponent::PostAssociatedAkEventAndWaitForEndAsync(int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
}

int32 UAkComponent::PostAssociatedAkEventAndWaitForEnd(const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
    return 0;
}

int32 UAkComponent::PostAkEventDefault(UAkAudioEvent* AKEvent) {
    return 0;
}

int32 UAkComponent::PostAkEventByName(const FString& in_EventName) {
    return 0;
}

void UAkComponent::PostAkEventAndWaitForEndAsync(UAkAudioEvent* AKEvent, int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
}

int32 UAkComponent::PostAkEventAndWaitForEnd(UAkAudioEvent* AKEvent, const FString& in_EventName, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
    return 0;
}

void UAkComponent::GetRTPCValue(UAkRtpc* RTPCValue, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType, const FString& RTPC, int32 PlayingID) {
}

float UAkComponent::GetAttenuationRadius() const {
    return 0.0f;
}

UAkComponent::UAkComponent() {
    this->bUseSpatialAudio = false;
    this->OcclusionCollisionChannel = ECC_GameTraceChannel18;
    this->EnableSpotReflectors = false;
    this->EarlyReflectionAuxBus = NULL;
    this->EarlyReflectionOrder = 0;
    this->EarlyReflectionBusSendGain = 1.00f;
    this->EarlyReflectionMaxPathLength = 0.00f;
    this->roomReverbAuxBusGain = 0.00f;
    this->diffractionMaxEdges = 0;
    this->diffractionMaxPaths = 0;
    this->diffractionMaxPathLength = 0.00f;
    this->DrawFirstOrderReflections = false;
    this->DrawSecondOrderReflections = false;
    this->DrawHigherOrderReflections = false;
    this->DrawDiffraction = false;
    this->StopWhenOwnerDestroyed = true;
    this->AttenuationScalingFactor = 1.00f;
    this->OcclusionRefreshInterval = 0.00f;
    this->bUseReverbVolumes = true;
}

