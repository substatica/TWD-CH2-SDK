#pragma once
#include "CoreMinimal.h"
#include "SDIPlayerHandAdvanced.h"
#include "TWDSeamlessTravelActorInterface.h"
#include "EGender.h"
#include "SkinDataVariantList.h"
#include "Curves/CurveFloat.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerHandLock.h"
#include "Engine/EngineTypes.h"
#include "TWDPlayerHand.generated.h"

class UObject;
class UPrimitiveComponent;
class UTWDInventoryDataWidget;
class UTWDWidgetComponent;
class ASDIInventoryActor;
class ASDIInventorySlot;
class AActor;

UCLASS()
class ATWDPlayerHand : public ASDIPlayerHandAdvanced, public ITWDSeamlessTravelActorInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<EGender, FSkinDataVariantList> GenderSkinVariantLists;
    
    UPROPERTY(EditAnywhere)
    UObject* StaminaDrainLoopFeedback;
    
    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve StaminaDrainLoopFeedbackCurve;
    
    UPROPERTY(EditAnywhere)
    UObject* StaminaActionFailedFeedback;
    
    UPROPERTY(EditAnywhere)
    UObject* StaminaActionEndedFeedback;
    
    UPROPERTY(EditAnywhere)
    float GrappledStabCooldown;
    
    UPROPERTY(EditAnywhere)
    float DismemberStabCooldown;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDWidgetComponent* PauseWidgetComponent;
    
    UPROPERTY(EditAnywhere)
    UObject* PauseButtonPressFeedback;
    
    UPROPERTY(Transient)
    FTransform IKThrowTransform;
    
    UPROPERTY(Transient)
    FVector IKThrowAxis;
    
    UPROPERTY(Transient)
    FVector IKThrowVelocity;
    
    UPROPERTY(Transient)
    FVector IKThrowCenter;
    
    UPROPERTY(Transient)
    float IKThrowInterp;
    
    UPROPERTY(Transient)
    FSDIPlayerHandLock IKThrowLock;
    
    UPROPERTY(Transient)
    TArray<FTransform> SimulatedMovementPath;
    
    UPROPERTY(Transient)
    float SimulatedMovementDuration;
    
    UPROPERTY(Transient)
    float SimulatedMovementTime;
    
    UPROPERTY(Transient)
    FSDIPlayerHandLock SimulatedMovementLock;
    
    UPROPERTY(Transient)
    int32 StaminaDrainLoopFeedbackId;
    
    UPROPERTY(Transient)
    float LastStaminaPct;
    
    UPROPERTY(Transient)
    float StabCooldown;
    
    UPROPERTY(Transient)
    bool bGoofyFingerGunFired;
    
    UPROPERTY(Transient)
    bool bGoofyFingerGunReadyToFire;
    
    UPROPERTY(Transient)
    float LastPhysicalHandMeshHitTimeStamp;
    
    UPROPERTY(Transient)
    float LastHeldActorHitTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDWidgetComponent* InventoryDataWidgetComponent;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryDataWidgetDelaySeconds;
    
private:
    UPROPERTY(Instanced, Transient)
    UTWDInventoryDataWidget* InventoryDataWidget;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryDataRange;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryDataRangeDelta;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryAngleThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryAngleThresholdDelta;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryIdleVelocityTime;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryIdleVelocityThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    float InventoryIdleVelocityThresholdDelta;
    
    UPROPERTY(EditDefaultsOnly)
    FVector InventoryWidgetOffset;
    
    UPROPERTY(Transient)
    FTimerHandle InventoryDataWidgetDelayTimer;
    
    UPROPERTY(EditDefaultsOnly)
    float PauseWidgetOffsetZ;
    
    UPROPERTY(Transient)
    ASDIInventoryActor* EquippedHandWeapon;
    
public:
    ATWDPlayerHand(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintPure)
    bool WouldGripInventorySlot(ASDIInventorySlot*& OutSlot) const;
    
    UFUNCTION(BlueprintCallable)
    void StopSimulatingMovement();
    
    UFUNCTION(BlueprintCallable)
    void StopSimulatingIKThrow();
    
    UFUNCTION(BlueprintCallable)
    bool SimulateMovementVelocity(TArray<FTransform>& RelativePath, float Velocity, bool bInterrupt, bool bAddCurrentTransformAsStart);
    
    UFUNCTION(BlueprintCallable)
    bool SimulateMovementDuration(TArray<FTransform>& RelativePath, float Duration, bool bInterrupt, bool bAddCurrentTransformAsStart);
    
    UFUNCTION(BlueprintCallable)
    void SimulateIKThrow(const FVector& ThrowVel, bool bInterrupt);
    
    UFUNCTION(BlueprintCallable)
    void SetStabCooldown(float Time);
    
    UFUNCTION(BlueprintImplementableEvent)
    void SetPauseWidgetComponentProgress(float Progress);
    
    UFUNCTION(BlueprintCallable)
    void SetHandHidden(bool bHide);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStaminaActionFailed();
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStaminaActionEnded();
    
protected:
    UFUNCTION()
    void OnPhysicalHandMeshHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void OnHeldActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnApplyGameUserSettings();
    
    UFUNCTION(BlueprintNativeEvent)
    void OnApplyCheatModes();
    
    UFUNCTION(BlueprintPure)
    bool IsSimulatingMovement() const;
    
    UFUNCTION(BlueprintPure)
    bool IsSimulatingIKThrow() const;
    
    UFUNCTION(BlueprintPure)
    float GetGrappledStabCooldown() const;
    
    UFUNCTION(BlueprintPure)
    ASDIInventoryActor* GetEquippedHandWeapon() const;
    
    UFUNCTION(BlueprintPure)
    float GetDismemberStabCooldown() const;
    
    UFUNCTION(BlueprintPure)
    bool CanStab() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

