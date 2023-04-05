#pragma once
#include "CoreMinimal.h"
#include "SDISDIActiveRagdollComponentRagdollActivatedSignatureDelegate.h"
#include "SDILatePhysicalAnimationComponent.h"
#include "Engine/EngineTypes.h"
#include "SDISDIActiveRagdollComponentRagdollDeactivatedSignatureDelegate.h"
#include "Engine/EngineTypes.h"
#include "PhysicsEngine/PhysicalAnimationComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDIActiveRagdollComponent.generated.h"

class AActor;
class UPhysicsAsset;
class UPrimitiveComponent;
class USDIActiveRagdollComponent;

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIActiveRagdollComponent : public USDILatePhysicalAnimationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference MeshComponentRef;
    
    UPROPERTY(EditAnywhere)
    TMap<FName, bool> BoneChainMap;
    
    UPROPERTY(EditAnywhere)
    TMap<FName, bool> ActiveBoneOverrideMap;
    
    UPROPERTY(EditAnywhere)
    FName ConstraintProfile;
    
    UPROPERTY(EditAnywhere)
    FName PhysicalAnimationDataProfile;
    
    UPROPERTY(EditAnywhere)
    FPhysicalAnimationData OverridePhysicalAnimationData;
    
    UPROPERTY(EditAnywhere)
    bool bEnableGravity;
    
    UPROPERTY(EditAnywhere)
    float BlendInSpeed;
    
    UPROPERTY(EditAnywhere)
    float BlendOutSpeed;
    
    UPROPERTY(EditAnywhere)
    bool bEngageOnCollision;
    
    UPROPERTY(EditAnywhere)
    float CollisionActiveDuration;
    
    UPROPERTY(EditAnywhere)
    bool bHackRecreatePhysicsStateOnCollision;
    
    UPROPERTY(Transient)
    FName RootBoneName;
    
    UPROPERTY(Transient)
    float DefaultStrengthMultiplyer;
    
    UPROPERTY(Transient)
    float ActiveTimer;
    
    UPROPERTY(Transient)
    int32 ToggledOnCount;
    
    UPROPERTY(Transient)
    bool bNotifyToggledOn;
    
    UPROPERTY(Transient)
    bool bBlendWeightInterpolating;
    
    UPROPERTY(Transient)
    bool bRagdollActive;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<UPhysicsAsset> CachedPhysicsAsset;
    
    UPROPERTY(Transient)
    TArray<int16> InstanceBoneIndices;
    
    UPROPERTY(Transient)
    TArray<int16> ActiveInstanceBoneIndices;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<UPrimitiveComponent>, TEnumAsByte<ECollisionChannel>> IgnoredCollisionComponents;
    
protected:
    UPROPERTY(Transient)
    bool bInsideOnComponentHit;
    
    UPROPERTY(Transient)
    bool bInsideOnStitchedComponentHit;
    
    UPROPERTY(Transient)
    bool bInsideOnHeldActorComponentHit;
    
    UPROPERTY(Transient)
    bool bInsideOnAccessoryComponentHit;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDISDIActiveRagdollComponentRagdollActivatedSignature OnRagdollActivatedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDISDIActiveRagdollComponentRagdollDeactivatedSignature OnRagdollDeactivatedDelegate;
    
    USDIActiveRagdollComponent();
    UFUNCTION(BlueprintCallable)
    void UpdatePhysicsAsset();
    
    UFUNCTION(BlueprintCallable)
    void UnlockBone(UPARAM(Ref) int32& InOutId);
    
    UFUNCTION(BlueprintCallable)
    bool TurnOn(float Duration);
    
    UFUNCTION(BlueprintCallable)
    void TurnOff(bool bAllowBlendOut);
    
    UFUNCTION(BlueprintCallable)
    void ToggleOn();
    
    UFUNCTION(BlueprintCallable)
    void ToggleOff(bool bAllowBlendOut);
    
    UFUNCTION(BlueprintCallable)
    void SetBoneActiveOverride(FName BoneName, bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    bool RemovePhysicalAnimationDataProfile(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveConstraintProfile(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    int32 OverridePhysicalAnimationDataProfile(FName Profile);
    
    UFUNCTION(BlueprintCallable)
    int32 OverrideConstraintProfile(FName Profile);
    
    UFUNCTION()
    void OnStitchedComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void OnHeldActorComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void MeshOnPhysicsStateChange();
    
    UFUNCTION(BlueprintCallable)
    int32 LockHands(FName RelativeBone, bool bRotation, bool bLocation);
    
    UFUNCTION(BlueprintCallable)
    int32 LockBone(FName Bone, FName RelativeBone, bool bRotation, bool bLocation);
    
    UFUNCTION(BlueprintPure)
    bool K2IsOn(float& OutActiveTimeRemaining) const;
    
    UFUNCTION(BlueprintPure)
    bool IsValidBone(const FName& BoneName) const;
    
    UFUNCTION(BlueprintPure)
    bool IsToggledOn() const;
    
    UFUNCTION(BlueprintPure)
    bool IsForcedOn() const;
    
    UFUNCTION(BlueprintPure)
    bool IsBoneLocked(FName Bone) const;
    
    UFUNCTION(BlueprintPure)
    bool IsActiveBone(const FName& BoneName) const;
    
    UFUNCTION(BlueprintPure)
    float GetDefaultStrengthMultiplyer() const;
    
    UFUNCTION(BlueprintPure)
    static USDIActiveRagdollComponent* GetActiveRagdollComponentFor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void ClearBoneActiveOverrides(const TArray<FName>& BoneNames);
    
    UFUNCTION(BlueprintCallable)
    void ClearBoneActiveOverride(FName BoneName);
    
    UFUNCTION(BlueprintPure)
    bool ActiveRagdollAllowed() const;
    
};

