#pragma once
#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "ESDIInteractiveInteractType.h"
#include "SDIRecoil.h"
#include "SDISpreadSettings.h"
#include "SDICameraRecoilSettings.h"
#include "SDIRecoilEntry.h"
#include "SDIComponentReplacement.h"
#include "UObject/NoExportTypes.h"
#include "SDIWeaponFirearmFiredShotInfo.h"
#include "SDIWeaponFirearmFireModeComponent.generated.h"

class UObject;
class USceneComponent;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIWeaponFirearmFireModeComponent : public UArrowComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIInteractiveInteractType DefaultInteractionType;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bRepeatingFire;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bVariableFireRate;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShotsPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShotsPerSecondTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bBurstFire;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 BurstShots;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float BurstShotsPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float SpreadDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIRecoil Recoil;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICameraRecoilSettings NonVRRecoil;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDICameraRecoilSettings NonVRRecoilADS;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISpreadSettings> SpreadSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISpreadSettings> PlayerSpreadSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISpreadSettings> NonVRPlayerSpreadSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAutoChamberNextRound;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* PrimaryStartFireFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* PrimaryRefireFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* PrimaryStopFireFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* PrimaryFireRoundFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* PrimaryDryFireFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* SecondaryStartFireFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* SecondaryRefireFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* SecondaryStopFireFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* SecondaryFireRoundFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* SecondaryDryFireFeedback;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsFiring;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bFiringRequested;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bFiringRequestHeld;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float RefireTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 BurstCounter;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float BurstTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 RoundsFired;
    
    UPROPERTY(Transient)
    TArray<FSDIRecoilEntry> TwoHandedRecoilEntries;
    
    UPROPERTY(Transient)
    TArray<FSDIRecoilEntry> PrimaryRecoilEntries;
    
    UPROPERTY(Transient)
    TArray<FSDIRecoilEntry> SecondaryRecoilEntries;
    
    UPROPERTY(Transient)
    FSDIComponentReplacement ComponentAttachment;
    
public:
    USDIWeaponFirearmFireModeComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateTickEnabled();
    
public:
    UFUNCTION(BlueprintCallable)
    void UpdateAttachmentInfo(USceneComponent* OldParent, USceneComponent* NewParent, const FName& NewParentSocketName);
    
    UFUNCTION(BlueprintCallable)
    void RequestStopFire();
    
    UFUNCTION(BlueprintCallable)
    void RequestFire();
    
    UFUNCTION(BlueprintPure)
    bool IsReadyToFire() const;
    
    UFUNCTION(BlueprintPure)
    bool IsFiring() const;
    
    UFUNCTION(BlueprintCallable)
    FTransform GetShotTransform(const FSDIWeaponFirearmFiredShotInfo& FiredShotInfo, bool bIgnoreSpread);
    
    UFUNCTION(BlueprintPure)
    UObject* GetSecondaryStopFireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetSecondaryStartFireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetSecondaryRefireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetSecondaryFireRoundFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetSecondaryDryFireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    FSDIRecoil GetRecoil(const FSDIWeaponFirearmFiredShotInfo& FiredShotInfo) const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetPrimaryStopFireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetPrimaryStartFireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetPrimaryRefireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetPrimaryFireRoundFeedback() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetPrimaryDryFireFeedback() const;
    
    UFUNCTION(BlueprintPure)
    FSDICameraRecoilSettings GetNonVRRecoil(const FSDIWeaponFirearmFiredShotInfo& FiredShotInfo) const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetFireModeTransform() const;
    
    UFUNCTION(BlueprintPure)
    FSDIComponentReplacement GetFireModeComponentAttachment() const;
    
    UFUNCTION(BlueprintPure)
    ESDIInteractiveInteractType GetDefaultInteractionType() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetBurstCounter() const;
    
    UFUNCTION(BlueprintPure)
    bool AutoChamberNextRound() const;
    
    UFUNCTION(BlueprintCallable)
    FTransform ApplySpread(const FSDIWeaponFirearmFiredShotInfo& FiredShotInfo, const FTransform& ShotTransform, float AdditionalSpread);
    
};

