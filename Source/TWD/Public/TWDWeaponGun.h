#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDDurabilityInterface.h"
#include "SDIWeaponFirearm.h"
#include "TWDSeamlessTravelActorInterface.h"
#include "TWDInventoryActorInterface.h"
#include "TWDTimeDilationActorInterface.h"
#include "TWDReplicatedInventoryActorInterfaceData.h"
#include "TWDInventoryActorInterfaceData.h"
#include "TWDInteractiveHighlightInterface.h"
#include "UObject/NoExportTypes.h"
#include "TWDInventoryActorBlueprintInterface.h"
#include "TWDDurabilityInterfaceData.h"
#include "TWDReplicatedDurabilityInterfaceData.h"
#include "Engine/EngineTypes.h"
#include "TWDTimeDilationActorData.h"
#include "ETWDLootType.h"
#include "SDICameraSwaySettings.h"
#include "RFloatExp.h"
#include "Curves/CurveFloat.h"
#include "RIntExp.h"
#include "SDICurveAnimation.h"
#include "SDIComponentReplacement.h"
#include "EWeaponAnimation.h"
#include "SDITuningAttribute_TWDWeaponGun.h"
#include "ESDIInteractiveInteractType.h"
#include "ETWDInventoryType.h"
#include "ETWDNonVREquipmentType.h"
#include "TWDWeaponGun.generated.h"

class ASDIInventorySlot;
class UTWDAutoTickAkComponent;
class UCapsuleComponent;
class ASDIInventoryActor;
class ATWDAmmoProp;
class UTWDWeaponShoveComponent;
class USceneComponent;
class UObject;
class ATWDProp;
class USDIAsyncOverlapEventGeneratorComponent;
class UArrowComponent;
class UAkAudioEvent;
class AActor;
class ATWDWeaponActorAttachmentEditor;
class ATWDWeaponGun;
class ASDIWeaponFirearmAmmo;
class UPrimitiveComponent;
class ATWDCharacter;
class ATWDBackpack;

UCLASS()
class ATWDWeaponGun : public ASDIWeaponFirearm, public ITWDSeamlessTravelActorInterface, public ITWDInventoryActorInterface, public ITWDTimeDilationActorInterface, public ITWDInteractiveHighlightInterface, public ITWDDurabilityInterface, public ITWDInventoryActorBlueprintInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDAutoTickAkComponent* AkAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDWeaponShoveComponent* WeaponShoveComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDInventoryActorInterfaceData TWDInventoryData;
    
    UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_RepTWDInventoryData)
    FTWDReplicatedInventoryActorInterfaceData RepTWDInventoryData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDDurabilityInterfaceData TWDDurabilityData;
    
    UPROPERTY(ReplicatedUsing=OnRep_RepTWDDurabilityData)
    FTWDReplicatedDurabilityInterfaceData RepTWDDurabilityData;
    
    UPROPERTY(EditAnywhere, Replicated)
    FTWDTimeDilationActorData RepTimeDilationData;
    
    UPROPERTY(EditAnywhere, Replicated)
    FTWDTimeDilationActorData RepPlayerTimeDilationData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float FireNoiseRadius;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* ReloadClipLocation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* ReloadClipFeedback;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UCapsuleComponent* ReloadCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIAsyncOverlapEventGeneratorComponent* ReloadCollisionOverlapGenerator;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UArrowComponent* ReloadDirection;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ReloadConeAngle;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* FiredRoundAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* DryFireAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* JammedFireAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* SuppressedFireAudioEvent;
    
    UPROPERTY(EditDefaultsOnly)
    FSDICameraSwaySettings NonVRWindedGunAimSway;
    
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ATWDAmmoProp> ReloadAmmoPropClass;
    
