#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDWeaponBow.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "TWDArrowAmmoUI.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDWeaponBowV2.generated.h"

class USDIPointGripComponent;
class USkeletalMeshComponent;
class UCapsuleComponent;
class USceneComponent;
class ATWDAmmoPropArrow;
class ASDIInventoryActor;
class UAkComponent;
class UTWDWidgetComponent;
class UObject;

UCLASS()
class TWD_API ATWDWeaponBowV2 : public ATWDWeaponBow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* BowMesh;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PrimaryGripLeft;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PrimaryGripRight;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* NockGripLeft;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* NockGripRight;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedPrimaryGripLeft;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedPrimaryGripRight;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedNockGripLeft;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedNockGripRight;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UCapsuleComponent* NockCapsule;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UCapsuleComponent* StringGrabCapsule;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* ArrowUILocation;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* LeftHandNockOffset;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* RightHandNockOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MinFirePullAmount;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float UnNockPullDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float UnNockMinNockedTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ReNockMinTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NockArrowMaxAngleDeg;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NockArrowGrabStringDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TSet<TEnumAsByte<ECollisionChannel>> NockArrowIgnoreCollisionChannels;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve PullAmountCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve LaunchVelocityCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve LaunchDurabilityCostCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve StaminaCostCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve PrimaryHandHapticsCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve SecondaryHandHapticsCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop DrawSoundLoop;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FString DrawSoundLoopRTPC;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve DrawSoundLoopRTPCCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<TSubclassOf<ATWDAmmoPropArrow>, FTWDArrowAmmoUI> ArrowTypeMap;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FVector ArrowUIOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TEnumAsByte<EAxis::Type> ArrowUIFlipAxis;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TEnumAsByte<EAxis::Type> ArrowUIInvertAxis;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bGrabHighestDurabilityArrow;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAutoNockArrowWhenGrabbingString;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bPrioritizeGrabbingStringOverBow;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAimAssist;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float AimAssistMinEngagePullAmount;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float AimAssistPathCollisionRadius;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float AimAssistPathCollisionTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float AimAssistTargetRadius;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve AimAssistTargetRadiusCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float AimAssistTargetZOffset;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FRuntimeFloatCurve AimAssistTargetZOffsetCurve;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float AimAssistMinDesiredSpeed;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform NockGripLeftRelTransform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform NockGripRightRelTransform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform InvertedNockGripLeftRelTransform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform InvertedNockGripRightRelTransform;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FTransform ArrowUILocationRelTransform;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDAmmoPropArrow> NockedArrow;
    
    UPROPERTY(Transient)
    TArray<TEnumAsByte<ECollisionChannel>> NockedArrowCollisionChannelIgnorances;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDAmmoPropArrow> LastUnNockedArrow;
    
    UPROPERTY(Transient)
    float LastUnNockedArrowTimestamp;
    
    UPROPERTY(Transient)
    bool bCanUnNockArrowFromPull;
    
    UPROPERTY(Transient)
    float NockedArrowTimestamp;
    
    UPROPERTY(Transient)
    bool bUnNockGrabbingArrow;
    
    UPROPERTY(Transient)
    float LastPullAmount;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TMap<UAkComponent*, FSDIAkAudioEventPairDynamicLoop> DrawSoundLoopComponentPairs;
    
public:
    ATWDWeaponBowV2();
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateAmmoWidget(UTWDWidgetComponent* WidgetComponent, TSubclassOf<ATWDAmmoPropArrow> ArrowType, int32 ArrowCount);
    
public:
    UFUNCTION(BlueprintCallable)
    ATWDAmmoPropArrow* UnNockArrow(bool bGrabArrow);
    
    UFUNCTION(BlueprintCallable)
    bool NockArrow(ATWDAmmoPropArrow* Arrow, bool bGrabString);
    
    UFUNCTION(BlueprintPure)
    bool IsValidArrowType(UClass* ArrowType) const;
    
    UFUNCTION(BlueprintPure)
    bool IsGripInverted() const;
    
    UFUNCTION(BlueprintPure)
    float GetPullDistance() const;
    
    UFUNCTION(BlueprintPure)
    float GetPullAmount() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetNockTransform(bool bIncludeSideOffset) const;
    
    UFUNCTION(BlueprintPure)
    float GetNockedArrowTime() const;
    
    UFUNCTION(BlueprintPure)
    ATWDAmmoPropArrow* GetNockedArrow() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetArrowDirection(bool bIncludeSideOffset) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetArrowCount(UObject* InventoryHolder, TSubclassOf<ATWDAmmoPropArrow> ArrowType) const;
    
    UFUNCTION(BlueprintPure)
    ASDIInventoryActor* GetAmmoPropArrow(UObject* InventoryHolder, TSubclassOf<ATWDAmmoPropArrow> ArrowType) const;
    
    UFUNCTION(BlueprintCallable)
    bool AttemptNockArrow(ATWDAmmoPropArrow* Arrow);
    
};

