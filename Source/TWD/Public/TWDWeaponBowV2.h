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
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* BowMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PrimaryGripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PrimaryGripRight;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* NockGripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* NockGripRight;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedPrimaryGripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedPrimaryGripRight;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedNockGripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* InvertedNockGripRight;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UCapsuleComponent* NockCapsule;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UCapsuleComponent* StringGrabCapsule;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* ArrowUILocation;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* LeftHandNockOffset;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* RightHandNockOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MinFirePullAmount;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float UnNockPullDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float UnNockMinNockedTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ReNockMinTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NockArrowMaxAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NockArrowGrabStringDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSet<TEnumAsByte<ECollisionChannel>> NockArrowIgnoreCollisionChannels;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve PullAmountCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve LaunchVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve LaunchDurabilityCostCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StaminaCostCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve PrimaryHandHapticsCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve SecondaryHandHapticsCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIAkAudioEventPairDynamicLoop DrawSoundLoop;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString DrawSoundLoopRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve DrawSoundLoopRTPCCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<TSubclassOf<ATWDAmmoPropArrow>, FTWDArrowAmmoUI> ArrowTypeMap;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FVector ArrowUIOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<EAxis::Type> ArrowUIFlipAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<EAxis::Type> ArrowUIInvertAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bGrabHighestDurabilityArrow;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAutoNockArrowWhenGrabbingString;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bPrioritizeGrabbingStringOverBow;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAimAssist;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AimAssistMinEngagePullAmount;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AimAssistPathCollisionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AimAssistPathCollisionTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AimAssistTargetRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve AimAssistTargetRadiusCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AimAssistTargetZOffset;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve AimAssistTargetZOffsetCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AimAssistMinDesiredSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform NockGripLeftRelTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform NockGripRightRelTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform InvertedNockGripLeftRelTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform InvertedNockGripRightRelTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
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
    ATWDWeaponBowV2(const FObjectInitializer& ObjectInitializer);
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