protected:
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<ATWDAmmoProp>> ActiveAmmoProps;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bReloadWithSingleRound;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDropReloadPropWhenClipUnloaded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp DurabilityCostPerShot;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve DurabilityJamChance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve DurabilityAdditionalSpreadDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRIntExp DurabilityUnJamActionCount;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ATWDProp> BrokenReplacementPropClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICurveAnimation ADSAccuracyCurveAnim;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve FiringAccuracyCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICurveAnimation WindedAccuracyModifierCurveAnim;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ATWDWeaponActorAttachmentEditor* AttachmentEditor;
    
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_bRepGunJammed)
    bool bRepGunJammed;
    
    UPROPERTY(BlueprintReadWrite, Replicated, Transient)
    int32 RepDurabilityUnJamActionCounter;
    
    UPROPERTY(Transient)
    FSDIComponentReplacement ReloadClipLocationReplacement;
    
    UPROPERTY(Transient)
    FSDIComponentReplacement ReloadDirectionReplacement;
    
    UPROPERTY(Transient)
    TArray<float> FiringAccuracyCurveTimes;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CurrentAccuracy;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAccuracyIsAnimating;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bSuppressed;
    
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EWeaponAnimation WeaponAnimType;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIsRevolver;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bPlatformDoEjectClipOnDryFire;
    
    ATWDWeaponGun(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    ATWDWeaponGun* TuneTWDWeaponGun(FSDITuningAttribute_TWDWeaponGun Attr, float PreModifier, float Add, float PostModifier);
    
    UFUNCTION(BlueprintCallable)
    void StopAkAudioComponent();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetJammed(bool bJammed, int32 UnJamActionCounter);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetAkAudioComponentSwitch(const FString& SwitchGroup, const FString& SwitchState);
    
    UFUNCTION(BlueprintCallable)
    void SetAkAudioComponentRTPCValue(const FString& RTPC, float Value, int32 InterpolationTimeMs);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetJammed(bool bJammed, int32 UnJamActionCounter);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetInventorySlotIdx_IFC(uint8 InventorySlotIdx);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDropAmmoProp(int32 AmmoToDrop, AActor* PropOwner, const FTransform& DropTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReloadSingleRound(TSubclassOf<ASDIWeaponFirearmAmmo> AmmoClass, int32 NewAmmoCount);
    
public:
    UFUNCTION(BlueprintPure)
    bool PredictFireModeTransform(ESDIInteractiveInteractType Type, FTransform& OutTransform) const;
    
    UFUNCTION(BlueprintCallable)
    int32 PostEventToAkAudioComponent(UAkAudioEvent* Event, const FString& EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool PerformUnJamAction();
    
protected:
    UFUNCTION()
    void OnRep_RepTWDInventoryData_Timer();
    
    UFUNCTION()
    void OnRep_RepTWDInventoryData(const FTWDReplicatedInventoryActorInterfaceData& OldRepTWDInventoryData);
    
    UFUNCTION()
    void OnRep_RepTWDDurabilityData(const FTWDReplicatedDurabilityInterfaceData& OldRepTWDDurabilityData);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnRep_bRepGunJammed(bool OldbRepGunJammed);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnReloadCollisionEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnReloadCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintPure)
    bool NeedsReloading() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsThreat(ATWDCharacter* Character);
    
    UFUNCTION(BlueprintPure)
    bool IsJammed() const;
    
    UFUNCTION(BlueprintPure)
    bool IsHipFiring() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsHighThreat(ATWDCharacter* Character);
    
    UFUNCTION(BlueprintPure)
    bool IsCompatibleAmmoProp(const ATWDAmmoProp* AmmoProp) const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool IsClipEjectedOrChamberOpen() const;
    
    UFUNCTION(BlueprintPure)
    bool GetReloadWithSingleRound() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetAmmoPropCurrencyCount() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<ASDIInventoryActor> GetAmmoPropCurrencyClass() const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool CanBeLoaded() const;
    
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
    
    UFUNCTION()
    void OnRep_RepTWDDurabilityData_Internal(const FTWDReplicatedDurabilityInterfaceData& OldRepTWDInventoryData) override PURE_VIRTUAL(OnRep_RepTWDDurabilityData_Internal,);
    
};

