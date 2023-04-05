#pragma once
#include "CoreMinimal.h"
#include "AkGameObject.h"
#include "AkOcclusionObstructionContainerQueryInterface.h"
#include "Engine/EngineTypes.h"
#include "SwitchMapKey.h"
#include "RTPCMapKey.h"
#include "AkExternalSourceInfo.h"
#include "Engine/LatentActionManager.h"
#include "ERTPCValueType.h"
#include "AkComponent.generated.h"

class UAkSwitchValue;
class UAkAuxBus;
class UAkRtpc;
class UAkComponent;
class UAkTrigger;
class UAkAudioEvent;

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkComponent : public UAkGameObject, public IAkOcclusionObstructionContainerQueryInterface {
    GENERATED_BODY()
public:
    UPROPERTY()
    bool bUseSpatialAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TEnumAsByte<ECollisionChannel> OcclusionCollisionChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    uint8 EnableSpotReflectors: 1;
    
private:
    UPROPERTY(EditAnywhere)
    UAkAuxBus* EarlyReflectionAuxBus;
    
    UPROPERTY(EditAnywhere)
    FString EarlyReflectionAuxBusName;
    
    UPROPERTY(VisibleAnywhere)
    int32 EarlyReflectionOrder;
    
    UPROPERTY(EditAnywhere)
    float EarlyReflectionBusSendGain;
    
    UPROPERTY(VisibleAnywhere)
    float EarlyReflectionMaxPathLength;
    
    UPROPERTY(VisibleAnywhere)
    float roomReverbAuxBusGain;
    
    UPROPERTY(VisibleAnywhere)
    int32 diffractionMaxEdges;
    
    UPROPERTY(VisibleAnywhere)
    int32 diffractionMaxPaths;
    
    UPROPERTY(VisibleAnywhere)
    float diffractionMaxPathLength;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    uint8 DrawFirstOrderReflections: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    uint8 DrawSecondOrderReflections: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    uint8 DrawHigherOrderReflections: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    uint8 DrawDiffraction: 1;
    
    UPROPERTY()
    bool StopWhenOwnerDestroyed;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float AttenuationScalingFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float OcclusionRefreshInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUseReverbVolumes;
    
    UPROPERTY(Transient)
    TMap<FSwitchMapKey, FString> SwitchMap;
    
    UPROPERTY(Transient)
    TMap<FRTPCMapKey, float> RTPCMap;
    
    UAkComponent();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void UseReverbVolumes(bool inUseReverbVolumes);
    
    UFUNCTION(BlueprintCallable)
    void UseEarlyReflections(UAkAuxBus* AuxBus, int32 Order, float BusSendGain, float MaxPathLength, bool SpotReflectors, const FString& AuxBusName);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSwitch(UAkSwitchValue* SwitchValue, const FString& SwitchGroup, const FString& SwitchState);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetStopWhenOwnerDestroyed(bool bStopWhenOwnerDestroyed);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetRTPCValue(UAkRtpc* RTPCValue, float Value, int32 InterpolationTimeMs, const FString& RTPC);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetOutputBusVolume(float BusVolume);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetListeners(const TArray<UAkComponent*>& Listeners);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetEarlyReflectionsVolume(float SendVolume);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetEarlyReflectionsAuxBus(const FString& AuxBusName);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetAttenuationScalingFactor(float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void PostTrigger(UAkTrigger* TriggerValue, const FString& Trigger);
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    void PostAssociatedAkEventAndWaitForEndAsync(int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    int32 PostAssociatedAkEventAndWaitForEnd(const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    int32 PostAkEventDefault(UAkAudioEvent* AKEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    int32 PostAkEventByName(const FString& in_EventName);
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    void PostAkEventAndWaitForEndAsync(UAkAudioEvent* AKEvent, int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    int32 PostAkEventAndWaitForEnd(UAkAudioEvent* AKEvent, const FString& in_EventName, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void GetRTPCValue(UAkRtpc* RTPCValue, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType, const FString& RTPC, int32 PlayingID);
    
    UFUNCTION(BlueprintCosmetic, BlueprintPure)
    float GetAttenuationRadius() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

