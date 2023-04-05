#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIInventoryActor.h"
#include "TWDInventoryActorBlueprintInterface.h"
#include "TWDSeamlessTravelActorInterface.h"
#include "TWDInventoryActorInterface.h"
#include "TWDInteractiveHighlightInterface.h"
#include "TWDInventoryActorInterfaceData.h"
#include "TWDReplicatedInventoryActorInterfaceData.h"
#include "ETWDInventoryType.h"
#include "ETWDNonVREquipmentType.h"
#include "ETWDLootType.h"
#include "TWDProp.generated.h"

class UTWDAutoTickAkComponent;
class UAkAudioEvent;
class UStaticMeshComponent;
class ATWDBackpack;
class ASDIInventorySlot;

UCLASS()
class ATWDProp : public ASDIInventoryActor, public ITWDSeamlessTravelActorInterface, public ITWDInventoryActorInterface, public ITWDInteractiveHighlightInterface, public ITWDInventoryActorBlueprintInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UTWDAutoTickAkComponent* AkAudioComponent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FTWDInventoryActorInterfaceData TWDInventoryData;
    
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RepTWDInventoryData)
    FTWDReplicatedInventoryActorInterfaceData RepTWDInventoryData;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bBlockInventorySlotPlacement;
    
public:
    ATWDProp(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void StopAkAudioComponent();
    
    UFUNCTION(BlueprintCallable)
    void SetAkAudioComponentSwitch(const FString& SwitchGroup, const FString& SwitchState);
    
    UFUNCTION(BlueprintCallable)
    void SetAkAudioComponentRTPCValue(const FString& RTPC, float Value, int32 InterpolationTimeMs);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetInventorySlotIdx_IFC(uint8 InventorySlotIdx);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void ReturnKeyItemToBackpack();
    
    UFUNCTION(BlueprintCallable)
    int32 PostEventToAkAudioComponent(UAkAudioEvent* Event, const FString& EventName);
    
protected:
    UFUNCTION()
    void OnRep_RepTWDInventoryData_Timer();
    
    UFUNCTION()
    void OnRep_RepTWDInventoryData(const FTWDReplicatedInventoryActorInterfaceData& OldRepTWDInventoryData);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    FText GetCollectibleString() const;
    
    UFUNCTION(BlueprintCallable)
    UStaticMeshComponent* DuplicateStaticMesh(UStaticMeshComponent* Source);
    
    UFUNCTION(BlueprintPure)
    bool AkAudioComponentHasActiveEvents() const;
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool ShouldApplyPrimaryGripPitchOffsetUserSetting() const override PURE_VIRTUAL(ShouldApplyPrimaryGripPitchOffsetUserSetting, return false;);
    
    UFUNCTION(BlueprintCallable)
    void SetSerializationString(const FString& NewString) override PURE_VIRTUAL(SetSerializationString,);
    
    UFUNCTION(BlueprintCallable)
    void SetNearbyHighlightShown(bool bShown) override PURE_VIRTUAL(SetNearbyHighlightShown,);
    
    UFUNCTION()
    void OnRep_RepTWDInventoryData_Internal() override PURE_VIRTUAL(OnRep_RepTWDInventoryData_Internal,);
    
    UFUNCTION(BlueprintCallable)
    FTWDInventoryActorInterfaceData K2GetTWDInventoryData() const override PURE_VIRTUAL(K2GetTWDInventoryData, return FTWDInventoryActorInterfaceData{};);
    
    UFUNCTION(BlueprintCallable)
    bool IsNearbyHighlightShown() const override PURE_VIRTUAL(IsNearbyHighlightShown, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsInsideBackpack(ATWDBackpack*& Backpack) const override PURE_VIRTUAL(IsInsideBackpack, return false;);
    
    UFUNCTION(BlueprintCallable)
    FTransform GetTWDSlotTransform(ASDIInventorySlot* InvSlot, const ASDIInventoryActor* InterfaceImpl) const override PURE_VIRTUAL(GetTWDSlotTransform, return FTransform{};);
    
    UFUNCTION(BlueprintCallable)
    float GetThrowRating() const override PURE_VIRTUAL(GetThrowRating, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    float GetSharpnessRating() const override PURE_VIRTUAL(GetSharpnessRating, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    FString GetSerializationString() const override PURE_VIRTUAL(GetSerializationString, return TEXT(""););
    
    UFUNCTION(BlueprintCallable)
    ETWDNonVREquipmentType GetNonVREquipmentType() const override PURE_VIRTUAL(GetNonVREquipmentType, return ETWDNonVREquipmentType::None;);
    
    UFUNCTION(BlueprintCallable)
    FText GetLootTypeText() const override PURE_VIRTUAL(GetLootTypeText, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    ETWDLootType GetLootType() const override PURE_VIRTUAL(GetLootType, return ETWDLootType::Default;);
    
    UFUNCTION(BlueprintCallable)
    FText GetInventoryTypeText() const override PURE_VIRTUAL(GetInventoryTypeText, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    ETWDInventoryType GetInventoryType() const override PURE_VIRTUAL(GetInventoryType, return ETWDInventoryType::Default;);
    
    UFUNCTION(BlueprintCallable)
    uint8 GetInventorySlotIdx() const override PURE_VIRTUAL(GetInventorySlotIdx, return 0;);
    
    UFUNCTION(BlueprintCallable)
    void GetInventoryDisplayInfo(FText& Name, int32& Count, FText& Type, FText& NewDescription, FText& NewFlavorText, float& SharpnessRating, float& DurabilityRating, float& ThrowRating, bool& bStabbingAllowed, bool& bDismemberAllowed) const override PURE_VIRTUAL(GetInventoryDisplayInfo,);
    
    UFUNCTION(BlueprintCallable)
    float GetDurabilityRating() const override PURE_VIRTUAL(GetDurabilityRating, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    bool DropOnArmGrapple() const override PURE_VIRTUAL(DropOnArmGrapple, return false;);
    
};

